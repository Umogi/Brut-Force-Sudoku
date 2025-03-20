# Brute-Force Sudoku Solver

## Description
This program is a brute-force Sudoku solver written in C. It iterates through possible number placements systematically to solve a given Sudoku puzzle. The algorithm uses backtracking to correct errors and ensure a valid solution.

## Features
- Solves a 9x9 Sudoku puzzle using brute-force.
- Utilizes backtracking to find the correct solution.
- Displays the Sudoku board dynamically as it solves the puzzle.
- Highlights original numbers in a different color (requires Windows).

## Prerequisites
- A C compiler (e.g., GCC, MSVC)
- Windows OS (for color functionality using `SetConsoleTextAttribute`)

## Compilation & Execution
1. Compile the program using a C compiler:
   ```sh
   gcc sudoku_solver.c -o sudoku_solver
   ```
   (Ensure you have a compatible compiler installed.)

2. Run the executable:
   ```sh
   ./sudoku_solver
   ```
   (On Windows, you may need to use `sudoku_solver.exe`.)

## How It Works
1. Reads a predefined 9x9 Sudoku grid.
2. Iterates through empty cells and fills them with values from 1 to 9.
3. Validates each placement using three conditions:
   - No duplicate numbers in the row.
   - No duplicate numbers in the column.
   - No duplicate numbers in the 3x3 sub-grid.
4. If a placement is invalid, it backtracks to the previous step and tries the next possible value.
5. Continues this process until the puzzle is solved.
6. Prints the solved Sudoku board.

## Functions
- `setColor(int color)`: Changes the console text color (Windows-only feature).
- `printSudoku(int array[SIZE][SIZE])`: Prints the Sudoku board dynamically.
- `horizontal(int x, int sudoku[SIZE][SIZE])`: Checks if a row contains duplicates.
- `vertical(int y, int sudoku[SIZE][SIZE])`: Checks if a column contains duplicates.
- `square(int x, int y, int sudoku[SIZE][SIZE])`: Checks if a 3x3 sub-grid contains duplicates.

## Notes
- The initial Sudoku puzzle is hardcoded into the `sudokuOriginal` array.
- The solver may not work efficiently for extremely difficult puzzles but guarantees a solution for valid inputs.
- The program clears the console before each print update (`system("cls")`), which may need modification for non-Windows systems.

## License
This project is open-source. Feel free to modify and distribute it [LICENSE](LICENSE).
