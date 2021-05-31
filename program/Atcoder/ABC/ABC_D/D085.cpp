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
    int n, h;
    cin >> n >> h;
    vector<P> p;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        p.push_back({a, 1001001001});
        p.push_back({b, 1});
    }
    sort(p.rbegin(), p.rend());
    int ans = 0, i = 0;
    while(h > 0){
        if(p[i].second == 1001001001){
            if(h % p[i].first == 0){
                ans += h/p[i].first;
                break;
            }else{
                ans += h/p[i].first+1;
                break;
            }
        }
        else {
            ans++;
            h -= p[i].first;
            //cout << h << endl;
            p[i].second--;
            if(p[i].second == 0) i++;
        }
    }
    cout << ans << endl;
    return 0;
}