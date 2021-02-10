#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> lower(n), upper(n);
    for(int i = 0; i< n; i++){
        cin >> a[i];
        if(i==0){
            lower[0].first = a[i];
            lower[0].second = a[i];
        }else if(i==1){
            lower[i].first = lower[i-1].first;
            lower[i].second = lower[i-1].second;
        }else{
            lower[i].first = min(lower[i-1].first, a[i-1]);
            lower[i].second = max(lower[i-1].second, a[i-1]);
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(i==n-1){
            upper[i].first = a[i];
            upper[i].second = a[i];
        }else if(i==n-2){
            upper[i].first = a[i+1];
            upper[i].second = a[i+1];
        }else{
            upper[i].first = min(upper[i+1].first, a[i+1]);
            upper[i].second = max(upper[i+1].second, a[i+1]);
        }
    }
    int mn = 1001001001;
    for(int i = 1; i< n-1; i++){
        if(a[i]> lower[i].first && a[i] > upper[i].first){
            mn = min(mn, a[i]+ lower[i].first + upper[i].first);
        }else if(a[i] < lower[i].first && a[i] < upper[i].first){
            mn = min(mn, a[i] + lower[i].first + upper[i].first);
        }
    }
    if(mn==1001001001){
        cout << -1 << endl;
        return 0;
    }
    cout << mn << endl;
    return 0;
}