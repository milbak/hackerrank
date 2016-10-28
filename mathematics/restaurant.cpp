// restaurant
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

unsigned int gcd(unsigned int a, unsigned int b){
    int r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned int T, l, b, g;
    std::cin>>T;
    for(int i = 0; i < T; i++){
        std::cin >> l >> b;
        g = l*b/pow(gcd(l,b),2);
        std::cout << g << std::endl;
    }
    return 0;
}
