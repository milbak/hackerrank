//Max perimeter triangle

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector <int> v;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int i = n - 3;
    while(i >= 0 && v[i] + v[i+1] <= v[i+2]) i--;
    
    if(i >= 0){
        cout << v[i] << " " << v[i+1] << " " << v[i+2];
    } else {
        cout << -1;
    }
    
    
    return 0;
}
