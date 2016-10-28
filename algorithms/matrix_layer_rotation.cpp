// matrix layer rotation
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;

void tracker(int &c, int i, int C){
    if(C%2 == 0){
            if(i < C/2 - 1) c++;
            else if(i >= C/2)c--;
        } else {
            if(i < C/2) c++;
            else c--;
        }
}

int main() {
    int N, M, R;
    cin >> N >> M >> R;
    vector< vector<unsigned> > G;
    int len = M, wid = N;
    int lay_sz = 2*len + 2*wid - 4;
    while(lay_sz > 0){
        vector<unsigned>v(lay_sz);
        G.push_back(v);
        len-=2;
        wid-=2;
        lay_sz = 2*len + 2*wid - 4;
    }
    int layer = 0;
    for(int i = 0; i < N; i++){
        int count = 0;
        for(int j = 0; j < M; j++){
            
            int l = std::min(layer,count);
            
            int pos;

            if(i == l || j == M - 1 - l){
                pos = (i+j) - 2*l;
            } else {
                pos = G[l].size() - ((i+j) - 2*l);
            }
            
            cin >> G[l][(pos + R*G[l].size() - R)%G[l].size()];
            //cout << "("<< l <<"," <<pos<<")\t";
            tracker(count, j, M);
        }
        //cout << std::endl;
        tracker(layer, i, N);
    }
    
    
    int lay = 0;
    for(int i = 0; i < N; i++){
        int count = 0;
        for(int j = 0; j < M; j++){
            int l = std::min(lay,count);
            int pos;

            if(i == l || j == M - 1 - l){
                pos = (i+j) - 2*l;
            } else {
                pos = G[l].size() - ((i+j) - 2*l);
            }

            cout << G[l][pos] << " ";
            tracker(count, j, M);
        }
        tracker(lay,i,N);
        cout << std::endl;
    }
    
    return 0;
}
