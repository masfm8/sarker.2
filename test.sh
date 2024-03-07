#!/bin/bash

# Compile the project
make clean && make

# Run the program with different sets of parameters
./oss -n 5 -s 3 -t 10
./oss -n 10 -s 5 -t 20

# Add more tests with different parameters as needed

echo "Testing complete."
