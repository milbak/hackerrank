// Jumping on the clouds

#include <iostream>
using std::cin;
using std::cout;

int main(){
    int n, counter = 0,  i = 0, a, b;
    cin >> n;
    cin.ignore(256, ' ');
    cin >> a >> b;
    while(i < n-2){
        if(b == 0){
            i+=2;
            ++counter;
            cin >> a >> b;
        } else {
            ++i;
            ++counter;
            a = b; 
            cin >> b;
        }
    }
    if(i + 1 != n) counter++;
    cout << counter;
    return 0;
}
