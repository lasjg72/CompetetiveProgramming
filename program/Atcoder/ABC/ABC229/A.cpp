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
    string s, t;
    cin >> s >> t;
    if(s == ".#"){
        if(t == "#."){
            cout << "No" << endl;
            return 0;
        }
    }
    if(s == "#."){
        if(t == ".#"){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
