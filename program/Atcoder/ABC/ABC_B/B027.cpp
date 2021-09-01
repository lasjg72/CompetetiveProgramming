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
    int tot = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        tot += a[i];
    }
    if(tot%n != 0){
        cout << -1 << endl;
        return 0;
    }
    int num = tot/n;
    int ans = 0, p = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != num){
            if(a[i]+p == num){
                p = 0;
                continue;
            }else{
                ans++;
                p = a[i]+p-num;
            }
        }else{
            if(p != 0){
                ans++;
                continue;
            }
        }
    }
    cout << ans << endl;
    return 0;
}