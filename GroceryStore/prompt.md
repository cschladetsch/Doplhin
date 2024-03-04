# C++20 - Grovery Store Inventory System

## Introduction

Efficient inventory mana genet is crucial for grocery (and other!) stores. The code generation task requirements the creation of a user-friendly, command-line inventory management system written in modern C++20 to streamline some basic inventory control tasks.

## Requirements

1. **Product Representation**. Define a `Product` class or struct to encapsulate product information:
 * `name` (string): Name of the product
 * `quantity` (int): The number of items in stock.
 * `pricePerUnit` (double): Price of a single unit of the product.
1. **Inventory**: Define an `Inventory` class that can be used to manipulate the inventory. This includes supporting adding new items, getting the quantity a given item in stock, and calculating the  total stock value.
1. **Command-Line Interface**: Add the following commands:
 * `--add-product`: Prompts the user to add add a new product type, including name, price, and quantity.
 * `--update-quantity`: Update the count of the product in stock.
 * `--total-value`: Calculates and displays the total value of the entire inventory.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
1. **Data Persistence**:
 * Assume a local file called "inventory.csv" that is used as the data storage for the inventory.
 * Do not provide headers in the CSV  file.
 * Example: The first column is the name of the product surrounded by double quotes. The second item is the price-per-unit. The final column is the number of items in stock. For Example:
 ```
 "Apple",0.5,50
 "Tomato",1.1,20
 ```

## Sample

```bash
$ cat inventory.csv
"Apple",0.5,50
"Tomato",1.1,20
$ ./inventory --add-product
Name: Pineapple
Cost: 2.2
Count: 10
$ ./inventory --total-value
69
$ ./inventory --update-quantity
Name: Apple
New Quantity: 0
$ ./inventory --total-value
44
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.
