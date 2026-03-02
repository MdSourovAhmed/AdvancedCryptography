#include <iostream>
#include <cstdint>
using namespace std;

uint32_t rotl(uint32_t x, int n) {
    return (x << n) | (x >> (32 - n));
}

uint32_t chacha_prng(uint32_t &state) {
    state ^= rotl(state, 13);
    state ^= rotl(state, 17);
    state ^= rotl(state, 5);
    return state;
}

int main() {
    uint32_t seed = 0x12345678;

    cout << "ChaCha-style PRNG output:\n";
    for(int i = 0; i < 7; i++) {
        cout << chacha_prng(seed) << " ";
    }

    return 0;
}
