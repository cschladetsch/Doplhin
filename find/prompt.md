# Problem Statement

Use C++20 code to implement a simpllified `find` command.

The find command searches for filenames that match a given regex, given a starting folder and a regex o match for filenames. This is applied recursively.

* Example

``bash
$ ./find . "*foo*
folder/foo.txt
other/foobar.txt
```

## Requirements

1. Use C++20 language. Do not use any external libraries.
1. There is no need to suport other options other than
1. The first argument to the program is the starting folder (directory) to search from.
1. The second argument is a [regex](https://en.wikipedia.org/wiki/Regular_expression) that provides a pattern to match for filenames.

## Samples

Given a file structure:

```
.
./foo/barstool
./spam/grok/foobar
./spam/grok/luke
```

And the command:

```
$ ./find . "bar*|foo*"
```

The output would be:

```
./foo/barstool
./spam/grok/foobar
```


