// equal stacks
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
std::stack<int> reverseStack(std::stack<int> stackIn) { 
    std::stack<int> tmp = stackIn; 
    std::stack<int> out; 
    while(!tmp.empty()) { 
        out.push(tmp.top() 
                ); 
        tmp.pop(); 
    } 
    return out; 
}
int main(){ 
    int n1; int n2; int n3;
    std::stack<int> stack1;
    std::stack<int> stack2;
    std::stack<int> stack3;

    int height1 =0;
    int height2 = 0;
    int height3= 0;

    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
       cin >> h1[h1_i];
        height1 += h1[h1_i];
        stack1.push(h1[h1_i]);
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
       cin >> h2[h2_i];
         height2 += h2[h2_i];
        stack2.push(h2[h2_i]);
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
       cin >> h3[h3_i];
         height3 += h3[h3_i];
        stack3.push(h3[h3_i]);
    }

    stack1 = reverseStack(stack1);
    stack2 = reverseStack(stack2);
    stack3 = reverseStack(stack3);

    while(height1 != height2 && height1 != height3)
        {

    while(height1 != height2) 
    {
        if(height1 > height2)
        {
            int height = stack1.top();
            stack1.pop();
            height1 -= height;
        }
        else
        {
            int height = stack2.top();
            stack2.pop();
            height2 -= height;
        }


    }
    while(height1 != height3)
    {
        if(height1 > height3)
        {
            int height = stack1.top();
            stack1.pop();
            height1 -= height;
        }
        else
        {
            int height = stack3.top();
            stack3.pop();
            height3 -= height;
        }
    }
       while(height2 != height3)
    {
        if(height2 > height3)
        {
            int height = stack2.top();
            stack2.pop();
            height2 -= height;
        }
        else
        {
            int height = stack3.top();
            stack3.pop();
            height3 -= height;
        }
    }
    }
    cout << height1 <<endl;

    return 0;
}