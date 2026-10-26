# Inverted Search

## Description
A menu-driven Inverted Search application developed in C to index words from multiple text files. It uses a hash table and linked lists to maintain word frequency and identify the files in which each word appears.

## Features
- Create a database from multiple text files.
- Track word frequency in each file.
- Search for a word and display its file locations and occurrence counts.
- Display the complete database.
- Update the database by adding new files.
- Save the database to a file.
- Validate input files and avoid duplicate file entries.

## Technologies Used
- **Programming Language:** C
- **Concepts:** Data Structures, Hashing, Singly Linked Lists, Pointers, File Handling, String Manipulation
- **Compiler:** GCC
- **Platform:** Linux

## Project Structure
- `main.c` – Main menu and program execution.
- `inverted_search.h` – Structure definitions, macros, and function declarations.
- `create_database.c` – Reads input files and creates the word database.
- `insert_at_last.c` – Inserts new word nodes.
- `search.c` – Searches for words in the database.
- `display_database.c` – Displays indexed words and their counts.
- `update_database.c` – Adds new files to the database.
- `save_database.c` – Saves database details to a file.
- `file_validation.c` – Validates input files and manages the file list.
- `update_database.c` – Updates the database with additional input files.

## Compilation
Run this command inside the project directory:

```bash
gcc main.c create_database.c display_database.c file_validation.c insert_at_last.c save_database.c search.c update_database.c -o inverted_search
```

## Execution
Pass one or more text files as command-line arguments:

```bash
./inverted_search file1.txt file2.txt
```

## Menu Options
1. Create Database
2. Display Database
3. Update Database
4. Search Database
5. Save Database
6. Exit

## Concepts Learned
- Hash table implementation using an array of linked-list heads.
- Word indexing and frequency counting.
- Singly linked lists and linked structures.
- File validation and file operations.
- Modular programming using multiple C source and header files.

## Author
Soundharya Lahari Uppula
