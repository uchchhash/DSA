#!/bin/bash

# Check if a filename was provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <filename.cpp>"
    exit 1
fi

# Get the filename without extension
filename=$(basename "$1" .cpp)

# Compile the C++ file
g++ -o "$filename" "$1"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Run the executable
    ./"$filename"
else
    echo "Compilation failed."
fi
