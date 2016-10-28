//bigger is greater

#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    scanf("%d", &N);
    while(N--){
        char s[100];
        scanf("%s", s);
        int i = strlen(s) - 1;
        while(i > 0 && s[i - 1] >= s[i]) 
            --i;
        if(i == 0){
            printf("no answer\n");
            continue;
        }
        
        int j = strlen(s) - 1; 
        while(s[j] <= s[i  - 1])
            --j;
        char c = s[j];
        s[j] = s[i - 1];
        s[i - 1] = c;
        j = strlen(s) - 1;
        while(i < j){
            c = s[j];
            s[j] = s[i];
            s[i] = c;
            ++i;
            --j;
        }
        printf("%s\n",s);
    }
    return 0;
}
