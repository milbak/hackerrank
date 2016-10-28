// almost sorted
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned n;
    cin >> n;
    vector<unsigned> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    int first = 0, second = 0, count = 0, i = 0;
    bool done = false;
    while(i < n - 1){
        if(v[i] > v[i+1]){
            if(!done) {
                first = i;
                while(v[first] > v[i+1] && i < n - 1){
                    i++;
                    if(v[i] > v[i+1]) count++;    
                }
                second = i;
                if(second - first -1 != count && count > 1){
                    cout << "no\n";
                    return 0;
                }
                done = true; 
            } else {
				cout << "no\n";
				return 0;
			}
        }
        ++i;
    }
    
    if(!done){
        cout << "no\n";
        return 0;
    }
    
    if(count > 1){
        if((first && second < n - 1 && v[first] <= v[second + 1] && v[first] >= v[first + 1] && v[second] >= v[first - 1] && v[second] <= v[second - 1]) || (first == 0 && second < n - 1 && v[first] >= v[first + 1] && v[first] <= v[second+1] && v[second] <= v[second - 1]) || (first && second == n - 1 && v[first] >= v[first + 1] && v[second] <= v[second - 1] && v[second] >= v[first - 1]) || (first == 0 && second == n - 1 && v[first] >= v[first + 1] && v[second] <= v[second - 1])) {
            cout << "yes\n" <<((count > 1) ? "reverse " : "swap ") << first + 1 << " " << second + 1;
        } else {
            cout << "no\n";
        }
    } else {
        if((first && v[second] >= v[first - 1] && v[second] <= v[first + 1] && second < n - 1 && v[first] <= v[second + 1] && v[first] >= v[second - 1]) || (first == 0 && v[second] <= v[first+1] && second < n - 1 && v[first] <= v[second + 1] && v[first] >= v[second - 1]) || (first && v[second] >= v[first - 1] && v[second] <= v[first + 1] && second == n - 1 && v[first] >= v[second - 1]) || (first == 0 && v[second] <= v[first+1] && second == n - 1 &&  v[first] >= v[second - 1])) {
            cout << "yes\n" <<((count > 1) ? "reverse " : "swap ") << first + 1 << " " << second + 1;
        } else {
            cout << "no\n";
        }
    }
    
    
    
    return 0;
}
