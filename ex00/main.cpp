/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:51:06 by kkido             #+#    #+#             */
/*   Updated: 2026/10/11 19:48:11 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Usage: ./convert <input>" << std::endl;
    return 0;
  }
  std::string input = argv[1];
  ScalarConverter::convert(input);
  return 0;
}