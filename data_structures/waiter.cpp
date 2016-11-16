#include <vector>
#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::vector;
using std::stack;

const vector<int> calcPrimes(int Q){
    vector<int> primes;
    primes.push_back(2);
    
    if(Q < 2) return primes;
    
    int next = 3;
    
    while(primes.size() < Q){
        int i = 0;
        while(i < primes.size()){
            if(next % primes[i] == 0){
                break;
            }
            if(primes[i]*primes[i] > next) {
                primes.push_back(next);
                break;
            }
            i++;
        }
        next += 2;
    }   
    return primes;
}

int main() {
    int N, Q, a;
    cin >> N >> Q;
    const vector<int> primes = calcPrimes(Q);
    stack<int> A;
    vector<stack<int>> B(Q);

    while(cin >> a){
        A.push(a);
    }
    
    for(int i = 0; i < Q; i++){
        stack<int> tmpA;
        while(!A.empty()){
            if(A.top() % primes[i] == 0){
                B[i].push(A.top());  
            } else {
                tmpA.push(A.top());
            }
            A.pop();
        }      
        A = tmpA;
    }

    for(int i = 0; i < Q; i++){
        while(!B[i].empty()){
            cout << B[i].top() << "\n";
            B[i].pop();
        }
    }

    while(!A.empty()){
        cout << A.top() << "\n";
        A.pop();
    }
   
    return 0;
}