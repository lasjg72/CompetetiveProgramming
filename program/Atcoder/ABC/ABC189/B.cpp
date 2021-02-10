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
    int n, x;
    cin >> n >> x;
    int tot = 0;
    for(int i = 0; i < n; i++){
        int v, p;
        cin >> v >> p;
        int tmp = v * p;
        tot += tmp;
        //cout << v << endl;
        //cout << tot << endl;
        if(tot > x * 100){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}