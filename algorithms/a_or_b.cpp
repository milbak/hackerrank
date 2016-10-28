// a or b

#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <bitset>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stringstream;
using std::bitset;

vector<bitset<4>> bitVec(string s){
    vector<bitset<4>> v;
    for(int i = 0; i < s.size(); i++){
        stringstream ss;
        unsigned n;
        ss << std::hex << s[i];
        ss >> n;
        bitset<4> b(n);
        v.push_back(n);
    }
    return v;
}

void printBits (vector<bitset<4>> v){
    for(int i = 0; i < v.size(); ++i){
        cout << v[i].to_string() << " ";
    }
    cout << endl;
}

void printHex (vector<bitset<4>> v){
    bool noleading = v[0][0];
    for(int i = 0; i < v.size(); ++i){
        unsigned n = (unsigned)v[i].to_ulong();
        if(n) noleading = true;
        if(noleading) cout << std::hex << std::uppercase << n; 
    }
    if(!noleading) cout << '0';
    cout << endl;
}

int main() {
    unsigned int Q, K;
    string a, b, c;
    cin >> Q;
    while(Q--){
        int count = 0;
        bool failed = false;
        cin >> K;
        cin >> a >> b >> c;
        vector<bitset<4>> A = bitVec(a), 
                          B = bitVec(b), 
                          C = bitVec(c),
                          AA, BB;
        
        //printBits(A);
        //printBits(B);
        
        std::reverse(A.begin(),A.end());
        std::reverse(B.begin(),B.end());
        std::reverse(C.begin(),C.end());
        for(int i = 0; i < C.size(); i++){
            bitset<4> ai = { 0}, bi;
            if(i < A.size()) ai = A[i];
            if(i < B.size()) bi = B[i];
            
            for(int bit = 0; bit < 4; bit++){
                if(C[i][bit] != (ai[bit] || bi[bit])){
                    if(C[i][bit]){
                        bi[bit] = 1;
                        ++count;
                    } else {
                        if(ai[bit]){
                            ai[bit] = 0;
                            ++count;
                        }
                        if(bi[bit]){
                            bi[bit] = 0;
                            ++count;
                        }
                    }
                }
            }
            
            if(count > K) {
                failed = true;
                break;
            }
            AA.push_back(ai);
            BB.push_back(bi);
        }
        //cout << "PRECOUNT: " << count <<endl;
        std::reverse(A.begin(),A.end());
        std::reverse(B.begin(),B.end());
        std::reverse(AA.begin(), AA.end());
        std::reverse(BB.begin(), BB.end());
        std::reverse(C.begin(), C.end());
        if(count < K){
            for(int i = 0; i < AA.size(); i++){
                for(int bit = 3; bit >= 0; bit--){
                    //cout << "A: " << AA[i][bit] << ", B: " << BB[i][bit] << endl; 
                    if(AA[i][bit]==1 && BB[i][bit] == 0 && count < K - 1){
                        //cout << "flip\n";
                        AA[i][bit] = 0;
                        BB[i][bit] = 1;
                        count += 2;
                    } else if(AA[i][bit] == 1 && BB[i][bit] == 1){
                        AA[i][bit] = 0;
                        ++count;
                    } 
                    //cout << i << ", "<<bit  <<" - COUNT: " << count <<endl;
                    if(count == K) break;
                }
                if(count == K) break;
            }
        }       
        
        if(failed){
            cout << "-1" << endl;
        } else {  
            //cout << "FINALCOUNT: " << count <<endl;
            printHex(AA);
            printHex(BB);
            //printBits(C);
        }
    }
    return 0;
}
