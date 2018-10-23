#ifndef _HASH_FUNCTION_H_
#define _HASH_FUNCTION_H_

template <typename T>
int divideHF(T e, int capacity){
  return e % capacity;
}

/*//TODO: mid-square
//which involves squaring the key and uses a number of digits from
//the middle of the result to create a hash code
int midSquareHF(T e, int capacity) {

}

//TODO: folding
//which breaks the key into multiple parts and adds these parts together
//in some convenient way of your choosing to create a hash code
int foldingHF(T e, int capacity) {

}

//TODO: selecting-digits
//which uses the second, third, and fifth digits of the key to create a hash code.
int selectDgtHF(T e, int capacity) {

}*/

#endif