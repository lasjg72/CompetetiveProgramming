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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int na, nb, na1, nb1, na2, nb2;
    if(n%2){
        int l = (n-1)/2;
        na = a[l];
        nb = b[l];
        //cout << na << ":" << nb << endl;
    }else{
        int l = n/2;
        int r = l-1;
        na1 = a[l];
        nb1 = b[l];
        na2 = a[r];
        nb2 = b[r];
        //cout << "na1: " << na1 << " na2: " << na2 << endl;
        //cout << "nb1: " << nb1 << " nb2: " << nb2 << endl;
    }
    ll ans = 0, tot = 0;
    ll ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
    for(int i = 0; i < n; i++){
        if(n%2){
            //cout << "---" << endl;
            ans += abs(na-a[i]);
            //cout << "ans: " << ans << endl;
            ans += abs(a[i]-b[i]);
            ans += abs(nb-b[i]);
            //cout << "ans: " << ans << endl;
        }else{
            ans1 += abs(na1-a[i]);
            ans2 += abs(nb1-b[i]);
            ans3 += abs(na2-a[i]);
            ans4 += abs(nb2-b[i]);
            tot += abs(a[i]-b[i]);
            
        }
    }
    if(n%2){
        cout << ans << endl;
    }else{
        cout << min(ans1, ans3)+min(ans2, ans4)+tot << endl;
    }
    return 0;
}