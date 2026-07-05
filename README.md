# Brash

**Brash** is a command-line interpreter (shell) written in C, focused on the study of operating systems and Unix process architecture. This project aims to explore the logic behind the interaction between the terminal, system calls, and the kernel.


## Name Origin

The name **Brash** is a combination of **"Bra"** (from Brazil) and **"sh"** (from shell), representing a personal take on shell development.


## Project Status

Development is in its early stages. This is an incremental implementation where the shell's foundation is being built, and core features are in the planning and implementation phase.


## Project Structure

The project is organized to separate business logic from configurations and ensure efficient compilation:

```text
brash/
├── include/
│   └── brash.h          # Contracts, definitions, and prototypes
├── src/
│   ├── main.c           # Main logic and execution loop
│   └── io.c             # Input and output management
├── Makefile             # Build automation
├── .gitignore           # Version control exclusions
├── LICENSE              # Project license
└── README.md            # Project documentation
```


## How to Compile

This project uses `make` to simplify compilation. Ensure you have `gcc` and `make` installed on your system.


### Main commands:

1. **Compile the project:**

   In the root directory, execute the command:

   ```bash
   make
   ```

    → This will generate the executable named brash.

2. **Clean temporary files:**

   To remove the object files and the generated executable, execute:

    ```bash
    make clean
    ```


## Capabilities

At the current stage, **Brash** is capable of:

* **Process Creation:** Successfully implements `fork()` to manage external command execution.
* **Command Execution:** Handles standard Unix programs and binaries via `execvp()`.
* **Error Handling:** Provides robust feedback for system call failures and invalid commands.
* **Memory Management:** Implements secure resource allocation and automated cleanup to prevent memory leaks.
* **Interactive Loop:** Maintains a stable shell session with clear command parsing.

## Supported Commands

Since **Brash** leverages `execvp()`, any standard command available in your Linux environment will work. Examples of what you can run right now:

* **File System:** `ls`, `ls -la`, `pwd`, `cd` (via system binary)
* **File Operations:** `cat [file]`, `touch [file]`, `mkdir [dir]`, `rm [file]`
* **System Tools:** `date`, `whoami`, `uname -a`, `top`, `clear`

Try these out in the `brash@user >>` prompt to verify the execution logic.

## Roadmap

Upcoming features and improvements planned for **Brash**:

- [ ] **Built-in Commands:** Implement shell-native commands like `cd` and `exit`.
- [ ] **Signal Handling:** Configure the shell to gracefully handle `SIGINT` (Ctrl+C) without crashing.
- [ ] **Pipe Support:** Enable process chaining using the `|` operator.
- [ ] **Environment Variables:** Allow the shell to parse and utilize environment variables.
- [ ] **Command Localization:** Implement a translation layer to support native Brazilian Portuguese aliases (e.g., `listar` -> `ls`, `criar` -> `mkdir`).

## Technologies

* **Language:** C

* **Environment:** Linux (Arch Linux)

* **Architecture:** Unix/Posix

---

*Developed by [Jhonatan Mickael](https://github.com/jhonatanmickael).*


*Licensed under the MIT License.*

