#include "src/sparse_set.h"
#include "src/hash_set.h"
#include "src/bit_vector.h"
#include <chrono>
#include <random>

//#include <iostream>
#include <string>

using namespace std;
using namespace std::chrono;
void testSpaceSparseSet(int size){
    for (volatile int i = 0; i < 100000000; ++i);
    SparseSet sparseSet(size);
    for (volatile int i = 0; i < 100000000; ++i);
}
void testSpaceBitVector(int size){
    for (volatile int i = 0; i < 100000000; ++i);
    BitVector bitVector(size);
    for (volatile int i = 0; i < 100000000; ++i);
}
void testSpaceHashSet(int size){
    for (volatile int i = 0; i < 100000000; ++i);
    HashSet<int> hs;
    for (int i = 0; i < size; ++i) {
        hs.insert(i);
    }
    for (volatile int i = 0; i < 100000000; ++i);
}

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

    cout <<  duration.count() << endl;

    auto start1 = high_resolution_clock::now();

    for(int i = 0; i < size; i++) {
        int num = distrib(gen);
        bitVector.insert(num);
        bitVector.eliminar(num);
        bitVector.member(num);
    }

    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout <<  duration1.count() << endl;
    auto start2 = high_resolution_clock::now();


    for(int i = 0; i < size; i++) {
        int num = distrib(gen);
        hashSet->insert(num);
        hashSet->remove(num);
        hashSet->find(num);
    }

    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout <<  duration2.count() << endl;
    delete hashSet;

}

void testIntersectHashSet(int size, int insertions){


    HashSet<int> *hashSet1 = new HashSet<int>;
    HashSet<int> *hashSet2 = new HashSet<int>;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, insertions - 1);

    for(int i = 0; i < insertions; i++) {
        int num = distrib(gen);
        hashSet1->insert(num);
        hashSet2->insert(num);
    }

    auto start = high_resolution_clock::now();

    HashSet<int> *hashSet3 = hashSet1->intersection(hashSet2);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << duration.count() << endl;

    delete hashSet1;
    delete hashSet2;
    delete hashSet3;
}

void testUnionHashSet(int size, int insertions){

    HashSet<int> *hashSet1 = new HashSet<int>;
    HashSet<int> *hashSet2 = new HashSet<int>;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, insertions - 1);

    for(int i = 0; i < insertions; i++) {
        int num = distrib(gen);
        hashSet1->insert(num);
        hashSet2->insert(num);
    }

    auto start = high_resolution_clock::now();

    HashSet<int> *hashSet3 = hashSet1->unionSet(hashSet2);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout <<  duration.count()<< endl;

    delete hashSet1;
    delete hashSet2;
    delete hashSet3;
}
void testDifferenceHashTable(int size, int insertions){


        HashSet<int> *hashSet1 = new HashSet<int>;
        HashSet<int> *hashSet2 = new HashSet<int>;

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, insertions - 1);

        for(int i = 0; i < insertions; i++) {
            int num = distrib(gen);
            hashSet1->insert(num);
            hashSet2->insert(num);
        }

        auto start = high_resolution_clock::now();

        HashSet<int> *hashSet3 = hashSet1->difference(hashSet2);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout <<  duration.count()  << endl;

        delete hashSet1;
        delete hashSet2;
        delete hashSet3;

}

void testIntersectSparseSet(int size, int insertions){


    SparseSet sparseSet1(size);
    SparseSet sparseSet2(size);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, insertions - 1);

    for(int i = 0; i < insertions; i++) {
        int num = distrib(gen);
        sparseSet1.insert(num);
        sparseSet2.insert(num);
    }

    auto start = high_resolution_clock::now();

    SparseSet sparseSet3 = sparseSet1.intersection(sparseSet2);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout  << duration.count() <<  endl;

}

