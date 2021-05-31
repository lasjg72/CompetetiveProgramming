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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    while(q--){
        int b;
        cin >> b;
        int l = -1, r = n-1;
        while(r-l>1){
            int mid = (l+r)/2;
            if(a[mid] >= b){
                r = mid;
            }else{
                l = mid;
            }
        }
        if(r == 0) cout << abs(a[r]-b) << endl;
        else cout << min(abs(a[r]-b), abs(a[r-1]-b)) << endl;
    }
    return 0;
}