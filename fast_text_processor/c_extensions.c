#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <string.h>
#include <ctype.h>

/* Fast string reversal using C */
static PyObject* fast_reverse(PyObject* self, PyObject* args) {
    const char* input;
    Py_ssize_t len;
    
    // Parse the input string
    if (!PyArg_ParseTuple(args, "s#", &input, &len)) {
        return NULL;
    }
    
    // Allocate memory for reversed string
    char* reversed = (char*)malloc(len + 1);
    if (!reversed) {
        return PyErr_NoMemory();
    }
    
    // Reverse the string
    for (Py_ssize_t i = 0; i < len; i++) {
        reversed[i] = input[len - 1 - i];
    }
    reversed[len] = '\0';
    
    // Create Python string object
    PyObject* result = PyUnicode_FromString(reversed);
    free(reversed);
    
    return result;
}

/* Fast character frequency counting */
static PyObject* fast_char_count(PyObject* self, PyObject* args) {
    const char* input;
    Py_ssize_t len;
    
    if (!PyArg_ParseTuple(args, "s#", &input, &len)) {
        return NULL;
    }
    
    // Create a Python dictionary for results
    PyObject* dict = PyDict_New();
    if (!dict) {
        return NULL;
    }
    
    // Count characters
    for (Py_ssize_t i = 0; i < len; i++) {
        char c = input[i];
        PyObject* key = PyUnicode_FromStringAndSize(&c, 1);
        PyObject* count = PyDict_GetItem(dict, key);
        
        if (count) {
            // Increment existing count
            long current = PyLong_AsLong(count);
            PyObject* new_count = PyLong_FromLong(current + 1);
            PyDict_SetItem(dict, key, new_count);
            Py_DECREF(new_count);
        } else {
            // First occurrence
            PyObject* one = PyLong_FromLong(1);
            PyDict_SetItem(dict, key, one);
            Py_DECREF(one);
        }
        Py_DECREF(key);
    }
    
    return dict;
}

/* Fast text cleaning (remove punctuation, lowercase) */
static PyObject* fast_clean_text(PyObject* self, PyObject* args) {
    const char* input;
    Py_ssize_t len;
    
    if (!PyArg_ParseTuple(args, "s#", &input, &len)) {
        return NULL;
    }
    
    // Allocate memory for cleaned string (worst case: same length)
    char* cleaned = (char*)malloc(len + 1);
    if (!cleaned) {
        return PyErr_NoMemory();
    }
    
    Py_ssize_t write_pos = 0;
    
    // Clean the string
    for (Py_ssize_t i = 0; i < len; i++) {
        char c = input[i];
        if (isalnum(c) || isspace(c)) {
            cleaned[write_pos++] = tolower(c);
        }
    }
    cleaned[write_pos] = '\0';
    
    // Create Python string object
    PyObject* result = PyUnicode_FromString(cleaned);
    free(cleaned);
    
    return result;
}

/* Method definitions */
static PyMethodDef TextProcessorMethods[] = {
    {"fast_reverse", fast_reverse, METH_VARARGS, "Reverse a string using C"},
    {"fast_char_count", fast_char_count, METH_VARARGS, "Count character frequency using C"},
    {"fast_clean_text", fast_clean_text, METH_VARARGS, "Clean text (remove punctuation, lowercase) using C"},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

/* Module definition */
static struct PyModuleDef textprocessormodule = {
    PyModuleDef_HEAD_INIT,
    "c_extension",   /* name of module */
    "Fast text processing using C extensions", /* module documentation */
    -1,       /* size of per-interpreter state of the module */
    TextProcessorMethods
};

/* Module initialization */
PyMODINIT_FUNC PyInit_c_extension(void) {
    return PyModule_Create(&textprocessormodule);
}
