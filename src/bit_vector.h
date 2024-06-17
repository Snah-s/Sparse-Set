#include <iostream>
#include <vector>
using namespace  std;

class BitVector {
private:
    vector<int> bv;
    int capacity;

public:
    BitVector(int val) {
        initbv(val);
    }

    bool initbv(int val) {
        bv = vector<int>(val / 32 + 1, 0);
        capacity = val;
        return true;
    }

    void insert(int i) {
        bv[i >> 5] |= (1 << (i & 0x1f));
    }

    void eliminar(int i) {
        bv[i >> 5] &= ~(1 << (i & 0x1f));
    }


    int member(int i) {
        return bv[i >> 5] & (1 << (i & 0x1f));
    }
    int find(int k) {
        int contador = 0;
        for (int i = 0; i < capacity; ++i) {
            if (member(i)) {
                if (contador == k) {
                    return i;
                }
                contador++;
            }
        }
        return -1; //no se encontro
    }

    void clearAll() {
        fill(bv.begin(), bv.end(), 0);
    }

    int size() {
        return capacity;
    }
};
