#include <iostream>

using namespace std;

template <typename T>
inline bool check_bit(const T &n, int i){
    return ((n & (1 << i)) != 0);
}

template <typename T>
inline void print_bit_pattern(const T &n){
    for(int i = sizeof(n) * 8 - 1;i >= 0;i--)
        cout << (check_bit(n,i) ? '1' : '0') << (i % 4 == 0? " " : "");
}

int main() {
    float n_float = -1.5;
    int n_int = *(int *) &n_float;
    // Type Punning (https://en.wikipedia.org/wiki/Type_punning)
    // &n_float -> takes memory address of n_float
    // (int *) &n_float  -> treats the memory location as integer
    // *(int *) &n_float -> de-referenced the memory location as integer
    // this makes copies the bits of float in an integer
    // as in C/C++ bitwise operation can only occur in int (or shot or long ..)
    // this hack allows to show bit pattern of float
    cout << n_float << " in IEEE754 Format => ";
    print_bit_pattern(n_int);
    // 1011 1111 1100 0000 0000 0000 0000 0000
    return 0;
}
