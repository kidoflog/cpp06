/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:01:27 by kkido             #+#    #+#             */
/*   Updated: 2026/10/11 17:58:44 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
  return true;
}

void convertInt(const std::string& str) {
  std::istringstream stream(str);
  std::ostringstream out;
  int value = 0;
  if (stream >> value) {
  } else {
    std::cout << "Error: Invalid input." << std::endl;
    return;
  }
  if (value <= std::numeric_limits<char>::max() &&
      value >= std::numeric_limits<char>::min()) {
    if (std::isprint(value)) {
      char c = static_cast<char>(value);
      std::cout << "char: " << "'" << c << "'" << std::endl;
    } else {
      std::cout << "char: Non displayable" << std::endl;
    }
  } else {
    std::cout << "char: impossible" << std::endl;
  }
  std::cout << "int: " << value << std::endl;
  float f = static_cast<float>(value);
  out << f;
  std::cout << "float: " << f << std::endl;
  out.clear();
  double d = static_cast<double>(value);
  std::cout << "double: " << d << std::endl;
}

void convertChar(const std::string& str) {
  char c = str[0];
  std::cout << "char: " << c << std::endl;
  int i = c;
  std::cout << "int: " << i << std::endl;
  float f = c;
  std::cout << "float: " << f << std::endl;
  double d = c;
  std::cout << "double: " << d << std::endl;
}

void convertDouble(const std::string& str) {
  std::istringstream stream(str);
  double value = 0;
  if (stream >> value) {
  } else {
    std::cout << "Error: Invalid input." << std::endl;
  }
}

void convertFloat(const std::string& str) {
  std::istringstream stream(str);
  float value = 0;
  if (stream >> value) {
  } else {
    std::cout << "Error: Invalid input." << std::endl;
  }
}
