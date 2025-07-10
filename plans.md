Here's a perfect small project to learn both CPython extensions and Poetry together:
Project: "Fast Text Processor"
A Python package that uses CPython to accelerate text processing operations.
What it does:

Python interface for common text operations
CPython extension for performance-critical parts
Compare pure Python vs C extension performance

Project Structure:
fast_text_processor/
├── pyproject.toml
├── fast_text_processor/
│   ├── __init__.py
│   ├── pure_python.py
│   └── c_extension.c
├── setup.py (for building C extension)
├── tests/
└── benchmarks/
Features to implement:

String reversal (easy CPython starter)
Character frequency counting
Simple text cleaning (remove punctuation, lowercase)
Benchmark comparison between Python and C versions

Why this is perfect for learning:

CPython: Simple string operations are great for learning the C API
Poetry: Handles both Python dependencies and C extension building
Small scope: Can finish in a weekend
Practical: You'll actually use text processing

Poetry setup:
