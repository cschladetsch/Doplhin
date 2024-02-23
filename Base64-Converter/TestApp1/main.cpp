#include <algorithm>
#include <bit>
#include <bitset>
#include <cassert>
#include <cctype>
#include <concepts>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <optional>
#include <ranges>
#include <source_location>
#include <span>
#include <stdint.h>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

static constexpr std::string_view const kBase64EncodingTable{
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};
static constexpr std::array<int, 256> const kBase64DecodingTable{{
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 62, -1, -1, -1, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60,
    61, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1, -1,
    26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
    45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1}};

class Base64Converter {
 public:
  Base64Converter(std::string_view input_filename, std::string_view output_filename,
              ConversionMode conversion_mode)
      : input_filename_(input_filename),
        output_filename_(output_filename),
        conversion_mode_(conversion_mode) {
    try {
      input_file_.open(input_filename_, std::ios::binary);
      if (!input_file_.is_open()) {
        throw std::runtime_error("Unable to open input file: " +
                                 std::string(input_filename_));
      }

      output_file_.open(output_filename_, std::ios::binary);
      if (!output_file_.is_open()) {
        throw std::runtime_error("Unable to open output file: " +
                                 std::string(output_filename_));
      }
    } catch (std::exception const& e) {
      std::throw_with_nested(std::runtime_error("Base64Converter constructor failed: " +
                                            std::string(e.what())),
                             e, std::source_location::current());
    }
  }

  void Convert() {
    try {
      if (conversion_mode_ == ConversionMode::kEncode) {
        Encode();
      } else {
        Decode();
      }
    } catch (std::exception const& e) {
      std::throw_with_nested(
          std::runtime_error("Base64Converter::Convert() failed: " +
                             std::string(e.what())),
          e, std::source_location::current());
    }
  }

 private:
  enum class ConversionMode { kEncode, kDecode };

  void Encode() {
    std::array<std::uint8_t, 3> input_buffer{};
    std::array<std::uint8_t, 4> output_buffer{};
    std::size_t bytes_read;

    while ((bytes_read = input_file_.read(reinterpret_cast<char*>(input_buffer.data()),
                                       input_buffer.size())
                                    .gcount()) > 0) {
      std::span<std::uint8_t, 4> encoded{output_buffer};

      std::ranges::transform(input_buffer | std::views::take(bytes_read), encoded,
                         [](std::uint8_t byte) {
                           return kBase64EncodingTable[(byte >> 2) & 0x3F];
                         });

      encoded[3] = '=';

      switch (bytes_read) {
        case 1:
          encoded[2] = '=';
          break;
        case 2:
          encoded[3] = (input_buffer[1] & 0x0F) << 4;
          break;
        default:
          break;
      }

      output_file_.write(reinterpret_cast<char*>(output_buffer.data()),
                      output_buffer.size());
    }
  }

  void Decode() {
    std::array<char, 4> input_buffer{};
    std::array<int, 4> decoded_values{};
    std::array<std::uint8_t, 3> output_buffer{};

    while (input_file_.getline(input_buffer.data(), input_buffer.size() + 1)) {
      std::span<char, 4> input{input_buffer};
      std::span<int, 4> decoded{decoded_values};

      std::ranges::transform(input, decoded, [](char c) {
        if (std::isspace(c)) {
          return -1;
        }

        auto const it = std::find(kBase64EncodingTable.begin(), kBase64EncodingTable.end(), c);
        if (it == kBase64EncodingTable.end()) {
          throw std::invalid_argument("Invalid base64 character found: '" +
                                      std::string{c} + "' at offset " +
                                      std::to_string(input_file_.gcount()) +
                                      "\n");
        }

        return std::distance(kBase64EncodingTable.begin(), it);
      });

      if (decoded[3] == -1) {
        break;
      }

      std::span<std::uint8_t, 3> decoded_output{output_buffer};
      decoded_output[0] = (decoded[0] << 2) | (decoded[1] >> 4);

      if (decoded[2] != -1) {
        decoded_output[1] = (decoded[1] << 4) | (decoded[2] >> 2);

        if (decoded[3] != -1) {
          decoded_output[2] = (decoded[2] << 6) | decoded[3];
        }
      }

      output_file_.write(reinterpret_cast<char*>(output_buffer.data()),
                      output_buffer.size() - static_cast<std::size_t>(decoded[3] == -1) -
                          static_cast<std::size_t>(decoded[2] == -1));
    }
  }

  std::string_view input_filename_;
  std::string_view output_filename_;
  ConversionMode conversion_mode_;

  std::ifstream input_file_;
  std::ofstream output_file_;
};

void HandleError(std::string const& message) {
  std::cerr << message << std::endl;
  std::exit(EXIT_FAILURE);
}

enum class ConversionMode { kEncode, kDecode };

template <typename Derived,
          typename = std::void_t< decltype(std::declval<Derived>().ParseCommandLine())>>
struct CommandLineInterface {
  static constexpr std::string_view const kProgramName{
      "/path/to/base64-converter"};

  void ParseCommandLine() {
    if (argc_ == 1) {
      HandleError("Usage: " + std::string(kProgramName) +
                  " input.bin output.txt [encode|decode]");
    }

    input_filename_ = argv_[1];
    output_filename_ = argv_[2];

    if (argc_ > 3) {
      conversion_mode_ = ParseConversionMode(argv_[3]);
    } else {
      conversion_mode_ = ConversionMode::kEncode;
    }
  }

  ConversionMode const& conversion_mode() const { return conversion_mode_; }
  std::string_view const& input_filename() const { return input_filename_; }
  std::string_view const& output_filename() const { return output_filename_; }

 private:
  static ConversionMode ParseConversionMode(std::string_view const& conversion_mode) {
    if (conversion_mode == "encode") {
      return ConversionMode::kEncode;
    } else if (conversion_mode == "decode") {
      return ConversionMode::kDecode;
    } else {
      HandleError("Invalid command line argument: " + std::string(conversion_mode) +
                  "\nExpected: [encode|decode]");
    }
  }

  int argc_;
  char const* const* argv_;
  std::string input_filename_;
  std::string output_filename_;
  ConversionMode conversion_mode_;
};

class Base64ConverterCommandLineInterface
    : public CommandLineInterface<Base64ConverterCommandLineInterface> {
 public:
  Base64ConverterCommandLineInterface(int argc, char const* const* argv)
      : CommandLineInterface{argc, argv} {
    this->ParseCommandLine();
  }
};

int main(int argc, char const* const* argv) {
  try {
    Base64ConverterCommandLineInterface cli(argc, argv);
    Base64Converter converter(cli.input_filename(), cli.output_filename(),
                          cli.conversion_mode());
    converter.Convert();
  } catch (std::exception const& e) {
    HandleError("Error: " + std::string(e.what()));
  }

  return EXIT_SUCCESS;
}
