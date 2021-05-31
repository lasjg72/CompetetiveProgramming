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
    vector<vector<int>> s(m);
    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int now;
            cin >> now;
            now--;
            s[i].push_back(now);
        }
    }
    vector<int> p(m);
    for(int i = 0; i < m; i++){
        cin >> p[i];
    }
    int ans = 0;   
    for(int bit = 0; bit < (1<<n); bit++){
        //cout << "-----" << endl;
        vector<int> pnum(m, 0);
        bool suc = true;
        for(int i = 0; i < n; i++){
            if(bit & (1<<i)){
                for(int j = 0; j < m; j++){
                    for(int v: s[j]){
                        // cout << "v: " << v << endl;
                        // cout << "i: " << i << endl;
                        if(v == i) pnum[j]++;
                    }
                }
            }
        }
        for(int i = 0; i < m; i++){
            //cout << "pnum: " << pnum[i] << endl;
            //cout << "p: " << p[i] << endl;
            if(pnum[i]%2 != p[i]) suc = false; 
        }
        //cout << "suc: " << suc << endl;
        if(suc) ans++;
    }
    cout << ans << endl;
    return 0;
}
