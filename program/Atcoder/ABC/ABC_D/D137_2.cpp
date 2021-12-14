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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
        p[i].first -= 1;
        //p[i].second *= -1;
    }
    sort(p.begin(), p.end());
    int ans = 0, pos = 0, i = 0;
    priority_queue<int> q;
    for(int i = 0; i < m; i++){
        while(pos < n && p[pos].first == i){
            q.push(p[pos].second);
            pos++;
        }
        if(!q.empty()){
            ans += q.top(); 
            q.pop();
            //cout << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}