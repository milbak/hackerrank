//Balanced Brackets

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

using namespace std;

string checkBrackets(string s){
    stack<char> left;
    for(int i = 0; i < s.size(); i++){
        switch(s[i]){
            case '(':
            case '{':
            case '[':
                left.push(s[i]);
                break;
            case ')':
                if(left.empty() || left.top() != '('){
                    return "NO\n";
                }
                left.pop();
                break;
            case ']':
                if(left.empty() || left.top() != '['){
                    return "NO\n";
                }
                left.pop();
                break;
            case '}':
                if(left.empty() || left.top() != '{'){
                    return "NO\n";
                }
                left.pop();
                break;
        }
    }
    return (left.empty()) ? "YES\n" : "NO\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << checkBrackets(s);
    }
    return 0;
}
