# pipex

## Table of contents

- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Testing](#testing)

## Introduction

**pipex** is a project from the 42 school curriculum that aims to replicate the behavior of the shell pipeline. 
The project involves creating a program that can redirect the output of one command to the input of another, 
similar to the shell pipe (|).

## Features

- Execute two commands in a sequence with input/output redirection.
- Mimics the functionality of the shell pipe (|).

## Requirements

- Operating System: Unix-like OS (Linux, macOS).
- Compiler: GCC or Clang.
- Make: Utility to manage the build process.

## Installation

1. Clone the repository:
```bash
git clone https://github.com/mariusz-smajdor/pipex.git && cd pipex
```

2. Compile the project
```bash
make
```

## Usage

To execute pipex, run the following command:
```bash
./pipex file1 cmd1 cmd2 file2
```

- file1: The input file.
- cmd1: The first command to execute.
- cmd2: The second command to execute.
- file2: The output file.

**pipex** will redirect the contents of **file1** to **cmd1**, then pipe the output of **cmd1** to **cmd2**, and finally save the result to **file2**.

## Examples

### Basic Example

```bash
./pipex infile "cat -e" "grep hello" outfile
```

This command will take **infile**, pass its content to **cat -e**, pipe the output to **grep hello**, and save the final output to **outfile**.

### Error Handling

If any part of the command fails (e.g., if **cmd1** or **cmd2** is not found), **pipex** will display an appropriate error message.

## Testing

To test the project, you can use a variety of input files and commands to ensure it behaves as expected. Compare the output of pipex with the shell equivalent to verify correctness.

Example test case:
```bash
./pipex infile "ls -l" "wc -l" outfile
```

Verify with:
```bash
< infile ls -l | wc -l > outfile
```
