#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>

using namespace std;
//using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int q;
    cin >> q;
    vector<int> t(q);
    for(int i = 0; i < q; i++){
        cin >> t[i];
    }
    int ans = 0;
    for(int i = 0; i < q; i++){
        //cout << "i: " << i << endl;
        int l = 0, r = n-1;
        while(r-l>1){
            int mid = (l+r)/2;
                if(a[mid] >= t[i]){
                    r = mid;
                }else{
                    l = mid;
                }
            //cout << "r: " << r << "l: " << l << endl;
        }
        if(a[r] == t[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}