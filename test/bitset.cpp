#include <iostream>
#include <bitset>

using namespace std;

int main() {
    // ビット幅の指定無し
    cout << (16384 << 1) << endl;  // 16384 left-shifted by 1 = 32768
    // ビット幅を 16 に指定
    cout << bitset<16>(16384 << 1) << endl;  // 0b10000000'00000000
    // 2進数から10進数に変換
    cout << bitset<16>(16384 << 1).to_ulong() << endl;  // 16384 left-shifted by 1 = 32768
    cout << endl;

    cout << (4 << 2) << endl;  // 4 left-shifted by 2 = 16
    cout << bitset<16>(4 << 2) << endl;  // 0b00000000'00010000
    cout << bitset<16>(16384 << 1).to_ulong() << endl;  // 4 left-shifted by 2 = 16
    cout << endl;

    cout << (4 << 14) << endl;  // 4 left-shifted by 14 = 65536 (ビット幅の指定無し)
    cout << bitset<16>(4 << 14) << endl;  // 0b00000000'00000000
    cout << bitset<16>(4 << 14).to_ulong() << endl;  // 4 left-shifted by 14 = 0
    // ↑ ビット幅が16だからそれより大きい桁は無視される
    cout << endl;
}