/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:51:06 by kkido             #+#    #+#             */
/*   Updated: 2026/10/25 21:00:19 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "func.hpp"

int main() {
  std::srand(static_cast<unsigned int>(std::time(0)));
  std::cout << "----- ptr identify test -----" << std::endl;
  for (int i = 0; i < 5; i++) {
    Base* baseptr = generate();
    identify(baseptr);
    delete (baseptr);
  }
  std::cout << "----- ref identify test -----" << std::endl;
  for (int i = 0; i < 5; i++) {
    Base* baseptr = generate();
    identify(*baseptr);
    delete (baseptr);
  }
  std::cout << "----- mix test -----" << std::endl;
  for (int i = 0; i < 5; i++) {
    Base* baseptr = generate();
    identify(baseptr);
    identify(*baseptr);
    delete (baseptr);
  }
}
