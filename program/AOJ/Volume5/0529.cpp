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
    while(1){
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        vector<int> p(n);
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        vector<int> cur;
        for(int i = 0; i < n; i++){
            cur.push_back(p[i]);
            for(int j = i; j < n; j++){
                cur.push_back(p[i]+p[j]);
            }
        }
        int ans = 0;
        sort(cur.begin(), cur.end());
        for(int now : cur){
            int l = 0, r = cur.size()-1;
            while(r-l>1){
                int mid = (l+r)/2;
                if(now+cur[mid] > m){
                    r = mid;
                }else{
                    l = mid;
                }
            }
            if(m >= now+cur[l]) ans = max(ans, now+cur[l]);
        }
        cout << ans << endl;
    }
    return 0;
}