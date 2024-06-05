function menu() {
    echo "Which program are you debugging?"
    echo "(m)ain"
    echo "(t)est"
}

mkdir .vscode
echo '{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++ - Build and debug active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/a.out",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "C/C++: g++ build active file",
            "miDebuggerPath": "/usr/bin/gdb"
        }
    ]
}' >'.vscode/launch.json'

menu
read -p "Enter a choice: " CHOICE
if [[ $CHOICE == "m" ]]; then
    echo '{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "C/C++: g++ build active file",
            "command": "g++",
            "type": "shell",
            "args": 
            [
                "-g", 
                "main.cpp",
                "-Wall",
                "-fsanitize=undefined",
                "-fsanitize=address",
                "-I",
                "./include"
            ],
            "problemMatcher": [
                "$tsc"
            ],
            "presentation": {
                "reveal": "always"
            },
            "group": "build"
        }
    ]
}' >'.vscode/tasks.json'
else
    echo '{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "C/C++: g++ build active file",
            "command": "g++",
            "type": "shell",
            "args": 
            [
                "-g", // makes program debuggable
                "tests/tests.cpp", // the file you wish to run (change to tests/tests.cpp if you want to debug tests)
                "-Wall", // enable all warnings
                "-fsanitize=undefined", // check for undefined behavior
                "-fsanitize=address", // check for leaks
                "-lgtest_main", // run google test main file
                "-lgtest", // links gtest library
                "-lpthread", // links pthread library
                "-I", // include './include directory'
                "./include"
            ],
            "problemMatcher": [
                "$tsc"
            ],
            "presentation": {
                "reveal": "always"
            },
            "group": "build"
        }
    ]
}' >'.vscode/tasks.json'
fi
