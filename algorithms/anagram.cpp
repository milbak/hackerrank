// anagram
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::string;
using std::vector;
int main() {
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        if(s.size()%2 != 0){
            cout << -1 << std::endl;
            continue;
        }
        vector<int> A(26, 0), B(26, 0);
        for(int i = 0; i < s.size(); i++){
            if(i < s.size()/2){
                A[s[i] - 'a']++;
            } else {
                B[s[i] - 'a']++;
            }
        }
        
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(B[i] > A[i])count += B[i] - A[i];
        }
        cout << count << std::endl;
    }
    return 0;
}
