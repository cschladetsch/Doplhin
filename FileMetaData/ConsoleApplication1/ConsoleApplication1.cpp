#include <execution>
#include <filesystem>
#include <format>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

// Helper function to convert file size to human-readable format
std::string formatFileSize(std::uintmax_t size) {
    const char* units[] = {"B", "KB", "MB", "GB", "TB"};
    int i = 0;
    double dsize = static_cast<double>(size);
    while (dsize >= 1024 && i < sizeof(units) / sizeof(const char*)) {
        dsize /= 1024;
        ++i;
    }
    return std::format("{:.1f}{}", dsize, units[i]);
}

// Function to analyze files in a directory
void analyzeDirectory(const std::filesystem::path& path, bool recursive, const std::vector<std::string>& extensions) {
    try {
        // Create a map to store file extensions and their corresponding file information
        std::map<std::string, std::pair<int, std::uintmax_t>> fileData;

        // Iterate over files in the directory using a recursive directory iterator
        for (auto const& file : recursive ? std::filesystem::recursive_directory_iterator(path)
                                        : std::filesystem::directory_iterator(path)) {
            // Check if the file is a regular file
            if (file.is_regular_file()) {
                // Extract the file extension
                std::string extension = file.path().extension().string();

                // Check if the file extension is in the specified list of extensions
                if (extensions.empty() || std::ranges::find(extensions, extension) != extensions.end()) {
                    // Increment the count and add the file size to the file extension data
                    auto& [count, size] = fileData[extension];
                    ++count;
                    size += file.file_size();
                }
            }
        }

        // Print the file information for each extension
        for (const auto& [extension, data] : fileData) {
            auto [count, size] = data;
            std::cout << std::format("{} files:\n", extension)
                      << std::format("- count: {}\n", count)
                      << std::format("- size: {}\n", formatFileSize(size));
        }
    } catch (const std::exception& ex) {
        // Handle exceptions and add contextual information before rethrowing
        throw std::runtime_error(std::format("Error analyzing directory {}: {}", path.string(), ex.what()));
    }
}

int main(int argc, char* argv[]) {
    // Parse command-line arguments
    std::string path;
    bool recursive = false;
    std::vector<std::string> extensions;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--path") {
            if (++i < argc) {
                path = argv[i];
            } else {
                std::cerr << "Error: Missing path argument.\n";
                return 1;
            }
        } else if (arg == "--recursive") {
            recursive = true;
        } else if (arg == "--ext") {
            if (++i < argc) {
                std::string ext = argv[i];
                std::ranges::for_each(ext | std::views::split(','), [&extensions](auto const& e) { extensions.push_back(e.to_string()); });
            } else {
                std::cerr << "Error: Missing file extensions argument.\n";
                return 1;
            }
        } else {
            std::cerr << "Error: Invalid argument: " << arg << "\n";
            return 1;
        }
    }

    // Validate path argument
    if (path.empty()) {
        std::cerr << "Error: Path argument is required.\n";
        return 1;
    }

    // Analyze files in the specified directory
    try {
        analyzeDirectory(path, recursive, extensions);
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << "\n";
        return 1;
    }

    return 0;
}
