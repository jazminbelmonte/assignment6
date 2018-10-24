#ifndef _HASH_FUNCTIONS_H_
#define _HASH_FUNCTIONS_H_

#include <string>
#include <sstream>

template <typename T>

int divideHF(T e, int capacity){
  return e % capacity;
}

//mid-square hash function
int midSquareHF(int e) {
   int x = e * e;
   std::string strx = std::to_string(x);
   std::string mid = strx.substr(2, 2);
   int y = std::stoi(mid);

   return y;
}

//folding hash function
int foldingHF(int e) {
  std::string x = std::to_string(e);
  std::string first = x.substr(0, 2);
  std::string second = x.substr(2, 2);
  std::string third = x.substr(4, 2);
  int total = std::stoi(first) + std::stoi(second) + std::stoi(third);

  return total;
}

//selecting-digits hash function
int selectDgtHF(int e) {
  std::string key;
  std::string stre = std::to_string(e);
  std::stringstream sin;
  sin << stre.substr(1, 2);
  sin << stre.substr(4, 1);
  sin >> key;
  int y = std::stoi(key);

  return y;
}

#endif