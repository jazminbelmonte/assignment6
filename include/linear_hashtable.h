#ifndef _LINEAR_HASHTABLE_H_
#define _LINEAR_HASHTABLE_H_

#include <iostream>
#include <iomanip>
#include "hash_functions.h"

template<typename T>
class LinearHashtable {
public:
  LinearHashtable(int capacity = 499):  sz(0), capacity(capacity), htable(new T[capacity]()){}

  LinearHashtable(const LinearHashtable<T>& c) = delete;
  LinearHashtable<T>& operator=(const LinearHashtable<T>&& c) = delete;

  friend std::ostream& operator<<(std::ostream& out, const LinearHashtable<T>& t){
    for(int i = 1; i <=t.capacity; i++){
      out << std::setw(5) << t.htable[i];
      if(i % 12 == 0) out << std::endl;
    } 

    out << std::endl;
    return out;
  }

  void add(T e){
    if(full()) throw std::runtime_error("Table is full.");

    int t = divideHF(e, capacity);
    if(!htable[t]){
      htable[t] = e;
    } else {
      int i = 1;
      while (htable[(t + i) % capacity]) i++;
      htable[(t + i) % capacity] = e;
    }

    sz++;
  }

  bool remove(T e){
    if(empty()) throw std::runtime_error("Table is empty.");

    int t = divideHF(e, capacity);
    if(htable[t] == e){
      htable[t] = 0;
      return true;
    } else {
      int i = 1;
      while (i < capacity){
        if(htable[(t + i) % capacity] == e){
          htable[t] = 0;
          return true;
        }
        
        i++;
      }

      htable[t] = 0;
      return false;
    }
  }

  bool	contains(T e) {
    int t = divideHF(e, capacity);
    if(htable[t] == e){
      return true;
    } else {
      int i = 1;
      while (i < capacity){
        if(htable[(t + i) % capacity] == e) return true;
        i++;
      }
      return  false;
    }
  }

  bool empty(){ return sz == 0; }
  bool full(){ return sz == capacity; }
  int size() { return sz; }

  ~LinearHashtable(){
      delete[] htable;
  }
protected:
  int sz, capacity;
  T *htable;
};
#endif