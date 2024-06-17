#include "src/sparse_set.h"
#include "src/hash_set.h"
#include "src/bit_vector.h"
#include <chrono>

using namespace std;

int main(){
  // Max Element == 40
  HashSet<int> hashSet;
  SparseSet sparseSet(40);

  // Insert 10 elements
  // start chrono
  auto start = chrono::high_resolution_clock::now();
  for (int i = 0; i < 10; i++){
    hashSet.insert(i);
  }
  // end chrono
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
  cout << "HashSet insert: " << duration.count() << " microseconds" << endl;

  // start chrono
  start = chrono::high_resolution_clock::now();
  for (int i = 0; i < 10; i++){
    sparseSet.insert(i);
  }
  // end chrono
  end = chrono::high_resolution_clock::now();
  duration = chrono::duration_cast<chrono::microseconds>(end - start);
  
  cout << "SparseSet insert: " << duration.count() << " microseconds" << endl;

}