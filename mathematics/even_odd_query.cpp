// even odd query

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, Q;
    cin >> N;
    vector<int> v(N);
    for(int i = 0 ; i < N; i++){
        cin >>  v[i];
    }
    
    cin >> Q;
    while(Q--){
        int x, y;
        cin >> x >> y;

        
        //cout << x << "," << y << ":";
        
        if(x < y && v[x] == 0 ){
            cout << "Odd\n";
        } else if(v[x - 1]%2){
            cout << "Odd\n";
        } else {
            cout << "Even\n";
        }
    }
    
    return 0;
}
