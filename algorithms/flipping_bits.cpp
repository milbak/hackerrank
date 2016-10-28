// Flipping bits
#include <iostream>


int main() {  
    unsigned int x;
    std::cin >> x;
    while(std::cin >> x)
        std::cout << ~x << std::endl;
    return 0;
}
