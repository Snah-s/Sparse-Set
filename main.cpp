#include "src/sparse_set.h"
#include "src/hash_set.h"
#include "src/bit_vector.h"
#include <chrono>

using namespace std;

int main(){
  int Max_Element = 100000;
  HashSet<int> hashSet;
  SparseSet sparseSet(Max_Element);

  // Insert 10 elements
  // start chrono
  auto start = chrono::high_resolution_clock::now();
  for (int i = 0; i < Max_Element; i++){
    hashSet.insert(i);
  }
  // end chrono
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  cout << "HashSet insert: " << duration.count() << " milliseconds" << endl;

  // start chrono
  start = chrono::high_resolution_clock::now();
  for (int i = 0; i < Max_Element; i++){
    sparseSet.insert(i);
  }
  // end chrono
  end = chrono::high_resolution_clock::now();
  duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  
  cout << "SparseSet insert: " << duration.count() << " milliseconds" << endl;

}