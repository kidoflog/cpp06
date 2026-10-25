/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 20:19:41 by kkido             #+#    #+#             */
/*   Updated: 2026/10/25 20:56:20 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void) {
  Base* base;
  int number = std::rand();
  if (number % 3 == 0) {
    base = new (A);
  } else if (number % 3 == 1) {
    base = new (B);
  } else {
    base = new (C);
  }
  return base;
}

void identify(Base* p) {
  if (!p) {
    std::cout << "Error: null pointer." << std::endl;
    return;
  }
  A* a = dynamic_cast<A*>(p);
  if (a) {
    std::cout << "This pointer points to an object of type A." << std::endl;
    return;
  }
  B* b = dynamic_cast<B*>(p);
  if (b) {
    std::cout << "This pointer points to an object of type B." << std::endl;
    return;
  }
  C* c = dynamic_cast<C*>(p);
  if (c) {
    std::cout << "This pointer points to an object of type C." << std::endl;
    return;
  }
  std::cout << "This pointer points to unknown object." << std::endl;
}

void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "This reference refers to an object of type A." << std::endl;
    return;
  } catch (...) {
  }
  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "This reference refers to an object of type B." << std::endl;
    return;
  } catch (...) {
  }
  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "This reference refers to an object of type C." << std::endl;
    return;
  } catch (...) {
  }
  std::cout << "This reference refers to unknown object." << std::endl;
}