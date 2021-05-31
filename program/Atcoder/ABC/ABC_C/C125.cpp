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

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), g(n+1, 0), g2(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        g[i+1] = gcd(g[i], a[i]);
    }
    for(int i = n-1; i >= 0; i--){
        g2[i] = gcd(g2[i+1], a[i]);
        //cout << g2[i] << endl;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int lgcd = g[i];
        int rgcd = g2[i+1];
        // cout << lgcd << endl;
        // cout << rgcd << endl;
        // cout << "----" << endl;
        ans = max(ans, gcd(lgcd, rgcd));
    }
    cout << ans << endl;
    return 0;
}