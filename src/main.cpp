#include <iostream>
#include <chrono>
#include <cstdlib>
#include "linear_hashtable.h"
#include "chained_hashtable.h"
using namespace std;

int main(){
  LinearHashtable<int> lht(57);

  for(int i = 0; i < 50; i++){
    lht.add(1 + rand() % 100);
  }
  cout << lht << endl;

  cout << lht.contains(17) << endl;
  cout << lht.contains(26) << endl;

  cout << lht.remove(4) << endl;
  cout << lht << endl;

  ChainedHashtable<int> ht(19);

  for(int i = 0; i < 50; i++){
    ht.add(1 + rand() % 100);
  }

  cout << ht << endl;

  cout << ht.contains(17) << endl;
  cout << ht.contains(26) << endl;

  cout << ht.remove(4) << endl;
  cout << ht << endl;

  return 0;
}