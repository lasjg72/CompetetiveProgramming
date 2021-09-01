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
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(2*n);
    ll ans = 0;
    for(int i = 0; i < 2*n; i++) cin >> a[i];
    vector<int> now = a;
    for(int i = 0; i < n; i++){
        int can = 1001001001;
        int p;
        for(int i = 0; i < now.size()-1; i++){
            if(can > abs(now[i]-now[i+1])){
                can = abs(now[i]-now[i+1]);
                p = i;  
            }
        }
        ans += can;
        
        a.resize(0);
        for(int i = 0; i < now.size(); i++){
            if(i == p || i == p+1) continue;
            a.push_back(now[i]);
        }
        now.resize(0);
        for(int i = 0; i < a.size(); i++){
            now.push_back(a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}