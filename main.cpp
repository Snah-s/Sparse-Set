#include "src/sparse_set.h"
#include "src/hash_set.h"
#include "src/bit_vector.h"
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

int main(){

  int size = 100;

  SparseSet sparseSet(size);
  BitVector bitVector(size);
  HashSet<int> *hashSet = new HashSet<int>;

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(0, size - 1);

  auto start = high_resolution_clock::now();

  for(int i = 0; i < size; i++) {
    int num = distrib(gen);
    sparseSet.insert(num);
    sparseSet.remove(num);
    sparseSet.exist(num);
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "SparseSet: Total execution time: " << duration.count() << " microseconds" << endl;

  auto start1 = high_resolution_clock::now();

  for(int i = 0; i < size; i++) {
    int num = distrib(gen);
    bitVector.insert(num);
    bitVector.eliminar(num);
    bitVector.member(num);
    }

  auto stop1 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(stop1 - start1);
  cout << "BitVector: Total execution time: " << duration1.count() << " microseconds" << endl;
  auto start2 = high_resolution_clock::now();

  for(int i = 0; i < size; i++) {
    int num = distrib(gen);
    hashSet->insert(num);
    hashSet->remove(num);
    hashSet->find(num);
  }

  auto stop2 = high_resolution_clock::now();
  auto duration2 = duration_cast<microseconds>(stop2 - start2);
  cout << "HashSet: Total execution time: " << duration2.count() << " microseconds" << endl;

  delete hashSet;
}