#include <iostream>
#include <vector>
#include<unordered_set>
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

    int size () {
        return capacity;
    }
    static BitVector unionset( BitVector& set1,  BitVector& set2) {
        size_t we=set1.bv.size();
        size_t we2=set2.bv.size();

        BitVector result(64);

        for(int i=0;i<we;i++){
            int nuevo=set1.find(i);
            result.insert(nuevo);
        }

        for(int j=0;j<we2;j++){
            int nuevo2=set2.find(j);
            result.insert(nuevo2);
        }

        return result;
    }

    static BitVector intersect( BitVector& set1,  BitVector& set2) {
        size_t we = set1.bv.size();
        size_t we2 = set2.bv.size();

        BitVector result(60);


        unordered_set<int> set2_elements;
        for (size_t j = 0; j < we2; j++) {
            set2_elements.insert(set2.find(j));
        }

        for (size_t i = 0; i < we; i++) {
            int nuevo = set1.find(i);
            if (set2_elements.find(nuevo) != set2_elements.end()) {
                result.insert(nuevo);
            }
        }

        return result;
    }

};