void testUnionSparseSet(int size, int insertions){


    SparseSet sparseSet1(size);
    SparseSet sparseSet2(size);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, insertions - 1);

    for(int i = 0; i < insertions; i++) {
        int num = distrib(gen);
        sparseSet1.insert(num);
        sparseSet2.insert(num);
    }

    auto start = high_resolution_clock::now();

    sparseSet1.unionSet(sparseSet2);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << duration.count() << endl;

}
void testDifferencSparseSet(int size, int insertions){


        SparseSet sparseSet1(size);
        SparseSet sparseSet2(size);

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, insertions - 1);

        for(int i = 0; i < insertions; i++) {
            int num = distrib(gen);
            sparseSet1.insert(num);
            sparseSet2.insert(num);
        }

        auto start = high_resolution_clock::now();

        SparseSet sparseSet3 = sparseSet1.difference(sparseSet2);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << duration.count() << endl;

}

void testIntersectBitVector(int size, int insertions){


    BitVector bitVector1(size);
    BitVector bitVector2(size);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, insertions - 1);

    for(int i = 0; i < insertions; i++) {
        int num = distrib(gen);
        bitVector1.insert(num);
        bitVector2.insert(num);
    }

    auto start = high_resolution_clock::now();

    BitVector bitVector3 = BitVector::intersect(bitVector1, bitVector2);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << duration.count() << endl;
}

void testUnionBitVector(int size, int insertions){


    BitVector bitVector1(size);
    BitVector bitVector2(size);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, insertions - 1);

    for(int i = 0; i < insertions; i++) {
        int num = distrib(gen);
        bitVector1.insert(num);
        bitVector2.insert(num);
    }

    auto start = high_resolution_clock::now();

    BitVector::unionset(bitVector1, bitVector2);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << duration.count() << endl;
}

void testDifferenceBitVector(int size, int insertions){

        BitVector bitVector1(size);
        BitVector bitVector2(size);

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, insertions - 1);

        for(int i = 0; i < insertions; i++) {
            int num = distrib(gen);
            bitVector1.insert(num);
            bitVector2.insert(num);
        }

        auto start = high_resolution_clock::now();

        BitVector bitVector3 = BitVector::difference(bitVector1, bitVector2);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << duration.count() << endl;

}
void testClearSparseSet(int size){

        SparseSet sparseSet(size);

        auto start = high_resolution_clock::now();

        sparseSet.clear();

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);

        cout << duration.count() << endl;


}
void testClearBitVector(int size){

        BitVector bitVector(size);

        auto start = high_resolution_clock::now();

        bitVector.clearAll();

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);

        cout << duration.count() << endl;


}
void testClearHashTable(int size){
    HashSet<int> hashSet;
    for (int i = 0; i < size; ++i) {
        hashSet.insert(i);
    }

    auto start = high_resolution_clock::now();
    hashSet.clearSet();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << duration.count() << " ";
}
void testAll(int size, int insertions){
//    testBasics(size);

//    testUnionSparseSet(size, insertions);
//    testUnionBitVector(size, insertions);
//    testIntersectSparseSet(size, insertions);
//    testIntersectBitVector(size, insertions);
//    testDifferencSparseSet(size, insertions);
//    testDifferenceBitVector(size, insertions);
//    testClearSparseSet(size);
//    testClearBitVector(size);
//    testClearHashTable(size);
}
void spaceTestDifference(){
    int size = 500;
    int insertions = 100;
    SparseSet sparseSet1(size);
    SparseSet sparseSet2(size);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, insertions - 1);

    for(int i = 0; i < insertions; i++) {
        int num = distrib(gen);
        sparseSet1.insert(num);
        sparseSet2.insert(num);
    }

    auto start = high_resolution_clock::now();

    SparseSet sparseSet3 = sparseSet1.difference(sparseSet2);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << duration.count() << endl;
}

//g++ -g -o main main.cpp
//valgrind --leak-check=full ./main
//valgrind --tool=massif --stacks=yes --massif-out-file=massif.out ./main
//ms_print massif.out


//int main(int argc, char** argv){
int main(){
//    testAll(500, 100); // 6230016 bytes
//    testAll(5000, 100);
//    testAll(50000, 100);
//    testAll(500000, 100);
//    testAll(5000000, 100);

//    if (argc != 2) {
//        std::cerr << "Uso: " << argv[0] << " <tamaño>" << std::endl;
//        return 1;
//    }
//    int size = std::stoi(argv[1]);
    testSpaceHashSet(5000);
//    testSpaceBitVector(500);

    return 0;
}
