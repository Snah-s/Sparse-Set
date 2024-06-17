#ifndef SPARSE_SET_H
#define SPARSE_SET_H

#include <iostream>
#include <vector>

using namespace std;

class SparseSet {
private:
  vector<int> dense;
  vector<int> sparse;
  int size;
  int maxElements; // tambien lo puedes interpretar como el tamaño maximo

public:
  SparseSet(int MaxElements): maxElements(MaxElements), size(0){
    dense.resize(maxElements);
    sparse.resize(maxElements);
  }

  void insert(int element){
    if (element >= maxElements || element < 0){
      throw "Elemento invalido";
    }

    if (sparse[element] >= size || dense[sparse[element]] != element){
      sparse[element] = size;
      dense[size] = element;
      size++;
    }
  }

  void remove (int element){
    if (element >= maxElements || element < 0){
      throw "Elemento invalido";
    }

    int index = sparse[element];

    if (index < size && dense[index] == element){
      int lastElement = dense[size -1];
      dense[index] = lastElement;
      sparse[lastElement] = index;
      size--;
    }
  }

  bool exist(int element)const{
    return element < maxElements && element >= 0 && sparse[element] < size && dense[sparse[element]] == element;
  }

  void clear(){
    size = 0;
  }

  int getSize()const{
    return size;
  }

  string toString()const{
    string result = "";
    for (int i = 0; i < size; i++){
      result += to_string(dense[i]) + " ";
    }
    return result;
  }
};

#endif // SPARSE_SET_H