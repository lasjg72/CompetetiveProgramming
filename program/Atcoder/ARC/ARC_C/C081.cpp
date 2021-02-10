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
    vector<ll> a(n, 0);
    map<ll, ll> edge;
    for(int i = 0; i< n; i++){
        cin >> a[i];
        edge[a[i]]++;
    }
    sort(a.begin(), a.end());
    ll edge1= 0, edge2 = 0;
    ll ans = 0;
    for(int i = n-1; i >= 0; i--){
        if(edge[a[i]] >= 4 && edge1 == 0){
            ans = a[i]*a[i];
            cout << ans << endl;
            return 0;
        }else if(edge[a[i]] >= 2){
            if(edge1 == 0) {
                edge1 = a[i];
                edge[a[i]] = 0;
            }
            else{
                edge2 = a[i];
                ans = edge1 * edge2;
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}