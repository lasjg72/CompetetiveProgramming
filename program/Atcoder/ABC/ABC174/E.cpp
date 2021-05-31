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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 0, r = 1000000000;
    while(r-l>1){
        int mid = (l+r)/2;
        ll tot = 0;
        // if(mid == 0){
        //     r = 1;
        //     break;
        // }
        for(int i = 0; i < n; i++){
            int num = 0;
            tot += (a[i]-1)/mid;
        }
        if(tot > k){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << r << endl;
    return 0;
}