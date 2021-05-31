#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>

using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int num1 = 0, num2 = 0;
    pair<int, int> p;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            p.first++;
        }else{
            if(p.first > 0) p.first--;
            else p.second++;
        }
    }
    for(int i = 0; i < p.second; i++){
        cout << '(';
    }
    cout << s;
    for(int i = 0; i < p.first; i++){
        cout << ')';
    }
    cout << endl;
    return 0;
}