#include <chrono>
#include <iostream>
#include <cstdlib>
#include "linear_hashtable.h"
#include "chained_hashtable.h"
#include "quadratic_hashtable.h"
using namespace std;

int main(){

  LinearHashtable<int> lht(599);

  auto lstart = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 250; i++){
    lht.add(rand() % 1000000);
  }
  auto lend = std::chrono::high_resolution_clock::now();

  cout << lht << endl;
  cout << "It took " << chrono::duration_cast<chrono::microseconds>(lend - lstart).count() << " microseconds" << endl;
  cout << endl;
  cout << endl;




  ChainedHashtable<int> ht(599);

  auto cstart = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 250; i++){
    ht.add(rand() % 1000000);
  }
  auto cend = std::chrono::high_resolution_clock::now();

  cout << ht << endl;
  cout << "It took " << chrono::duration_cast<chrono::microseconds>(cend - cstart).count() << " microseconds" << endl;
  cout << endl;
  cout << endl;




  QuadraticHashtable<int> qht(599);

  auto startq = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 250; i++){
    qht.add(rand() % 1000000);
  }
  auto endq = std::chrono::high_resolution_clock::now();

  cout << qht << endl;
  cout << "It took " << chrono::duration_cast<chrono::microseconds>(endq - startq).count() << " microseconds" << endl;

  return 0;
}
