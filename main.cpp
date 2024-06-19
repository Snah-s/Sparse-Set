#include "src/sparse_set.h"
#include "src/hash_set.h"
#include "src/bit_vector.h"
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

void testBasics(int size){


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

void testIntersectHashSet(int size){


    HashSet<int> *hashSet1 = new HashSet<int>;
    HashSet<int> *hashSet2 = new HashSet<int>;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, size - 1);

    for(int i = 0; i < size; i++) {
        int num = distrib(gen);
        hashSet1->insert(num);
        hashSet2->insert(num);
    }

    auto start = high_resolution_clock::now();

    HashSet<int> *hashSet3 = hashSet1->intersection(hashSet2);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "HashSet Intersection: Total execution time: " << duration.count() << " microseconds" << endl;

    delete hashSet1;
    delete hashSet2;
    delete hashSet3;
}

void testUnionHashSet(int size){

    HashSet<int> *hashSet1 = new HashSet<int>;
    HashSet<int> *hashSet2 = new HashSet<int>;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, size - 1);

    for(int i = 0; i < size; i++) {
        int num = distrib(gen);
        hashSet1->insert(num);
        hashSet2->insert(num);
    }

    auto start = high_resolution_clock::now();

    HashSet<int> *hashSet3 = hashSet1->unionSet(hashSet2);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "HashSet Union: Total execution time: " << duration.count() << " microseconds" << endl;

    delete hashSet1;
    delete hashSet2;
    delete hashSet3;
}
void testDifferenceHashTable(int size){


        HashSet<int> *hashSet1 = new HashSet<int>;
        HashSet<int> *hashSet2 = new HashSet<int>;

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, size - 1);

        for(int i = 0; i < size; i++) {
            int num = distrib(gen);
            hashSet1->insert(num);
            hashSet2->insert(num);
        }

        auto start = high_resolution_clock::now();

        HashSet<int> *hashSet3 = hashSet1->difference(hashSet2);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "HashSet Difference: Total execution time: " << duration.count() << " microseconds" << endl;

        delete hashSet1;
        delete hashSet2;
        delete hashSet3;

}

void testIntersectSparseSet(int size){


    SparseSet sparseSet1(size);
    SparseSet sparseSet2(size);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, size - 1);

    for(int i = 0; i < size; i++) {
        int num = distrib(gen);
        sparseSet1.insert(num);
        sparseSet2.insert(num);
    }

    auto start = high_resolution_clock::now();

    SparseSet sparseSet3 = sparseSet1.intersection(sparseSet2);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "SparseSet Intersection: Total execution time: " << duration.count() << " microseconds" << endl;

}

void testUnionSparseSet(int size){


    SparseSet sparseSet1(size);
    SparseSet sparseSet2(size);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, size - 1);

    for(int i = 0; i < size; i++) {
        int num = distrib(gen);
        sparseSet1.insert(num);
        sparseSet2.insert(num);
    }

    auto start = high_resolution_clock::now();

    SparseSet sparseSet3 = sparseSet1.unionSet(sparseSet2);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "SparseSet Union: Total execution time: " << duration.count() << " microseconds" << endl;

}
void testDifferencSparseSet(int size){


        SparseSet sparseSet1(size);
        SparseSet sparseSet2(size);

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, size - 1);

        for(int i = 0; i < size; i++) {
            int num = distrib(gen);
            sparseSet1.insert(num);
            sparseSet2.insert(num);
        }

        auto start = high_resolution_clock::now();

        SparseSet sparseSet3 = sparseSet1.difference(sparseSet2);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "SparseSet Difference: Total execution time: " << duration.count() << " microseconds" << endl;

}

void testIntersectBitVector(int size){


    BitVector bitVector1(size);
    BitVector bitVector2(size);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, size - 1);

    for(int i = 0; i < size; i++) {
        int num = distrib(gen);
        bitVector1.insert(num);
        bitVector2.insert(num);
    }

    auto start = high_resolution_clock::now();

    BitVector bitVector3 = BitVector::intersect(bitVector1, bitVector2);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "BitVector Intersection: Total execution time: " << duration.count() << " microseconds" << endl;
}

void testUnionBitVector(int size){


    BitVector bitVector1(size);
    BitVector bitVector2(size);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, size - 1);

    for(int i = 0; i < size; i++) {
        int num = distrib(gen);
        bitVector1.insert(num);
        bitVector2.insert(num);
    }

    auto start = high_resolution_clock::now();

    BitVector bitVector3 = BitVector::unionset(bitVector1, bitVector2);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "BitVector Union: Total execution time: " << duration.count() << " microseconds" << endl;
}

void testDifferenceBitVector(int size){

        BitVector bitVector1(size);
        BitVector bitVector2(size);

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, size - 1);

        for(int i = 0; i < size; i++) {
            int num = distrib(gen);
            bitVector1.insert(num);
            bitVector2.insert(num);
        }

        auto start = high_resolution_clock::now();

        BitVector bitVector3 = BitVector::difference(bitVector1, bitVector2);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "BitVector Difference: Total execution time: " << duration.count() << " microseconds" << endl;

}

void testAll(int size){
    testBasics(size);
    testIntersectHashSet(size);
    testUnionHashSet(size);
    testDifferenceHashTable(size);

    testIntersectSparseSet(size);
    testUnionSparseSet(size);
    testDifferencSparseSet(size);

    testIntersectBitVector(size);
    testUnionBitVector(size);
    testDifferenceBitVector(size);
}


int main(){
    testAll(100);
    return 0;
}
