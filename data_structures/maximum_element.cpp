//Maximum Element

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;


int main() {
    int N;
    vector< int > stack;
    vector< int > max_stack;
    cin >> N;
    while(N--){
        int q;
        cin >> q;
        if(q == 1){
            int v;
            cin >> v;
            stack.push_back(v);
            if(max_stack.size() == 0 || max_stack.back() <= v) max_stack.push_back(v);
        } else if(q == 2){
            if(max_stack.back() == stack.back()) max_stack.pop_back();
            stack.pop_back();
        } else {
            cout << max_stack.back() << "\n";
        }
    }
    return 0;
}
