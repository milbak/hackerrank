// sherlock and anagrams
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::vector;
using std::string;

bool matching(string a, string b){
    if(a.size() != b.size()) return false;
    vector<int> A(26,0), B(26,0);
    for(int i = 0; i < a.size(); i++){
        A[a[i] - 'a']++;
        B[b[i] - 'a']++;
    }   
    for(int i = 0; i < 26; i++){
        if(A[i] != B[i]) return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while(T--){
        string S;
        cin >> S;
        int count = 0;
        for(int i = 0; i < S.size() - 1; i++){
            for(int j = i+1; j < S.size(); j++){
                for(int s = 1; s < S.size() - j + 1; s++){
                    //cout <<S.substr(i,s) << " " <<  S.substr(j,s) << std::endl;
                    count += matching(S.substr(i,s), S.substr(j,s));
                }
            }
        }
        
        cout << count << std::endl;
    }
    return 0;
}
