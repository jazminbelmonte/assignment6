#ifndef _HASH_FUNCTIONS_H_
#define _HASH_FUNCTIONS_H_

#include <string>
#include <sstream>
#include <cstdlib>

template <typename T>
int divideHF(T e, int capacity){
  return e % capacity;
}

//mid-square hash function
template <typename T>
int midSquareHF(T e, int capacity) {
  double eNew = e;
  double x = (eNew * eNew);
  std::string xString = std::to_string(x);

  while (xString.length() < 7){
    xString.append(std::to_string (rand() % 10));
  }

  std::string mid = xString.substr(3, 3);
  int y = std::stoi(mid);

  return y % capacity;
}

//folding hash function
template <typename T>
int foldingHF(T e, int capacity) {
  std::string eString = std::to_string(e);

  while (eString.length() != 6){
    eString.append(std::to_string (rand() % 10));
  }

  std::string first = eString.substr(0, 2);
  std::string second = eString.substr(2, 2);
  std::string third = eString.substr(4, 2);
  int total = std::stoi(first) + std::stoi(second) + std::stoi(third);

  return total % capacity;
}

//selecting-digits hash function
template <typename T>
int selectHF(T e, int capacity) {
  std::string key;
  std::string eString = std::to_string (e);

  while (eString.length() != 6){
    eString.append(std::to_string (rand() % 10));
  }

  std::stringstream sin;
  sin << eString.substr (1, 2);
  sin << eString.substr (4, 1);
  sin >> key;
  int y = std::stoi(key);

  return y % capacity;
}

#endif