#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>

using namespace std;
using ll = long long;

int main()
{
    string x;
    cin >> x;
    stack<char> s;
    for(int i = 0; i < x.length(); i++){

        if(s.empty()) s.push(x[i]);
        else{
            if(x[i] == 'S') s.push(x[i]);
            else if(x[i] == 'T'){
                if(s.top() == 'S') s.pop();
                else s.push(x[i]);
            }
        }
    }
    cout << s.size() << endl;
    return 0;
}