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
    int v, t, s, d;
    cin >> v >> t >> s >> d;
    int st = v * t;
    int vt = v * s;
    if(st <= d && d <= vt){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}