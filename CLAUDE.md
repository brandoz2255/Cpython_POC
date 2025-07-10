# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

This is a Fast Text Processor project - a learning project that demonstrates CPython C extensions for performance-critical text operations. The goal is to learn both CPython extensions and compare pure Python vs C extension performance side by side.

**Project Goals:**
- Python interface for common text operations
- CPython extension for performance-critical parts  
- Compare pure Python vs C extension performance
- Learn the CPython C API with simple string operations
- Small scope that can be completed in a weekend

**Implemented Features:**
- String reversal (easy CPython starter)
- Character frequency counting
- Simple text cleaning (remove punctuation, lowercase)
- Benchmark comparison between Python and C versions

## Build and Development Commands

### Building the C Extension
```bash
python fast_text_processor/setup.py build_ext --inplace
```

### Installing the Package
```bash
pip install -e .
```

### Running Basic Tests
```bash
python -c "import fast_text_processor; print(fast_text_processor.reverse_string('hello'))"
```

## Code Architecture

### Core Structure
- `fast_text_processor/` - Main package directory
  - `__init__.py` - Package interface with fallback logic
  - `c_extensions.c` - C implementation of text processing functions
  - `setup.py` - Build configuration for C extension
- `raw_python.py` - Standalone pure Python implementations
- `plans.md` - Project planning and feature documentation

### Key Design Patterns

**Fallback Architecture**: The package uses a graceful fallback pattern where:
1. It attempts to import the C extension module
2. If the C extension is unavailable, it falls back to pure Python implementations
3. The main API functions (`reverse_string`, `char_count`, `clean_text`) automatically use the fastest available method

**Performance Comparison Support**: The package exposes both C and Python versions separately for benchmarking:
- `c_reverse`, `c_char_count`, `c_clean_text` - C implementations (if available)
- `python_reverse`, `python_char_count`, `python_clean_text` - Pure Python implementations

### C Extension Details
The C extension (`c_extensions.c`) implements three main functions:
- `fast_reverse` - String reversal using manual character copying
- `fast_char_count` - Character frequency counting using Python dictionaries
- `fast_clean_text` - Text cleaning (remove punctuation, lowercase) using C character manipulation

The C code follows proper Python C API patterns with reference counting and error handling.

### File Relationships
- `fast_text_processor/__init__.py` imports from both `c_extension` (C) and creates a unified API
- `raw_python.py` contains identical functions to those in the package but as standalone implementations
- The package structure allows for easy benchmarking between implementations