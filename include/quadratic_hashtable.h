//
// Created by Jazmin Belmonte on 10/18/18.
//
#ifndef _QUADRATIC_HASHTABLE_H_
#define _QUADRATIC_HASHTABLE_H_

#include <iostream>
#include <iomanip>
#include "hash_functions.h"


template<typename T>
struct Cell {
  T info;
  bool empty = true;
};

template<typename T>
class QuadraticHashtable {
public:
  QuadraticHashtable(int capacity = 499):  sz(0), capacity(capacity), htable(new Cell<T>[capacity]()){}

  QuadraticHashtable(const QuadraticHashtable<T>& c) = delete;
  QuadraticHashtable<T>& operator=(const QuadraticHashtable<T>&& c) = delete;

  friend std::ostream& operator<<(std::ostream& out, const QuadraticHashtable<T>& t){
      for(int i = 1; i <= t.capacity; i++){
          out << std::setw(5) << t.htable[i-1].info;
          if(i % 12 == 0) out << std::endl;
      }

      out << std::endl;
      return out;
  }

  void add(T e){
      if(full()) throw std::runtime_error("Table is full.");

      int t = divideHF(e, capacity);
      if(htable[t].empty){
          htable[t] = { e, false};
      }
      //TODO: change from linear probing to quadratic probing
      else {
          int i = 1;
          while (!htable[(t + i) % capacity].empty) i += 2;
          htable[(t + (i*i)) % capacity] = {e, false};
      }

      sz++;
  }

  bool remove(T e){
      if(empty()) return false;

      int t = divideHF(e, capacity);
      if(htable[t].info == e){
          htable[t].empty = true;
          sz--;
          return true;
      } else {
          int i = 1;
          while (i < capacity){
              if(htable[(t + i) % capacity].info == e){
                  htable[t].empty = true;
                  sz--;
                  return true;
              }

              i++;
          }

          return false;
      }
  }

  bool	contains(T e) {
      int t = divideHF(e, capacity);
      if(htable[t].info == e){
          return true;
      } else {
          int i = 1;
          while (i < capacity){
              if(htable[(t + i) % capacity].info == e) return true;
              i++;
          }
          return false;
      }
  }

  bool empty(){ return sz == 0; }
  bool full(){ return sz == capacity; }
  int size() { return sz; }

  ~QuadraticHashtable(){
      delete[] htable;
  }
protected:
  int sz, capacity;
  Cell<T> *htable;
};

#endif //_QUADRATIC_HASHTABLE_H_
