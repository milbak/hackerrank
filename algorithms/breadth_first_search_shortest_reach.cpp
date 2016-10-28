// breadth first search: shortest reach
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>


int main() {  
    int N, M, T, S;
    
    //read test cases
    std::cin >> T;
    
    while(T--){
        //read nodes (N) and edges (M)
        std::cin >> N >> M;
        std::vector< std::vector<bool> > graph(N, std::vector<bool>(N));
        //decrement N and M for indexes;
        N--; M--;

        for(int i = 0; i <= N; i++){
            //iterate over nodes
            fill(graph[i].begin(), graph[i].end(), false);
            
        }
           

        for(int i = 0; i <= M; i++){
            //iterate over edges
            int x, y;
            std::cin >> x >> y;
            x--; y--;
            graph[x][y] = true;
            graph[y][x] = true;
        }
            
            
        //read starting poing
        std::cin >> S;
        //decrement S for index
        S--;
        std::queue<int> q;
        
        //initialize the distances to S
        std::vector<int> dS(N+1);
        fill(dS.begin(),dS.end(), -1);
        q.push(S);
        //d(S,S) = 0
        dS[S] = 0;
        //BFS loop
        while(!q.empty()){
            //get value from queue
            int curr = q.front();
            q.pop();
            
            //iterate over nodes
            for(int i = 0; i <= N; i++){
                //check if node is connected to current, and if node hasn't been tested
                if(graph[curr][i] && dS[i] == -1){
                    //set distance for node
                    dS[i] = dS[curr] + 1;
                    //add node to 
                    q.push(i);
                }
            }
            
        }
        
        //display
        for(int i = 0; i <= N; i++){
            if(i == S) continue;
            int v = (dS[i] == -1) ? -1 : dS[i] * 6;
            std::cout << v << " ";
        }

        std::cout << std::endl;
    }
    return 0;
}
