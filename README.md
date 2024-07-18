# File merger in C++
This C++ program merges the contents of all `.cpp` and `.h` files in the current directory into a single output file named `merged_files.txt`. Each file's content is prefixed with the file name for clarity. (For other extensions of files change in the code where it is commented.)

## Prerequisites

- C++ compiler supporting C++17 or later.
- Standard Library's `<filesystem>` support.

## Building the Program
Compile the code:
    ```
    g++ -std=c++17 -o textFromFiles textFromFiles.cpp
    ```

## Running the Program

To run the program:

```sh
./textFromFiles
```
