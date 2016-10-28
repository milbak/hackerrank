// circular array rotation
#include <vector>
#include <iostream>

int main() {
    int n,  k, q, ind;
    std::cin >> n >> k >> q;
    std::vector<int> v(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[(i+k)%n];
    }
    
    for(int i = 0; i < q; i++){
        std::cin >> ind;
        std::cout << v[ind] << "\n";
    }
    return 0;
}
