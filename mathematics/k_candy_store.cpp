// K candy store

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
#define MOD 1000000000ULL
#define SIZE 1001

void populate(int (&ncr)[SIZE][SIZE]){
    ncr[1][0] = 1;
    ncr[1][1] = 1;
    for(int i = 2; i < SIZE; i++){
        ncr[i][0] = 1;
        ncr[i][i] = 1;
        for(int j = 1; j < i; j++){
            ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
        }
    }
}


int main() {
    int T;
    int ncr[SIZE][SIZE];
    populate(ncr);
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;
        cout << ncr[N + K - 1][N - 1] << std::endl;
    }
    return 0;
}
