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

vector<vector<ll>> a;

ll bs(int x, int xnum, int y, int ynum){
    ll l = 0, r = 1001001001001001001;
    while(r-l>1){
        ll mid = (l+r)/2;
        for(int i = 0; i < x; i++){
            ll now = a[xnum][i];
            int pos = lower_bound(a[ynum].begin(), a[ynum].end(), now)-a[ynum].begin();
            if(pos == y)){
                if(abs(a[ynum][pos-1]-now) <= mid){
                    r = mid;
                }else{
                    l = mid;
                }
            }else if(pos == 0){
                if(abs(a[ynum][pos]-now) <= mid){
                    r = mid;
                }else{
                    l = mid;
                }
            }else if(pos = y-1){
                if(abs(a[ynum][pos-1]-now) <= mid){
                    r = mid;
                }else{
                    l = mid;
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    a.resize(3);
    for(int i = 0; i < 2*n; i++){
        ll na;
        char c;
        cin >> na >> c;
        if(c == 'R'){
            a[0].push_back(na);
        }else if(c == 'G'){
            a[1].push_back(na);
        }else{
            a[2].push_back(na);
        }
    }
    int n0 = a[0].size(), n1 = a[1].size(), n2 = a[2].size();
    if(n0%2 == 0 && n1%2==0 && n2%2 == 0){
        cout << 0 << endl;
        return 0;
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    sort(a[2].begin(), a[2].end());
    if(n1%2==0){

    }else if(n2%2==0){
        
    }else{
        
    }
    return 0;
}