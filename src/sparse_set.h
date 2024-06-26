#ifndef SPARSE_SET_H
#define SPARSE_SET_H

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class SparseSet {
private:
    int* dense;
    int* sparse;
    int size;
    int maxElements;

public:
    SparseSet(int MaxElements) : size(0), maxElements(MaxElements) {
        dense = new int[maxElements];
        sparse = new int[maxElements];
    }

    ~SparseSet() {
        delete[] dense;
        delete[] sparse;
    }

    void insert(int element) {
        if (element >= maxElements || element < 0) {
            throw invalid_argument("Elemento invalido");
        }

        if (sparse[element] >= size || dense[sparse[element]] != element) {
            sparse[element] = size;
            dense[size] = element;
            size++;
        }
    }

    void remove(int element) {
        if (element >= maxElements || element < 0) {
            throw invalid_argument("Elemento Invalido");
        }

        int index = sparse[element];

        if (exist(element)) {
            int lastElement = dense[size - 1];
            dense[index] = lastElement;
            sparse[lastElement] = index;
            size--;
        }
    }

    bool exist(int element) const {
        return element < maxElements && element >= 0 && sparse[element] < size && dense[sparse[element]] == element;
    }

    void clear() {
        size = 0;
    }

    int getSize() const {
        return size;
    }

    string toString() const {
        string result = "";
        for (int i = 0; i < size; i++) {
            result += to_string(dense[i]) + " ";
        }
        return result;
    }

    void unionSet(const SparseSet& other) {
        SparseSet result(max(maxElements, other.maxElements));
        for (int i = 0; i < size; i++) {
            result.insert(dense[i]);
        }
        for (int i = 0; i < other.size; i++) {
            result.insert(other.dense[i]);
        }
    }

    SparseSet intersection(const SparseSet& other) {
        SparseSet result(maxElements);
        for (int i = 0; i < size; i++) {
            if (other.exist(dense[i])) {
                result.insert(dense[i]);
            }
        }
        return result;
    }

    SparseSet difference(const SparseSet& other) {
        SparseSet result(maxElements);
        for (int i = 0; i < size; i++) {
            if (!other.exist(dense[i])) {
                result.insert(dense[i]);
            }
        }
        return result;
    }
};

#endif // SPARSE_SET_H
