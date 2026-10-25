/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:51:06 by kkido             #+#    #+#             */
/*   Updated: 2026/10/25 19:47:50 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"

int main() {
  Data data;
  uintptr_t ptr;
  Data* dataptr;
  data.src = "Hello, world!";
  ptr = Serializer::serialize(&data);
  dataptr = Serializer::deserialize(ptr);
  std::cout << "Original Data: " << data.src << std::endl;
  std::cout << "Converted Data: " << dataptr->src << std::endl;
  std::cout << "Original pointer: " << &data << std::endl;
  std::cout << "Serialized value: " << ptr << std::endl;
  std::cout << "Deserialized pointer: " << dataptr << std::endl;
  if (dataptr == &data) {
    std::cout << "dataptr == &data" << std::endl;
  } else {
    std::cout << "dataptr != &data" << std::endl;
  }
}
