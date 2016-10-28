// flatland space stations
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::cin;
using std::cout;
using std::vector;


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> M(m);
    for(int i = 0; i < m; ++i){
        cin >> M[i];
    }
    
    std::sort(M.begin(),M.end());
    
    int max = 0;
    for(int i = 1; i < M.size(); ++i){
        int test = (M[i] - M[i-1])/2;
        if(max < test) max = test;
    }
    if(M[0] > max && M[0] != 0) max = M[0];
    if((n - 1) - M.back() > max) max = n - 1 - M.back();
    
    cout << max;
    return 0;
}
