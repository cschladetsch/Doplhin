# C++20 - Convert UTC Time to Local Time

## Problem Statement

There is abundant confusion about how to deal with date-time stamps.

The generated program allows for conversion of a datetime from Coordinated Universal Time (UTC) to its corresponding local time. The input can in either UTC FORMAT or in a human-readable format.

The output is always formal [UTC](https://en.wikipedia.org/wiki/Coordinated_Universal_Time).

## Requirements

1. **Input**: The input is passed on the command line as a quoted string.
1. **Output**: The program will display the corresponding local time in common UTC format.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.

## Instructions

* Enter the datetime in either UTC or a more human-readable form.
 * UTC Format: "YYYY-MM-DDTHH:MM:SSZ". For example, "2024-03-05-T15:40:00Z".
 * Human Readable Format: `Month Day Year at Time Zone`. For example "March 7th, 2024 at 10:30am EST"
  * Date components are separated by whitespace or punctuation.
  * Month represented by full name (e.g. "March")
  * Date represented by ordinal number number followed by "st", "nd", "rd", "th". For example `7th`
  * Year represented by a 4-digit number.
  * Time represented using 12-hr clock time followed by 'AM' or 'PM'.
  * Time zone specified after the time component and separated by whitespace. For example: "EST" or "PST" or "AEST".
  * The program will correctly deal with daylight savings based on local time zone.

## Sample Usage

```bash
$ ./convert_utc_to_local "2024-03-07T17:30:00Z"
2024-03-07T10:30:00-5:00 (Eastern Standard Time)
$ ./convert_utc_to_local "March 7th, 2024 at 10:30AM EST"
2024-03-07T10:30:00-0500 (Eastern Standard Time)
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.

