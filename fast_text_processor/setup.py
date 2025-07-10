from setuptools import setup, Extension

# Define the C extension
c_extension = Extension(
    "fast_text_processor.c_extension",
    sources=["fast_text_processor/c_extensions.c"],
    include_dirs=[],
    libraries=[],
    library_dirs=[],
    extra_compile_args=["-O3"],  # Optimization
)

setup(
    name="fast-text-processor",
    ext_modules=[c_extension],
    zip_safe=False,
)
