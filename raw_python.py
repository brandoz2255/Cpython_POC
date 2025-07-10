"""
Pure Python implementations for comparison
"""

import string
from collections import Counter


def python_reverse(text):
    """Reverse a string using pure Python"""
    return text[::-1]


def python_char_count(text):
    """Count character frequency using pure Python"""
    return dict(Counter(text))


def python_clean_text(text):
    """Clean text using pure Python"""
    # Remove punctuation and convert to lowercase
    translator = str.maketrans("", "", string.punctuation)
    cleaned = text.translate(translator).lower()
    return cleaned
