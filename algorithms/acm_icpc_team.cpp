// acm icpc team
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using std::cin;
using std::cout;
using std::vector;
using std::string;

int main(){
    int n, m, max = 0;
    cin >> n >> m;
    vector< vector< bool >> v(n,vector<bool>(m));
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        for(int s = 0; s < m; s++){
            v[i][s] = tmp[s] - '0';
        }
    }

    std::map<int, vector<std::pair<int, int>>> M;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int val = 0;
            for(int k = 0; k < m; k++){
                val += v[i][k] | v[j][k];
            }
            if(val > max){
                max = val;
                vector< std::pair<int, int> > a;
                a.push_back(std::pair<int, int>(i,j));
                M.insert(std::map<int,vector<std::pair<int, int>>>::value_type(val,a));
            } else if(val == max){
                M[val].push_back(std::pair<int, int>(i,j));
            }
        }
    }
    if(max == 0){
        cout << max << std::endl << n;
    } else {
        cout << max << std::endl << M[max].size();
    }
    return 0;
}
