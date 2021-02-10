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
    int n;
    cin >> n;
    map<int, int> d;
    vector<int> a(n), b(n);
    vector<vector<int>> to;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        d[a[i]]++;
        d[b[i]]++;
        // to[a[i]].push_back(b[i]);
        // to[b[i]].push_back(a[i]);
    }
    set<pair<int, int>> s;
    int ans = 0;
    map<int, int> x;
    for(int i = 0; i < n; i++){
        if(d[a[i]] <= d[b[i]]){
            if(x[a[i]] == 0){
                x[a[i]]++;
                d[b[i]]--;
                ans++;
                //
                //d[a[i]]--;
            }else if(x[b[i]] == 0){
                x[b[i]]++;
                d[a[i]]--;
                ans++;
                //
                //d[b[i]]--;
            }
        }else{
            if(x[b[i]] == 0){
                x[b[i]]++;
                d[a[i]]--;
                ans++;
                //
                //d[b[i]]--;
            }else if(x[a[i]] == 0){
                x[a[i]]++;
                d[b[i]]--;
                ans++;
                //
                //d[a[i]]--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}