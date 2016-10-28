// bear and steady gene

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
using std::map;

bool checkCounts(map<char, int> D, int target){
    if(D['A'] <= target &&
       D['C'] <= target &&
       D['G'] <= target &&
       D['T'] <= target){
        return true;
    }
    return false;
}

int main() {
    int N, tail = 0, result = 500000;
    string s;
    
    cin >> N >> s;
    map<char, int> D = {{'A',0},{'C',0},{'G',0},{'T',0}};
    int target = N/4;
    for(int i = N - 1; i >= 0; i--){
        D[s[i]]++;
        if(!checkCounts(D,target)){
            tail = i + 1;
            D[s[i]]--;
            break;
        }
    }
    
    for(int head = -1; head < N - 1 && tail < N && head < tail; head++){
        while(!checkCounts(D, target) && tail < N){
            D[s[tail]]--;
            tail++;
        } 
        int len = std::max(0, tail - head - 1);
        if(len < result){
            result = len;
        }
        D[s[head + 1]]++;
    }
    cout << result << std::endl;

    return 0;
}
