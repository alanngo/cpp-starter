# C++ Starter
C++ program to get projects started and going on Linux Enviornment
## ⭐ Features

- Colored logging
- Unit Testing
- VScode Debugging

## 🚀 Getting Started
- ``$ make run`` => Runs main file
- ``$ make test`` => Runs all test cases

## 🪲 Debugging

### VSCode (only debugs main file)
1.  ``make debug-start`` => Generates vscode debug files
2. Open VsCode ->``Run`` -> ``Start Debugging``

### GDB
-  ``make debug`` => Build and runs entry point file
    - ``ENTRY_POINT``: specifies which files to compile (defaults to ``tests/tests.cpp``)
