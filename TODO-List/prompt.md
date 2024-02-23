# C++20 - Create a Simple TODO list Application

## Problem Statement

Generate code for a simple TODO list console application using C++20. The application enables users to add, view, mark as complete, and remove tasks.

The application should provide a simple Command-Line Interface (CLI) to manage the task list. It will also ensure that task data is persistent and uses a simple human-readable and editable text-file based format. 

## Requirements

1. **Cross-platform compatibility**: Ensure that the program works across common operating systems such as Windows, macOS and Linux.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
1. Tasks can have two states:
 * Complete.
 * Incomplete.

### Command Line Interface

The following commands must be supported:

1. Add Task.
 * Syntax: `todo add "<task description>"`
 * Description: Add a new task with the provided description to the TODO list. 
  * The task description must be surrounded by double-quotes `"`. 
  * Every new task has a task number that is monotonically greater than any previous task. Specifically, if task number 3 is deleted, a new task would has task number 4 associated with it.
1. View Tasks. 
 * Syntax: `todo list`
 * Description: Display all tasks currently on the TODO list, including tasks marked as 'Completed'. 
1. Mark as Completed.
 * Syntax: `todo complete <task_number>`.
 * Description: Marks the task with the specified task number as being completed.
1. Remove Task.
 * Syntax: `todo remove <task_number>`
 * Description: Removes the task with the specified task number from the TODO list.

### Persistent Storage

 * Text File. Task data is stored in a simple text file to ensure persistence between different runs of the application. This text file is human- and machine-readable. The user can manually edit this file. Each line in the text file represents a different task. It has the following format:
   * `<task_number>,<task_status>,<task_description>`
   * **task_number**: A unique numeric integral identifier, starting from 1, and incrementing sequentially.
   * **task_status**: One of 'complete' or 'incomplete'.
   * **task_description**: This field is wrapped in double quotes `"`. If double quotes are given in the task description, they are replaced by single quotes `'` before storage.

#### Example of persistent storage

```
1,incomplete,"Finish project report"
2,complete,"Buy groceries"
3,incomplete,"Call John"
```

## Examples

```bash
$ todo add "Finish project report"
$ todo list
1. [ ] Finish project report
$ todo complete 1
1. [x] Finish project report
$ todo add "Buy groceries"
$ todo list
1. [x] Finish project report
2. [ ] Buy groceries
$ todo add "Call John"
$ todo list
1. [x] Finish project report
2. [ ] Buy groceries
3. [ ] Call John
$ todo remove 2
$ todo list
1. [x] Finish project report
3. [ ] Call John
$ todo delete 4
Error: Task number 4 does not exist
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.
* Assume the persistent storage is globally available, for instance in the file `~/.todo-list.txt`


