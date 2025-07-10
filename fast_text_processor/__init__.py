"""
Fast Text Processor - CPython Extension Demo
"""

try:
    # Import the C extension
    from . import c_extension

    HAS_C_EXTENSION = True
except ImportError:
    HAS_C_EXTENSION = False
    print("Warning: C extension not available, falling back to pure Python")

from .pure_python import python_reverse, python_char_count, python_clean_text


def reverse_string(text):
    """Reverse a string using the fastest available method"""
    if HAS_C_EXTENSION:
        return c_extension.fast_reverse(text)
    else:
        return python_reverse(text)


def char_count(text):
    """Count character frequency using the fastest available method"""
    if HAS_C_EXTENSION:
        return c_extension.fast_char_count(text)
    else:
        return python_char_count(text)


def clean_text(text):
    """Clean text using the fastest available method"""
    if HAS_C_EXTENSION:
        return c_extension.fast_clean_text(text)
    else:
        return python_clean_text(text)


# Expose both C and Python versions for benchmarking
if HAS_C_EXTENSION:
    c_reverse = c_extension.fast_reverse
    c_char_count = c_extension.fast_char_count
    c_clean_text = c_extension.fast_clean_text
else:
    c_reverse = None
    c_char_count = None
    c_clean_text = None

__all__ = [
    "reverse_string",
    "char_count",
    "clean_text",
    "python_reverse",
    "python_char_count",
    "python_clean_text",
    "c_reverse",
    "c_char_count",
    "c_clean_text",
    "HAS_C_EXTENSION",
]
