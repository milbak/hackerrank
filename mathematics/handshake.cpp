// Handshake

#include <iostream>


using std::cin;
using std::cout;


int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << n*(n-1)/2 << std::endl;
    }
    return 0;
}
