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
    vector<int> t(n);
    vector<P> p(n);
    for(int i = 0; i < n; i++){
        cin >> t[i] >> p[i].first >> p[i].second;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int l = p[i].first, r = p[i].second;
        for(int j = i+1; j < n; j++){
            int nl = p[j].first, nr = p[j].second;
            if(r < nl || nr < l) continue;
            if((l < nl && nl < r) || (l < nr && nr < r) || (nl < l && l < nr) || (nl < r && r < nr)){
                //cout << i << " " << j << endl;
                ans++;
                continue;
            }
            if(nl == r){
                if(t[i] == 1 || t[i] == 3){
                    if(t[j] == 1 || t[j] == 2){
                        ans++;
                        continue;
                    }
                }
            }
            if(nr == l){
                if(t[i] == 1 || t[i] == 2){
                    if(t[j] == 1 || t[j] == 3){
                        ans++;
                        continue;
                    }
                }
            }
            if(nr == r){
                if(t[i] == 1 || t[i] == 3){
                    if(t[j] == 1 || t[j] == 3){
                        ans++;
                        continue;
                    }
                }
            }
            if(nl == l){
                if(t[i] == 1 || t[i] == 2){
                    if(t[j] == 1 || t[j] == 2){
                        ans++;
                        continue;
                    }
                }
            }
            if(nl == l && nr == r) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}