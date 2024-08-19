# CA-internship

Task 1: GPA calculator

In this C++ code, I created a command-line tool for calculating Semester Grade Point Average (SGPA) and Cumulative Grade Point Average (CGPA). I implemented functionality to prompt users for the number of subjects or semesters and their respective credit hours, points, or GPAs. I used basic arrays to store these inputs and performed arithmetic operations to compute and display the SGPA and CGPA. The code features a menu-driven interface to guide users through the calculations. However, I noted that the code could benefit from improvements in dynamic array handling and input validation to enhance its robustness.



Task 2: Lofin and regestration system

In this code, I’ve created a simple login and registration system in C++ with basic file handling and password management. I start by defining a menu function to present options for registration, login, or exiting the system. For password generation, I used `strong_pass` to create a secure password, and `hash_password` applies a basic Caesar cipher to hash passwords before saving them. The `username_exists` function checks if a username is already taken by reading from a file. During registration, I either suggest a strong password or let the user enter one. The login function verifies credentials by comparing the hashed password from the file with the user's input. Finally, in the `main` function, I run a loop to handle user choices and perform the corresponding actions until the user decides to exit.



Task 3: Suduko solver

In this code, I developed a Sudoku solver using the backtracking approach. I start by defining a 9x9 board and then use `printBoard` to display the board once solved. The `isValid` function helps me check if a number can be placed in a cell without breaking Sudoku rules. In `solveSudoku`, I recursively try different numbers in empty cells until I find a solution or determine that no solution exists. Finally, in `main`, I initialize a Sudoku puzzle and use these functions to solve it, printing the solved board or a message if no solution is found.

