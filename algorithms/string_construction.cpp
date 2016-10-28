//string construction

#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    getchar();
    while(n--){
        int count = 0;
        bool az[26] = { 0 };
        char ch = getchar();
        while(ch >= 'a' && ch <= 'z'){
            if( !az[ch - 'a']) {
                az[ch - 'a'] = true;
                count++;
            }  
            ch = getchar();
        }
        printf("%d\n",count);        
    }
    return 0;
}
