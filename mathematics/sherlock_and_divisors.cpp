// Sherlock and Divisors

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int count = (N+1)%2;
        if(count)
            for(int i = 2; i <= sqrt(N); i++){
                if(N%i == 0 && i%2 == 0) count++;
                if((N/i)!= i && N%(N/i) == 0 && (N/i)%2 == 0)count++;
            }
        cout << count << std::endl;
    }
    return 0;
}
