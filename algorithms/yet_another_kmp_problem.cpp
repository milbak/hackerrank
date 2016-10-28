// yet another kmp problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::swap;

int main() {
    vector<int> A(26);
    int length = 0, min = -1;
    string L;
    for(int i = 0; i < 26; i++){
        cin >> A[i];
        length += A[i];
        if(A[i] > 0){
            char c = 'a' + i;
            L += c;
            if(min < 0 || A[i] < A[min]) min = i;
        }     
    }
    
    string s;
    s += 'a' + min;
    length--;
    A[min]--;
    if(L[0] == 'a' + min){
        while(L.size() > 1 && A[min] && A[L[1]-'a']){
            s+= L[0];
            s+= L[1];
            A[min]--;
            A[L[1]-'a']--;
        }
    }
    
    for(int i = 0; i < L.size(); i++){
        while(A[L[i] - 'a']){
            s += L[i];
            A[L[i] - 'a']--;
        }
    }
    

    cout << s << std::endl;

    
    return 0;
}
