// camel case

#include <stdio.h>

int main(){
    int count = 1;
    char ch;
    while(scanf("%c", &ch) == 1){
        if(ch >= 'A' && ch <= 'Z') ++count;
    }   
    printf("%d", count);
    return 0;
}
