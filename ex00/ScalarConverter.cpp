/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:01:27 by kkido             #+#    #+#             */
/*   Updated: 2026/10/11 22:14:53 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cctype>
#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
  (void)src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {
  (void)src;
  return *this;
}

ScalarConverter::~ScalarConverter() {
}

void ScalarConverter::convert(const std::string& str) {
  if (isChar(str)) {
    convertChar(str);
  } else if (isInt(str)) {
    convertInt(str);
  } else if (isDouble(str)) {
    convertDouble(str);
  } else if (isFloat(str)) {
    convertFloat(str);
  } else {
    std::cout << "Error: Invalid input." << std::endl;
  }
}

bool isChar(const std::string& str) {
  return (str.length() == 1 && !(str[0] <= '9' && str[0] >= '0'));
}

bool isInt(const std::string& str) {
  int i = 0;
  if (str[i] == '+' || str[i] == '-') {
    i++;
  }
  if (!(str[i] <= '9' && str[i] >= '0')) {
    return false;
  }
  while (str[i] <= '9' && str[i] >= '0') {
    i++;
  }
  if (str[i] != '\0') {
    return false;
  }
  std::istringstream stream(str);
  int value = 0;
  if (!(stream >> value)) {
    return false;
  }
  return true;
}

bool isDouble(const std::string& str) {
  if (str == "-inf" || str == "+inf" || str == "nan") {
    return true;
  }
  int i = 0;
  if (str[i] == '+' || str[i] == '-') {
    i++;
  }
  if (!(str[i] <= '9' && str[i] >= '0')) {
    return false;
  }
  while (str[i] <= '9' && str[i] >= '0') {
    i++;
  }
  if (str[i] != '.' || !(str[i + 1] <= '9' && str[i + 1] >= '0')) {
    return false;
  }
  i++;
  while (str[i] <= '9' && str[i] >= '0') {
    i++;
  }
  if (str[i] != '\0') {
    return false;
  }
  std::istringstream stream(str);
  double value = 0;
  if (!(stream >> value)) {
    return false;
  }
  return true;
}

bool isFloat(const std::string& str) {
  if (str == "-inff" || str == "+inff" || str == "nanf") {
    return true;
  }
  int i = 0;
  if (str[i] == '+' || str[i] == '-') {
    i++;
  }
  if (!(str[i] <= '9' && str[i] >= '0')) {
    return false;
  }
  while (str[i] <= '9' && str[i] >= '0') {
    i++;
  }
  if (str[i] != '.' || !(str[i + 1] <= '9' && str[i + 1] >= '0')) {
    return false;
  }
  i++;
  while (str[i] <= '9' && str[i] >= '0') {
    i++;
  }
  if (str[i] != 'f' || str[i + 1] != '\0') {
    return false;
  }
  std::string numberPart = str.substr(0, str.size() - 1);
  std::istringstream stream(numberPart);
  float value = 0;
  if (!(stream >> value)) {
    return false;
  }
  return true;
}

void convertInt(const std::string& str) {
  std::istringstream stream(str);
  int value = 0;
  stream >> value;
  if (value <= std::numeric_limits<char>::max() &&
      value >= std::numeric_limits<char>::min()) {
    char c = static_cast<char>(value);
    unsigned char uc = static_cast<unsigned char>(c);
    if (std::isprint(uc)) {
      std::cout << "char: " << "'" << c << "'" << std::endl;
    } else {
      std::cout << "char: Non displayable" << std::endl;
    }
  } else {
    std::cout << "char: impossible" << std::endl;
  }
  std::cout << "int: " << value << std::endl;
  float f = static_cast<float>(value);
  std::cout << "float: " << formatFloat(f) << std::endl;
  double d = static_cast<double>(value);
  std::cout << "double: " << formatDouble(d) << std::endl;
}

void convertChar(const std::string& str) {
  char c = str[0];
  std::cout << "char: " << "'" << c << "'" << std::endl;
  int i = static_cast<int>(c);
  std::cout << "int: " << i << std::endl;
  float f = static_cast<float>(c);
  std::cout << "float: " << formatFloat(f) << std::endl;
  double d = static_cast<double>(c);
  std::cout << "double: " << formatDouble(d) << std::endl;
}

void convertDouble(const std::string& str) {
  if (str == "nan" || str == "+inf" || str == "-inf") {
    convertSpecialLiteral(str);
    return;
  }
  std::istringstream stream(str);
  double value = 0;
  stream >> value;
  double integerPart;
  std::modf(value, &integerPart);
  if (integerPart <= std::numeric_limits<char>::max() &&
      integerPart >= std::numeric_limits<char>::min()) {
    char c = static_cast<char>(value);
    unsigned char uc = static_cast<unsigned char>(c);
    if (std::isprint(uc)) {
      std::cout << "char: " << "'" << c << "'" << std::endl;
    } else {
      std::cout << "char: Non displayable" << std::endl;
    }
  } else {
    std::cout << "char: impossible" << std::endl;
  }
  if (integerPart <= std::numeric_limits<int>::max() &&
      integerPart >= std::numeric_limits<int>::min()) {
    int i = static_cast<int>(value);
    std::cout << "int: " << i << std::endl;
  } else {
    std::cout << "int: impossible" << std::endl;
  }
  if (value <= std::numeric_limits<float>::max() &&
      value >= -std::numeric_limits<float>::max()) {
    float f = static_cast<float>(value);
    std::cout << "float: " << formatFloat(f) << std::endl;
  } else {
    std::cout << "float: impossible" << std::endl;
  }
  std::cout << "double: " << formatDouble(value) << std::endl;
}

void convertFloat(const std::string& str) {
  if (str == "nanf" || str == "+inff" || str == "-inff") {
    convertSpecialLiteral(str);
    return;
  }
  std::string numberPart = str.substr(0, str.size() - 1);
  std::istringstream stream(numberPart);
  float value = 0;
  stream >> value;
  double integerPart;
  std::modf(value, &integerPart);
  if (integerPart <= std::numeric_limits<char>::max() &&
      integerPart >= std::numeric_limits<char>::min()) {
    char c = static_cast<char>(value);
    unsigned char uc = static_cast<unsigned char>(c);
    if (std::isprint(uc)) {
      std::cout << "char: " << "'" << c << "'" << std::endl;
    } else {
      std::cout << "char: Non displayable" << std::endl;
    }
  } else {
    std::cout << "char: impossible" << std::endl;
  }
  if (integerPart <= std::numeric_limits<int>::max() &&
      integerPart >= std::numeric_limits<int>::min()) {
    int i = static_cast<int>(value);
    std::cout << "int: " << i << std::endl;
  } else {
    std::cout << "int: impossible" << std::endl;
  }
  std::cout << "float: " << formatFloat(value) << std::endl;
  double d = static_cast<double>(value);
  std::cout << "double: " << formatDouble(d) << std::endl;
}

std::string formatDouble(const double& value) {
  std::ostringstream out;
  out << value;
  std::string text = out.str();
  if (text.find_first_of(".eE") == std::string::npos) {
    text += ".0";
  }
  return text;
}

std::string formatFloat(const float& value) {
  std::ostringstream out;
  out << value;
  std::string text = out.str();
  if (text.find_first_of(".eE") == std::string::npos) {
    text += ".0";
  }
  text += "f";
  return text;
}

void convertSpecialLiteral(const std::string& str) {
  if (str == "nan" || str == "nanf") {
    convertNanNanf();
  } else if (str == "+inf" || str == "+inff") {
    convertPlusInfInff();
  } else if (str == "-inf" || str == "-inff") {
    convertMinusInfInff();
  }
}

void convertNanNanf() {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: nanf" << std::endl;
  std::cout << "double: nan" << std::endl;
}
void convertPlusInfInff() {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: +inff" << std::endl;
  std::cout << "double: +inf" << std::endl;
}

void convertMinusInfInff() {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: -inff" << std::endl;
  std::cout << "double: -inf" << std::endl;
}