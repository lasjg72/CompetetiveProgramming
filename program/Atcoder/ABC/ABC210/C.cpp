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
    vector<int> c(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++) cin >> c[i];
    set<int> st;
    for(int i = 0; i < k; i++){
        st.insert(c[i]);
        mp[c[i]]++;
    }
    int ans = st.size();
    for(int i = 1; i < n-k+1; i++){
        mp[c[i-1]]--;
        if(mp[c[i-1]] == 0) st.erase(c[i-1]);
        //cout << "i+k-1: " << i+k-1 << endl;
        mp[c[i+k-1]]++;
        st.insert(c[i+k-1]);
        ans = max(ans, (int)st.size());
    }
    cout << ans << endl;
    return 0;
}