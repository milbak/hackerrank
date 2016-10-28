// Manasa and factorials
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int check(long long int p, long long int n){
    long long int tmp = p, outp = 0, five = 5;
    while(five<tmp){
        outp += tmp/five;
        five = five*5;
    }
    if(outp>=n){
        return 1;
    } else {
        return 0;
    }
}


int main() {
    int t;
    scanf("%d",&t);
    
    while(t--){
        long long int n;
        scanf("%lld",&n);
        
        if(n==1){
            printf("5\n");
            continue;
        }
        
        long long int low = 2;
        long long int high = 5*n;
        
        while(low < high){
            long long int mid = (low+high)/2;
        
            if(check(mid,n)){
                high = mid;
            } else {
                low = mid+1;
            }
        }
        printf("%lld\n",low);
        
    }
    
    
    return 0;
}
