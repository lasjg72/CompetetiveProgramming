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
P dp[100005];
const int INF = 1001001001;
int n;

int bs(int y, int x){
    int l = -1;
    int r = n;
    while(r-l>1){
        int mid = (l+r)/2;
        if(dp[mid].second >= x){
            r = mid;
        }else{
            l = mid;
        }
    }
    return r;
}

int main()
{
    cin >> n;
    vector<P> size(n);
    for(int i = 0; i < n; i++){
        cin >> size[i].first >> size[i].second;
        dp[i] = {INF, INF};
    }
    sort(size.begin(), size.end());
    for(int i = 0; i < n; i++){
        int now = bs(size[i].first, size[i].second);
        if(dp[now-1].first < size[i].first && dp[now-1].second < size[i].second) dp[now] = {size[i].first, size[i].second};
        else if(dp[now-1].first < size[i].first && dp[now-1].second > size[i].second) dp[now-1] = {size[i].first, size[i].second};
        else if(now == 0) dp[now] = {size[i].first, size[i].second};
    }
    cout << bs(INF, INF) << endl;
    return 0;
}