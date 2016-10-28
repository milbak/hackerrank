//beautiful triplets

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int n, d, t = 0,tmp;
    std::cin >> n >> d;
    std::map< int, std::vector<int> > a;
    for(int i = 0; i < d; ++i){
        std::vector<int> v;
        a.insert(std::map< int, std::vector<int> >::value_type(i, v));
    }
    for(int i = 0; i < n; ++i){
        std::cin >> tmp;
        a[tmp % d].push_back(tmp);
    }
    
    for(int i = 0; i < d; ++i){
        int m = a[i].size();
        for(int j = 1; j < m-1; ++j){
            if(a[i][j] - a[i][j - 1] == d && a[i][j+1] - a[i][j] == d)++t;
        }
    }
    
    std::cout << t;
    return 0;
}
