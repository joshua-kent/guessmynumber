#!/bin/bash

# This bash script is designed to compile
# directly to Linux, and does not have support
# for compiling to Windows as well.

# Builds the program from source code
# Uses g++ compiler by default (edit Build
# function to change), and compiles
# to Windows and Linux as an executable.

# NOTICE: THIS CURRENTLY DOES NOT HAVE AN OPTION
# TO EXECUTE AFTER BUILD

SOURCEFILE="./source/main.cpp" 
BUILDLOCATION="GMN_linux"

function Build {
    
    # $1 - build location
    if [[ $1 -eq "" ]]; then
        buildLocation=$BUILDLOCATION
    else
        buildLocation=$1
    fi

    echo "Building GuessMyNumber for Linux at $buildLocation..."
    
    g++ $SOURCEFILE -o $buildLocation

    echo "Build complete."
}

# MAIN BUILD:
Build
echo ""