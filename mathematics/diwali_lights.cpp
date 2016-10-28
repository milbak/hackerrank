// diwali lights

#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

int main() {
    int T;
    cin >> T;
    while(T--){
        unsigned N, val = 1;
        cin >> N;
        
        for(unsigned i = 0; i < N; i++){
            val *= 2;
            val = val%100000;
        }
        cout << val-1 << std::endl;
    }
    return 0;
}
