#include <iostream>
#include <random>
using namespace std;

int main() {
    random_device rd;          // entropy source
    mt19937 gen(rd());         // Mersenne Twister PRNG
    uniform_int_distribution<> dist(0, 100);

    cout << "Mersenne Twister Output:\n";
    for (int i = 0; i < 7; i++) {
        cout << dist(gen) << " ";
    }

    return 0;
}
