#!/usr/bin/env bash

cd "$(dirname "$0")/../ex00" || exit 1

# Integer inputs
echo "Input: 0"
./convert 0
echo "Input: 7"
./convert 7
echo "Input: 31"
./convert 31
echo "Input: 32"
./convert 32
echo "Input: 42"
./convert 42
echo "Input: +42"
./convert +42
echo "Input: -42"
./convert -42
echo "Input: 256"
./convert 256

# Character inputs
echo "Input: a"
./convert a
echo "Input: +"
./convert +
echo "Input: -"
./convert -

# Double inputs
echo "Input: 0.0"
./convert 0.0
echo "Input: 42.0"
./convert 42.0
echo "Input: 4.25"
./convert 4.25
echo "Input: -4.25"
./convert -4.25

# Float inputs
echo "Input: 0.0f"
./convert 0.0f
echo "Input: 42.0f"
./convert 42.0f
echo "Input: 4.25f"
./convert 4.25f
echo "Input: -4.25f"
./convert -4.25f

# Special values
echo "Input: nan"
./convert nan
echo "Input: nanf"
./convert nanf
echo "Input: -inf"
./convert -inf
echo "Input: -inff"
./convert -inff
echo "Input: +inf"
./convert +inf
echo "Input: +inff"
./convert +inff

# Invalid inputs
echo 'Input: "" (empty string)'
./convert ""
echo "Input: 12abc"
./convert 12abc
echo "Input: 1.2.3"
./convert 1.2.3
echo "Input: 4.2ff"
./convert 4.2ff
echo "Input: 9999999999999999999999999999999999999999"
./convert 9999999999999999999999999999999999999999
