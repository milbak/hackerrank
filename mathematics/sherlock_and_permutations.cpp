// sherlock and permutations
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
typedef unsigned long long ull;

#define P 1000000007ULL

ull ppow(ull n, ull e){
    ull r = 1;
    while (e > 0) {
        if (e % 2 == 1) r = (r * n) % P;
        n = (n * n) % P;
        e /= 2;
    }
    return r;
}

int main() {
    int T;
    cin >> T;
    while(T--){
        ull N, M, ans = 1;
        cin >> N >> M;
        M--;
        ull num = 1;
        for(ull i = 1; i <= N+M; i++){
            num = ((num%P)*(i%P))%P;
        }
        
        ull fM = 1;
        
        for(ull i = 1; i <= M; i++){
            fM = ((fM%P)*(i%P))%P;
        }
        
        ull fN = 1;
        
        for(ull i = 1; i <= N; i++){
            fN = ((fN%P)*(i%P))%P;
        }

        
        ull den = (fN*fM)%P;
        
        ans = (num*ppow(den,P-2))%P;
        
        
        cout << ans << std::endl;
    }
    
    return 0;
}
