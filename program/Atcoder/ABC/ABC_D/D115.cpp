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
vector<ll> a(51), p(51);

ll dfs(int n, ll x){
    // cout << "n: " << n << endl;
    // cout << "x: " << x << endl;
    if(n == 0){
        if(x == 1) return 1;
        else return 0;
    }
    if(x == 1) {
        return 0;
    }
    else if(1 < x && x <= a[n-1]+1) return dfs(n-1, x-1);
    else if(x == a[n-1]+2) return p[n-1]+1;
    else if(a[n-1]+2 < x && x <= 2*a[n-1]+2) return p[n-1]+1+dfs(n-1, x-2-a[n-1]);
    else return 2*p[n-1]+1;
}

int main()
{
    int n;
    ll x;
    cin >> n >> x;
    a[0] = 1;
    p[0] = 1;
    for(int i = 1; i <= n; i++){
        a[i] = 2*a[i-1] + 3;
        p[i] = 2*p[i-1] + 1;  
    }
    cout << dfs(n, x) << endl;
    return 0;
}
