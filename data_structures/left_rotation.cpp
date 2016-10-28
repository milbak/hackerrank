// Left rotation

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;


int main() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[(i + n - d)%n];
    }
    
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
