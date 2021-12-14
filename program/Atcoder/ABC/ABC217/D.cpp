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
    int L, q;
    cin >> L >> q;
    set<int> pos;
    pos.insert(0);
    pos.insert(L);
    while(q--){
        int c, x;
        cin >> c >> x;
        if(c == 1){
            pos.insert(x);
        }else{
            auto l = pos.lower_bound(x);
            cout << *l-*(--l) << endl;
        }
    }
    return 0;
}