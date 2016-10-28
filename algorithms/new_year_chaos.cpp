// new year chaos
#include <iostream>
#include <vector>
#include <string>

int main(){
    int T;
    std::cin >> T;
    while(T--){
        int n, bribes = 0;
        bool chaotic = false;
        std::cin >> n;
        std::vector<int> v(n);
        
        for(int i = 0; i < n; i++){
            std::cin >> v[i];
        }
        
        for(int i = n - 1; i >= 0; i--){
            if(v[i] - (i + 1) > 2){
                chaotic = true;
                break;
            }
            int j = (v[i] - 2 > 0) ? v[i] - 2 : 0;
            while(j < i){
                if(v[j] > v[i]) bribes++;
                j++;
            }
        }
        if(chaotic) std::cout << "Too chaotic\n";
        else std::cout << bribes << std::endl;
        
    }
    return 0;
}
