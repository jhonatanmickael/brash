# Brash


**Brash** is a command-line interpreter (shell) written in C, focused on the study of operating systems and Unix process architecture. This project aims to explore the logic behind the interaction between the terminal, system calls, and the kernel.


## Name Origin

The name **Brash** is a combination of **"Bra"** (from Brazil) and **"sh"** (from shell), representing a personal take on shell development.


## Project Status

Development is in its early stages. This is an incremental implementation where the shell's foundation is being built, and core features are in the planning and implementation phase.


## Technologies

* **Language:** C

* **Environment:** Linux (Arch Linux)

* **Architecture:** Unix/Posix


##  Project Structure
```text
brash/
├── src/          # Main source code
├── include/      # Header files
├── Makefile      # Build automation
├── .gitignore    # Version control exclusions
└── README.md     # Documentation
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

---

*Developed by [Jhonatan Mickael](https://github.com/jhonatanmickael).*


*Licensed under the MIT License.*

