// Summing the N series

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;

typedef unsigned long long ull;
    
#define MOD 1000000007
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int T;
    ull n;
    cin >> T;
    while(T--){
        cin >> n;
        cout << ((n%MOD)*(n%MOD))%MOD << std::endl;
    }
    return 0;
}
