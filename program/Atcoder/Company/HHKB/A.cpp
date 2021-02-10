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
    char s, t;
    cin >> s >> t;
    if(s == 'Y'){
        if(t == 'a'){
            cout << 'A' << endl;
        }else if(t == 'b'){
            cout << 'B' << endl;
        }else{
            cout << 'C' << endl;
        }
    }else{
        cout << t << endl;
    }
    return 0;
}