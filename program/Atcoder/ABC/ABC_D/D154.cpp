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
    int n, k;
    cin >> n >> k;
    vector<double> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    double ans = 0;
    int l = 0, r = k-1;
    for(int i = 0; i < k; i++){
        ans += (p[i]+1)/2;
    }
    double now = ans;
    while(r < n){
        now -= (p[l]+1)/2;
        //cout << "now: " << (p[l]+1)/2 << endl;
        r++;
        l++;
        now += (p[r]+1)/2;
        ans = max(now, ans);
    }
    printf("%.7f\n", ans);
    return 0;
}