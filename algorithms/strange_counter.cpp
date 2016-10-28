// strange counter

#include <cstdio>
#include <stdint.h>
#include <inttypes.h>
#include <cmath>
#include <algorithm>

int main(){
    uint64_t t, counter = 3, m = 1;
    scanf("%" PRIu64 "",&t);
    uint64_t p = (t+2)/3;
    uint64_t c = 0, d;
    while(p >> 1){
        p = (p >> 1);
        c++; 
    }
    d = 3*pow(2,c);
    uint64_t a = d - (t+2)%d;
    printf("%" PRIu64 "\n", a);
    return 0;
}
