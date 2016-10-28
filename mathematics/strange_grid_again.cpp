// Strange grid again

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;


int main() {
    long r, c;
    cin >> r >> c;
    cout << (r + r%2 - 2)*5 + (r - 1)%2 + 2*(c - 1);
    return 0;
}
