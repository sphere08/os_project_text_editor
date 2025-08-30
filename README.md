# Minimalist Text Editor in C on Linux

## Overview

This program allows you to edit a specific line in a text file. It reads the file, displays its contents, counts the total number of lines, and then lets the user replace the content of a chosen line. The changes are saved back into the original file only. Remember it uses 0-based indexing for the indexing of lines in the content of test.txt.

## Features

- Display contents of a file.
- Count the total number of lines.
- Edit a specific line by providing its line number.
- Save changes directly to the original file.

## Usage

1. Compile the program and run it:
   ```bash
   gcc text_editor.c -o text_editor
   ./text_editor test.txt
   ```
