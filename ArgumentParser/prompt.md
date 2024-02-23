C++20 - Command-Line Argument Parser

# Overview

The goal of this code generation task is to develop a command-line argument parser using modern C++20.

This parser aims to simplify handling user input passed via the command line. The parser offers functionality similar to that found in the `boost::program_options` framework, but without the need for any external dependencies.

## Problem Statement

Command-line interfaces (CLIs) are crucial for many applications, providing a reliable and flexible way to pass user input to a program.

Generate code for a versatile, template-based command-line parsing system capable of handling `int`, `bool`, `std::string` and `float` types. This parser should allow for the specification of named options with default  values and the automatic generation of help messages, ensuring ease of use and integration into any C++ application.

## Requirements

1. **Supported Data Types**: Type parser must accommodate `int`, `bool`, `float`, and `std::string` types, leveraging `std::variant<>` for type-safe storage of argument values. It also supports arguments that have no value, such as `--help`.
1. **Named Arguments**: Support named options of the form `--option=value`. All arguments to the program are named. Not all arguments have a value.
1. **Default Values**: Enable the provision of default values for options.
1. **Help Messages**: Automatically generate a help message that details available options, their descriptions, and default values if any.
1. **Error Handling**: Incorporate robust error handling for scenarios such as unknown option names, missing values, malformed values, and type mismatches, providing clear and actionable feedback to the user. Errors should use exceptions.
1. **Help Option**: Explicitly add a `--help` option that takes no arguments.  This should write a help message  automatically created by the parser.
1. **Handling Multiple Entries**: The parser should fail with a useful error message if the same option is specified more than once.
1. **Comments**: Add comments to the code, focusing on the "why" and not the "what" or "how".
1. **C++20**: The generated code should only use modern C++20 libraries and best practices. Do not use any external libraries.


### Provided Framework for the CommandLineParser class

```cpp
class CommandLineParser {
public:
    typedef std::variant<int, bool, float, std::string> ArgumentValue;

    // add an option with a name, a description, and an optional default value
    void addOption(const std::string_view& name, const std::string_view description, std::optional<ArgumentValue> defaultValue = std::nullopt);

    // retrieve the value of the given named option
    template <typename T>
    T get(const std::string_view& name) const;

    // true if the user passsed the given option
    bool wasOptionProvided(const std::string& optionName) const;

    bool wasHelpRequested() const { return wasOptionProvided("help"); }

    // returns a help message detailing all available options
    std::string getHelpMessage() const;
};
```

### Provided `main` function driver code

```cpp
// TODO: include all required headers

// TODO: include defintion for the CommandLineParser class

int main(int argc, char **argv) {
    CommandLineParser parser;

    parser.addOption("port", "Specify the port number", 8080);
    parser.addOption("verbose", "Enable verbose logging", false);
    parser.addOption("timeout", "Set the timeout in seconds", 5.0f);
    parser.addOption("config", "Configuration file path", "default.cfg");

    try {
        parser.parse(argc, argv);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    if (parser.wasHelpRequested()) {
        std::cout << parser.getHelpMessage() << std::endl;
        return 0;
    }

    int port = parser.get<int>("port");
    int verbose = parser.get<bool>("verbosity");
    int timeout = parser.get<float>("timeout");
    int config = parser.get<std::string>("config");

    std::cout << "Using port: " << port << std::endl;
    std::cout << "Operation timeout: " << timeout << " seconds" << std::endl;
    std::cout << "Configuration file: " << config << std::endl;

    // application logic follows...

    return 0;
}
```

## Samples

The following shows correct and incorrect use of the application.

### Example passing new values for options

```bash
$ ./app --port=888 --timeout=10 --config=prod.cfg
Using Port: 888
Operation timeout: 10.0
Configuration file: prod.cfg
```

### Sample with malformed value

```bash
$ ./app --number="foobar"
Error: Invalid value provided for option --number: Expected an integer value
```

### Sample invocation of the Help message

```bash
$ ./app --help
--port: Specify the port number (default: 8080)
--verbose: Enable verbose logging (default: false)
--timeout: Set the timeout in seconds (default: 5.0)
--config: Configuration file path (default: default.cfg)
```

## Notes
* Consider using the `<regex>` library for parsing the command line.
* The `getHelpMessage` method of the CommandLineParser class should iterate over all options, generating a comprehensive help message.
* The parser's design should allow for easy extension and maintenance, facilitating the straightforward addition of new features and data types.
* Consider adding the type of the value in the help text.
* Boolean values are specified as `true` or `false` and not as string literals in double quotes such as `"true"`.



