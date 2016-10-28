//quicksort 1 - partition
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void partition(vector <int>  ar) {
    vector<int> lo,hi,eq;
    for(int i = 0; i < ar.size(); i++){
        if(ar[i] < ar[0]) 
            lo.push_back(ar[i]);
        else if(ar[i] > ar[0]) 
            hi.push_back(ar[i]);
        else 
            eq.push_back(ar[i]);
    }
    for(vector<int>::iterator it = lo.begin(); it != lo.end(); it++) cout << *it << " ";
    for(vector<int>::iterator it = eq.begin(); it != eq.end(); it++) cout << *it << " ";
    for(vector<int>::iterator it = hi.begin(); it != hi.end(); it++) cout << *it << " ";  
}
int main(void) {
   vector <int>  _ar;
   int _ar_size;
   cin >> _ar_size;
    
     for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }

   partition(_ar);
   
   return 0;
}
