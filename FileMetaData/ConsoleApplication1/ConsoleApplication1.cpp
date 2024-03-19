#include <execution>
#include <filesystem>
#include <format>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

// Custom exception class for handling errors
class FileMetadataError : public std::exception {
public:
    FileMetadataError(const std::string& message) : m_message(message) {}
    const char* what() const noexcept override { return m_message.c_str(); }

private:
    std::string m_message;
};

// Helper function to convert file size to a readable format
std::string format_file_size(std::uintmax_t size) {
    const char* units[] = {"KB", "MB", "GB"};
    int i = 0;
    double dsize = static_cast<double>(size);
    while (dsize >= 1024 && i < 3) {
        dsize /= 1024;
        i++;
    }
    return std::format("{:.2f}{}", dsize, units[i]);
}

// Function to process a directory and extract file metadata
void process_directory(const std::filesystem::path& path, bool recursive, const std::vector<std::string>& extensions) {
    try {
        // Create a generator for iterating over the directory
        auto directory_iterator = recursive ? std::filesystem::recursive_directory_iterator(path)
                                            : std::filesystem::directory_iterator(path);

        // Group files by their extensions using ranges
        auto grouped_files = directory_iterator
                             | std::views::filter([](const auto& entry) { return entry.is_regular_file(); })
                             | std::views::transform([](const auto& entry) { return entry.path().extension().string(); })
                             | std::ranges::views::group_by(std::ranges::equal_to{});

        // Filter the grouped files based on the specified extensions
        auto filtered_files = grouped_files
                              | std::views::filter([&extensions](const auto& group) {
                                  return std::ranges::any_of(extensions, [&group](const auto& ext) { return group.key() == ext; });
                              });

        // Calculate the count and total size for each file extension
        for (const auto& [extension, files] : filtered_files) {
            std::uintmax_t total_size = 0;
            int count = 0;
            for (const auto& file : files) {
                total_size += std::filesystem::file_size(file);
                count++;
            }

            // Print the file metadata
            std::cout << extension << " files:\n";
            std::cout << "- count: " << count << "\n";
            std::cout << "- size: " << format_file_size(total_size) << "\n";
        }
    } catch (const std::filesystem::filesystem_error& e) {
        throw FileMetadataError(std::format("Error accessing directory {}: {}", path, e.what()));
    }
}

int main(int argc, char* argv[]) {
    try {
        // Parse command line arguments
        std::string path;
        bool recursive = false;
        std::vector<std::string> extensions;

        for (int i = 1; i < argc; i++) {
            if (std::string(argv[i]) == "--path") {
                if (i + 1 < argc) {
                    path = argv[++i];
                }
                else {
                    throw FileMetadataError("Missing path argument");
                }
            }
            else if (std::string(argv[i]) == "--recursive") {
                recursive = true;
            }
            else if (std::string(argv[i]) == "--ext") {
                if (i + 1 < argc) {
                    std::string ext_list = argv[++i];
                    std::ranges::for_each(ext_list | std::views::split(','), [&extensions](const auto& ext) { extensions.push_back(ext); });
                }
                else {
                    throw FileMetadataError("Missing extension list argument");
                }
            }
        }

        // Validate path argument
        if (path.empty()) {
            throw FileMetadataError("Path argument is required");
        }

        // Process the directory and extract file metadata
        process_directory(path, recursive, extensions);

        return 0;
    }
}
