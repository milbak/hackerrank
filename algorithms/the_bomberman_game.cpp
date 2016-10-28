// the bomberman game
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::max;
using std::min;

void printGrid(vector< vector<int> > G){
    int R = G.size(), C = G[0].size();
    for(int r = 0; r < R; ++r){
        for(int c = 0; c < C; ++c){
            cout << ((G[r][c]) ? 'O' : '.');
        }
        cout << "\n";
    }
}

void place(vector< vector<int> > &G){
    for(int r = 0; r < G.size(); r++){
        for(int c = 0; c < G[r].size(); c++){
            if(!G[r][c]) G[r][c] = 3; 
        }
    }
}


void countdown(vector< vector<int> > &G){ 
    for(int r = 0; r < G.size(); r++){
        for(int c = 0; c < G[r].size(); c++){
            if(G[r][c] > 0){
                --G[r][c];
                if(!G[r][c]){
                    if(c - 1 >= 0) G[r][c - 1] = 0;
                    if(r - 1 >= 0) G[r - 1][c] = 0;
                    if(c + 1 <= G[r].size() - 1 && G[r][c + 1] != 1) G[r][c + 1] = 0;
                    if(r + 1 <= G.size() - 1 && G[r + 1][c] != 1) G[r + 1][c] = 0;
                }
            }
        }
    }
    
};

int main() {
    unsigned long long int N;
    int R, C;
    cin >> R >> C >> N;
    vector< vector<int> > G(R);
    for(int r = 0; r < R; ++r){
        vector<int> g(C);
        for(int c = 0; c < C; ++c){
            char tmp;
            cin >> tmp;
            g[c] = (tmp == '.') ? 0 : 3;
        }
        G[r] = g;
    }
    if(N > 1){
        for(int i = 1; i <= N%4 + 4; ++i){
            countdown(G);
            if(i % 2 == 0) place(G);
        }
    }
    printGrid(G);
    return 0;
}
