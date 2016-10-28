// absolute permutation

#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, N, K;
    scanf("%d", &T);
    //int NUMBER = T;
    while(T--){
        //printf("TEST %d: \n", NUMBER - T);
        scanf("%d %d", &N, &K);
        //printf("N: %d\nK: %d\n", N, K);
        vector<int> v(N,0);
        bool flag = true;
        for(int i = 1; i <= N; ++i){
            if(!v[i - 1]){
                if(i - 1 + K >= N){
                    flag = false;
                    break;
                }
                v[i - 1] = i + K;
                v[i - 1 + K] = i;
            } 
        }
        if(flag)
            for(int i = 0; i < N; ++i) printf("%d ", v[i]);
        else
            printf("-1");
               
        printf("\n");
    }
    return 0;
}
