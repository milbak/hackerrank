// the grid search
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
int main(){
    int t;
    cin >> t; 
    
    while(t--){
        int gr, gc, pr, pc;
        cin >> gr >> gc;
        
        vector<string> g(gr);
        
        for(int i = 0; i < gr; i++){
            cin >> g[i];
        }
       
        cin >> pr >> pc;
        vector<string> p(pr);
       
        for(int i = 0; i < pr; i++){
            cin >> p[i];
        }
       
        bool flag = false;
        for(int i = 0; i < gr; i++){
            for(int j = 0; j < gc; j++){
                if(flag) break;
                if(g[i][j] == p[0][0]){
                    flag = true;
                    for(int r = 0; r < pr; r++){
                        
                        for(int c = 0; c < pc; c++){
                            if(i+r >= gr || j+c >= gc ||p[r][c] != g[i+r][j+c]) {
                                flag = false;
                                break;
                            }           
                        }
                        if(!flag) break;
                        
                    }
                }
                
            }
        }
        cout << ((flag) ? "YES" : "NO") << std::endl;
    }

    return 0;
}
