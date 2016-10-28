// Reverse game
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::string;
using std::reverse;
using std::vector;

int main() {
    int T;
    cin >> T;
    while(T--){
        int N, K, index = 0;;
        cin >> N >> K;
        if(K < N/2){
            index = 2*K + 1;
        } else {
            index = 2*(N-K) - 2;
        }
        cout << index << std::endl;
    }
    
    return 0;
}
