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
        if (member(i)){
            return;
        }
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
        size_t we=set1.size();
        size_t we2=set2.size();

        size_t maxSize = max(we, we2);

        BitVector result(maxSize);

        for(int i=0;i<maxSize;i++){
            int nuevo=set1.member(i);
            int nuevo2=set2.member(i);

            if(nuevo != 0 || nuevo2 != 0){
                result.insert(i);
            }
        }

        return result;
    }

    static BitVector intersect( BitVector& set1,  BitVector& set2) {
        size_t we = set1.size();
        size_t we2 = set2.size();
        int maxSize = max(we, we2);

        BitVector result(maxSize);

        for (size_t j = 0; j < maxSize; j++) {
            if (set1.member(j) != 0 && set2.member(j) != 0) {
                result.insert(j);
            }
        }

        return result;
    }
    static BitVector difference( BitVector& set1,  BitVector& set2) {
        size_t we = set1.size();
        size_t we2 = set2.size();
        int maxSize = max(we, we2);

        BitVector result(maxSize);

        for (size_t j = 0; j < maxSize; j++) {
            if (set1.member(j) != 0 && set2.member(j) == 0) {
                result.insert(j);
            }
        }

        return result;
    }

};
