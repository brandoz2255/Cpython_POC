# Fast Text Processor

A learning project demonstrating CPython C extensions for high-performance text processing operations.

## Overview

This project compares pure Python implementations with C extension versions of common text processing functions. It showcases how to write CPython extensions and demonstrates significant performance improvements for certain operations.

## Features

- **String Reversal**: Reverse text using pure Python vs C
- **Character Frequency Counting**: Count character occurrences
- **Text Cleaning**: Remove punctuation and convert to lowercase
- **Performance Benchmarking**: Compare execution times side-by-side
- **Graceful Fallback**: Automatically uses pure Python if C extension fails to build

## Quick Start

### Build the C Extension

```bash
python fast_text_processor/setup.py build_ext --inplace
```

### Basic Usage

```python
import fast_text_processor as ftp

# Automatically uses fastest available implementation
text = "Hello World!"
print(ftp.reverse_string(text))      # "!dlroW olleH"
print(ftp.char_count(text))          # {'H': 1, 'e': 1, 'l': 3, ...}
print(ftp.clean_text(text))          # "hello world"

# Check if C extension is available
print(f"C Extension: {ftp.HAS_C_EXTENSION}")
```

### Performance Comparison

```python
# Access specific implementations for benchmarking
result_py = ftp.python_reverse(text)   # Pure Python version
result_c = ftp.c_reverse(text)         # C extension version (if available)
```

## Performance Results

Based on 100,000 iterations:

| Operation | Python | C Extension | Speedup |
|-----------|--------|-------------|---------|
| String Reversal | 0.0078s | 0.0063s | 1.25x |
| Character Counting | 0.2089s | 0.1412s | 1.48x |
| Text Cleaning | 0.2158s | 0.0127s | **16.94x** |

## Project Structure

```
fast_text_processor/
├── __init__.py              # Main package interface with fallback logic
├── pure_python.py           # Pure Python implementations
├── c_extensions.c           # C implementation of text processing functions
├── setup.py                 # Build configuration for C extension
└── c_extension.so           # Compiled C extension (after build)

raw_python.py                # Standalone Python implementations
plans.md                     # Original project planning
documentation.md             # Detailed learning notes and explanations
CLAUDE.md                    # Development guidance
```

## How It Works

The package uses a **graceful fallback architecture**:

1. **Import Attempt**: Tries to import the C extension
2. **Fallback**: If unavailable, uses pure Python implementations
3. **Unified API**: Main functions automatically choose the fastest available method
4. **Benchmarking Support**: Both implementations remain accessible for performance testing

## What You'll Learn

- How to write CPython C extensions using the Python C API
- When C extensions provide significant performance benefits
- Proper memory management and error handling in C extensions
- How to structure projects that combine Python and C code
- Performance measurement and optimization techniques

## Requirements

- Python 3.6+
- GCC or compatible C compiler
- setuptools

## Further Reading

See [documentation.md](documentation.md) for detailed explanations of:
- CPython vs CPython Extensions
- Performance analysis
- When to use C extensions
- Development best practices

## Learning Goals

This project is designed to teach:
- **CPython C API**: Writing C code that interfaces with Python
- **Performance Optimization**: Understanding when and how C extensions help
- **Build Systems**: Using setuptools to compile C extensions
- **API Design**: Creating clean interfaces with fallback mechanisms