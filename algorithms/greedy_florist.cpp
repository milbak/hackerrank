// Greedy Florist
#include<iostream>
#include<algorithm>

int main(void){
    int N, K;
    std::cin >> N >> K;
    int C[N];
    for(int i = 0; i < N; i++){
        std::cin >> C[i];
    }

    std::sort(C,C+N,std::greater<int>());
    int result = 0, cnt = 0;
    for(int i = 0; i < N; i++){
        result += C[i]*(cnt/K + 1);
        cnt++;
    }
    
    
    std::cout << result << std::endl;  
    return 0;
}
