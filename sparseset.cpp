#include <iostream>
#include <vector>
using namespace  std;


bool initbv(vector<int>& bv, int val) {
    bv = vector<int>(val / 32 + 1, 0);
    return true;
}

void set(vector<int>& bv, int i) {
    bv[i >> 5] |= (1 << (i & 5));
}

int member(vector<int>& bv, int i) {
    return bv[i >> 5] & (1 << (i & 0x1f));
}
int main() {
    std::vector<int> bitVector;

    initbv(bitVector, 32);

    int s1[] = {32, 5, 0};
    int s2[] = {32, 4, 5, 0};

    for (int i = 0; s1[i]; i++) {
        set(bitVector, s1[i]);
    }

    for (int i = 0; s2[i]; i++) {
        if (member(bitVector, s2[i])) {
            cout << s2[i] << std::endl;
        }
    }
}
