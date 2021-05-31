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
    vector<vector<int>> a(n, vector<int>(n-1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            cin >> a[i][j];
            a[i][j]--;
        }
        reverse(a[i].begin(), a[i].end());
    }
    set<P> st;
    auto check = [&](int i){
        if(a[i].size() == 0) return;
        int j = a[i].back();
        if(a[j].back() == i){
            if(i > j) swap(i, j);
            st.insert(P(i, j));
        }
    };
    for(int i = 0; i < n; i++){
        check(i);
    }
    int ans = 0;
    while(st.size() > 0){
        ans++;
        set<P> tmp;
        swap(st, tmp);
        for(P p : tmp){
            int i = p.first, j = p.second;
            a[i].pop_back();
            a[j].pop_back();
        }
        for(P p : tmp){
            int i = p.first, j = p.second;
            check(i);
            check(j);
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i].size() != 0){
            cout << -1 << endl;
            return 0;    
        }
    }
    cout << ans << endl;
    return 0;
}