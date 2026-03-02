#include <bits/stdc++.h>

using namespace std;

vector<int> LCG(int &seed, int &mod, int &mul, int &inc)
{
    vector<int> R(7);
    R[0] = seed;
    for (int i = 1; i < 7; i++)
    {
        R[i] = ((R[i - 1] * mul) + inc) % mod;
    }

    return R;
}

int main()
{
    int seed, mod, mul, inc;
    cout << "Enter a seed: ";
    cin >> seed;
    cout << "Enter the mod: ";
    cin >> mod;
    cout << "Enter the Multiplier value: ";
    cin >> mul;
    cout << "Enter the Increment term: ";
    cin >> inc;

    printf("Generating 7 Sudo random numbers with---\nInitial seed: %d\nModulo: %d\nMultilpier: %d\nIncrement Term: %d\n", seed, mod, mul, inc);
    vector<int> Randoms = LCG(seed, mod, mul, inc);

    cout << "Sequence of Random values are: ";

    for (int &r : Randoms)
        printf("%d ", r);

    return 0;
}
