# C++20 - 1D Minesweeper Game

I require the design and development of a one-dimensional version of [Minesweeper](https://en.wikipedia.org/wiki/Minesweeper_(video_game)). 

The objective is to create a command-line based game that presents players with the challenge of clearing a linear minefield without detonating and hidden mines.

The implementation will use C++20 to ensure modern programming practices are applied.

## Problem Statement

The essence of the original **Minesweeper** game is to test a players' deductive reasoning and strategic thinking in a two-dimensional grid. The challenge with this project is to transpose the Minesweeper mechanics onto a one-dimensional game space.

The simplified interface aims to maintain the essence of strategic depth and engagement of the original 2D game, requiring players to use logic and strategy to navigate through the minefield safely.

## Requirements

1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
1. **Only Use Single Line IO**: No ASCII art.

### Gameplay Mechanics

1. **Initialisation**: At the start, the game prompts for the length of the minefield and the number of hidden mines.
1. **Board Representation**: A dynamic one-dimensional array represents the game board as known by the player, with cells possibly containing mines.
1. **Mine Distribution**: Mines are randomly placed across the line a the start of the game.
1. **Player Interaction**: Players input a cell index as a non-negative integer each turn to reveal its contents. Doing so could have two outcomes:
 * A number indicating the number of adjacent mines.
 * A mine, which ends the game.
1. **Victory Condition**: The game is won by revealing all non-mine cells.

### User Interface

1. **Display**: The board is shown as a series of characters unrevealed cells `.`m revealed mines `*` and numbers for adjacent mines.
1. **Inputs**: The game prompts the user for input. Trap and report errors in all input by providing feedback. Invalid input does not change the game state, and it also does not halt the game.

## Examples

Winning game:

```bash
$ ./minesweeper
Length of minefield: 10
Number of mines: 3
Board: . . . . . . . . . .
Cell [0..9]?: 5
Board: . . 1 1 1 . . . . . 
Cell [0..9]?: 2
Board: 1 1 1 1 1 . . . . .
Cell [0..9]?: 9
You win!
```

Losing game:

```bash
Cell [0..9: 7
Board: 1 1 1 1 1 1 2 * 1 1
Boom! You lost.
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.
