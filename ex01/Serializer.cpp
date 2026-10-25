/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:01:27 by kkido             #+#    #+#             */
/*   Updated: 2026/10/25 21:03:05 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::Serializer(const Serializer& src) {
  (void)src;
}

Serializer& Serializer::operator=(const Serializer& src) {
  (void)src;
  return *this;
}

Serializer::~Serializer() {
}

uintptr_t Serializer::serialize(Data* ptr) {
  uintptr_t adress = reinterpret_cast<uintptr_t>(ptr);
  return adress;
}

Data* Serializer::deserialize(uintptr_t raw) {
  Data* data = reinterpret_cast<Data*>(raw);
  return data;
}