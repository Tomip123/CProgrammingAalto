# 🎓 Aalto University: C Programming Mastery

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Build System](https://img.shields.io/badge/Build-Makefile-orange.svg)](https://www.gnu.org/software/make/)
[![Testing](https://img.shields.io/badge/Testing-Valgrind-green.svg)](https://valgrind.org/)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

A comprehensive collection of modules, exercises, and projects from the Aalto University C Programming curriculum. This repository tracks the journey from fundamental syntax to complex system-level programming, memory management, and data structures.

---

## 🗺️ Curriculum Roadmap

The course is structured into progressive modules, each targeting specific core competencies in C development:

| Module | Focus Area | Key Concepts |
| :--- | :--- | :--- |
| **M01-M02** | **Foundations** | Control flow, `printf/scanf`, arithmetic series, and vector math. |
| **M03** | **Logic & Macros** | ASCII manipulation, preprocessor macros, and complex nested loops. |
| **M04** | **Bit Manipulation** | Bitwise operators, sequence analysis, and custom frame header parsing. |
| **M05** | **Memory & Arrays** | Pointer arithmetic, string buffers, and standard sorting algorithms. |
| **M06** | **Dynamic Allocation** | `malloc/free`, dynamic arrays, and advanced string manipulation. |
| **M07-M08** | **Data Structures** | Structs, linked lists (Queues), vehicle seat management, and product catalogs. |
| **M09** | **System & Files** | File I/O (binary/text), hex dumps, and the **Final Dungeon Project**. |

---

## 🚀 Key Projects

### 🏰 [M09-T5] The Dungeon
A terminal-based rogue-like engine demonstrating:
- Procedural map generation.
- Monster AI and player interaction logic.
- Modular code architecture across multiple header and source files.

### 🔢 Bit Manipulation Engine
Advanced bitwise operations to handle low-level data protocols, essential for embedded systems and performance-critical software.

### 🛡️ Memory Safety (The Polisher)
Extensive use of **Valgrind** to ensure zero memory leaks and prevent segmentation faults in dynamic data structures.

---

## 🛠️ Development Workflow

Every exercise follows a standardized build system for consistency and ease of testing.

### Prerequisites
- **Compiler:** `gcc` (Standard C99/C11)
- **Build Tool:** `make`
- **Memory Analysis:** `valgrind`

### Building an Exercise
Navigate to any task directory (e.g., `M05/sort`) and use the provided Makefile:

```bash
# Compile the main program
make main

# Run the compiled binary
./src/main

# Execute automated tests
make test

# Check for memory leaks
make valgrind-test
```

---

## 📝 Exam Preparation

The repository includes dedicated folders for exam practice:
- `Exam/`: Past exam tasks (March 2022) covering Strings, Bits, and Arrays.
- `ExampleExam/`: Mock exams to simulate the pressure of timed coding assessments.

---

## 💻 Environment Setup

This project is optimized for **VS Code**.
- `.vscode/`: Contains `launch.json` and `tasks.json` for integrated debugging and building.
- `.code-workspace`: Individual workspace files for each module to keep the development environment focused.

---

*Part of the Aalto University Computer Science curriculum.*
