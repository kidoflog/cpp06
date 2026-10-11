/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:01:32 by kkido             #+#    #+#             */
/*   Updated: 2026/10/05 18:15:04 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter {
 public:
  static void convert(const std::string& str);

 private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter& src);
  ScalarConverter& operator=(const ScalarConverter& src);
  ~ScalarConverter();
};
void convertChar(const std::string& str);
void convertInt(const std::string& str);
void convertDouble(const std::string& str);
void convertFloat(const std::string& str);
bool isChar(const std::string& str);
bool isInt(const std::string& str);
bool isDouble(const std::string& str);
bool isFloat(const std::string& str);

#endif