# C++20 - Meal Planner

Many people wish to limit their daily caloric intake, but find it difficult to do so for various reasons. These include keeping track of calories and als oensuring the diet is not monotonous.

## Problem Statement

Generate a C++20-conformant program that generates a weekly meal plan. Including _breakfast_, _lunch_, _dinner_ and _dessert_ categoris. The data for the food stuffs is provided by a data file in CSV (Comma Separated Value) file. The generated program aims to ensure a balanced and varied intake of meals while meeting a specific daily caloric target.

The challenge is to generate a command-line tool that generates a meal plan, including all meal categories (breakfast, lunch, dinner, dessert), from a dataset provided by a CSV file. This program aims to ensure a balanced and varied intake of meals while meeting a specified dailing caloric intake.

Create a tool that automates the construction of a nutrituous and varied weekly meal plan. The must algorithmically select from a dataset of food items - eeach with specified caloric values and meal designations - to adhere to dietary constraints. The result is a user-friedly summary of the meal plan for a full week (Monday to Sunday). The user supplies the name of the file to read food/meal information from, as well as caloric content. These are detailed further below.

## Requirements

1. **Modular Design**: With distinc requirements for CSV parsing, meal planning, and output formatting.
1. **Emphasis Readability**: And maintainability with clear coding practises and inline documentation.
1. **Smart Pointers**: For efficient and safe memory management, `std::ranges` for data manipulation, and througoiu error handling.
1. **Recognise Large Datasets**: Support use-cases where there could be many thousands of meals to select from. Also, remember than a given meal can be used at different MealTimes (Breakfast, Lunch, Dinner, Dessert).
1. **Ignore Snacks**: This is outside the scope of the problem.
1. **Efficiently parse Input file**: Ensure data integretry. Catch any errors, add context, and re-throw.
1. **Algoirithm**: Create an algorithm that meets the requirements: varied diet that is approximate to the given caloric intake per day.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.

## Provided Framework

```cpp
class MealPlanner {
    enum class MealType {
        Breakfast,
        Lunch,
        Dinner,
        Dessert
    };

    struct Meal {
        MealType type;
        int Calories;
        std::string Description;
    };

    // etc...
};

```

### Input File Specification

1. Format: The inpiut must be provided in CSV (Comma-Separated Values) format.
1. Fiels: Each row in the CSV file represents a food item and must contain the following fields:
 * Name: The name of the food item, enclosed in double quotes `"`.
 * Calories: The caloric value of the food item, as an integer.
 * Meal Type: This is a trailing, variable-length, comma-separated list of symbols to specify when the food should be consumed. The keywords available are:
  * "breakfast", "lunch", "dinner", and "dessert". (without the quotes).
1. Field Order: The fields must appear in the specified order: Name, Calories, Meal Type(s)
1. Data Integrity.
1. No Header. 
1. Quoted Strings.
1. No Comments.

## Example

```bash
$ cat data.csv
"Avocado Toast",200,breakfast
"Chicken Caesar Salad",350,lunch
"Pan-Seared Salmon",400,dinner
"Brown Rice",215,lunch,dinner
"Greek Yogurt",100,breakfast
"Berry Smoothie",180,breakfast
"Beef Stir-Fry",475,dinner
"Mixed Nuts",170,snack
"Chocolate Mousse",300,dessert
"Caprese Salad",150,lunch
"Chia Seed Pudding",250,breakfast
"Quinoa Salad",320,lunch
"Vegetable Lasagna",410,dinner
"Garlic Bread",180,dinner
"Apple Cinnamon Oatmeal",220,breakfast
"Veggie Burger",350,lunch
"Stuffed Bell Peppers",375,dinner
"Carrot Cake",390,dessert
"Tomato Soup",150,lunch

$ ./mealplanner data.csv 2000

Weekly Meal Plan (Target: 2000 Calories/day)

Monday
- Breakfast: Greekyogurt (100 calories), Berry Smoothie (180 calories)
- Lunch: Chicken Caeser Salad (350 calories), Brown Rice (512 calories)
- Dinner: Pan-Seared Salmon (400 calories), Garlic Bread (180 calories)
- Desset: Chocolate Mousse (300) 
Total Calories for Monday: 1625

Tuesday
- Breakfast: Avocado Toast (200), Fruit Salad (150) calories    
- Lunch: Quinoa Salad (320 calories), Mixed Nuts (150) calories 

[...etc...]

Weekly Summary:
- Total calories : 124556
- Average Daily calories: 1909
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.


