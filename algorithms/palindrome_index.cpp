// palindrome index

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::string;

int main() { 
    int T;
    cin >> T;
    while(T--){
        string s;
        bool found = false;
        int index = -1;
        cin >> s;
        for(int i = 0; i <= s.size()/2; i++){
            int j = s.size() - 1 - i;
            //cout << i << ": "<<s[i] << ", " << j << ": " << s[j] << std::endl;
            if(s[i] != s[j]){
                if(!found){
                    bool flag = true;
                    for(int k = i + 1; k <=s.size()/2; k++){
                        int l = s.size() - k; 
                        if(s[k] != s[l]){
                            flag = false;
                            break;
                        }
                    }
                    if(!flag){
                        bool flag2 = true;
                        for(int k = i; k <= s.size()/2; k++){
                            int l = s.size() - 2 - k;
                            if(s[k] != s[l]){
                                flag2 = false;
                                break;
                            }
                        }
                        if(!flag2){
                            index = -1;
                            break;
                        } else {
                            index = j;
                            s.erase(j, 1);
                        }
                    } else {
                        index = i;
                        s.erase(i, 1);
                    }    
                } else {
                    index = -1;
                    break;
                }
            }
        }
        cout << index <<std::endl;
    }
    return 0;
}
