// larry's array

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;


int main() {
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> a(N);
        for(int i = 0; i < N; i++){
            cin >> a[i];
        }
        int count = 0;
        for(int i = 0; i < N; i++){
            for(int j = i; j < N; j++){
                if(a[i]>a[j]) count++;
            }
        }
        bool flag = !(count %  2);
        cout << ((flag) ? "YES" : "NO") << std::endl;
    }
    
    return 0;
}
