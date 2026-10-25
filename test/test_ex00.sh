#!/usr/bin/env bash

cd "$(dirname "$0")/../ex00" || exit 1

# Integer inputs
echo ""
echo "Input: 0"
./convert 0
echo ""
echo "Input: 7"
./convert 7
echo ""
echo "Input: 31"
./convert 31
echo ""
echo "Input: 32"
./convert 32
echo ""
echo "Input: 42"
./convert 42
echo ""
echo "Input: +42"
./convert +42
echo ""
echo "Input: -42"
./convert -42
echo ""
echo "Input: 256"
./convert 256

# Character inputs
echo ""
echo "Input: a"
./convert a
echo ""
echo "Input: +"
./convert +
echo ""
echo "Input: -"
./convert -

# Double inputs
echo ""
echo "Input: 0.0"
./convert 0.0
echo ""
echo "Input: 42.0"
./convert 42.0
echo ""
echo "Input: 4.25"
./convert 4.25
echo ""
echo "Input: -4.25"
./convert -4.25

# Float inputs
echo ""
echo "Input: 0.0f"
./convert 0.0f
echo ""
echo "Input: 42.0f"
./convert 42.0f
echo ""
echo "Input: 4.25f"
./convert 4.25f
echo ""
echo "Input: -4.25f"
./convert -4.25f

# Special values
echo ""
echo "Input: nan"
./convert nan
echo ""
echo "Input: nanf"
./convert nanf
echo ""
echo "Input: -inf"
./convert -inf
echo ""
echo "Input: -inff"
./convert -inff
echo ""
echo "Input: +inf"
./convert +inf
echo ""
echo "Input: +inff"
./convert +inff

# Invalid inputs
echo ""
echo 'Input: "" (empty string)'
./convert ""
echo ""
echo "Input: 12abc"
./convert 12abc
echo ""
echo "Input: 1.2.3"
./convert 1.2.3
echo ""
echo "Input: 4.2ff"
./convert 4.2ff
echo ""
echo "Input: 9999999999999999999999999999999999999999"
./convert 9999999999999999999999999999999999999999
