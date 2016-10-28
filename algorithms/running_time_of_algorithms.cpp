// Running time of algorithms
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MX 1001
using std::cin;
using std::cout;
void insertionSort(int sz, int *  ar) {
    int *begin  = ar;
    int *end    = ar + sz;
    int count = 0;
    for(int *i = begin + 1; i != end; ++i){
        int t = *i;
        for(int *j = i; j >= begin - 1; --j){
            if(j != begin && (*(j - 1) > t)){
                *j = *(j-1);
                count++;
            } else *j = t;
            if(*j == t) break;
        }
    }
    cout << count << std::endl;
}
int main() {
    int arr[MX];
    int N;
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    
    insertionSort(N, arr);
    return 0;
}
