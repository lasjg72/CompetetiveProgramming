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
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int l, r;
        cin >> l >> r;
        ll num = r - 2*l + 1;
        if(num <= 0){
            cout << 0 << endl;
        }else{
        cout << num * (num + 1) / 2 << endl;
        }
    }
    return 0;
}
