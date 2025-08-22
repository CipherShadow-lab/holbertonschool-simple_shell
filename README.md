![Unleash the shell within](Documents/Holberton-Shell-Banner_v3.png)

# Simple Shell Project
A basic Unix command-line interpreter built in C that replicates key features of the standard shell.

### 📖 Project Description
This project is a simple Unix shell implemented in the C programming language. It replicates a subset of common shell behaviours such as executing programs, handling environment variables and responding to user input.

The project demonstrates key low-level programming concepts, such as:

- Process creation with fork()
- Program execution using execve()
- Waiting for child processes with wait(); and
- Accessing and modifying environment variables

### ⚙️ Key Features
- Implemented built-ins including exit and env
- Handling of commands with arguments
- PATH handling to verify if a command exists

### 🛠️ Installing and Running the Project

```bash
# 1. Clone the repository
git clone https://github.com/CipherShadow-lab/holbertonschool-simple_shell.git
cd holbertonschool-simple_shell

# 2. Compile the shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# 3. Run the shell
./hsh
```

### 📐 Design Principles
- Modular functions for handling input, parsing, environment management and execution
- Memory-safe practices using malloc and free
- Follows Unix philosophy: "Simple, Composable and Efficient"

### 😤 Challenges Faced
- Handling memory management carefully (no leaks!)
- Managing the environment safely
- Parsing user input into valid command and arguments
- Handling errors and signals cleanly

### 📂 Repository Files

- `main.c` – Entry point of the shell
- `handler.c` – Handles input and dispatches commands
- `parser.c` – Tokenises user input
- `executor.c` – Forks and executes commands
- `path.c` – Resolves command paths
- `builtins.c` – Contains built-in commands
- `_string.c` – Custom string helper functions
- `shell.h` – Header file with all declarations
- `README.md` – Project documentation
  
### 👩🏽‍💻👩🏽‍💻👩🏽‍💻 Contributors
- Anna Halaapiapi
- Tran Nguyen
- Toni Mathieson
