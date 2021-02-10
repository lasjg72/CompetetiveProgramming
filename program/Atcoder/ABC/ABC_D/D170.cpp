#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n,0);
    vector<int> cnt(1000005, 0);
    for(int i =0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i< n; i++){
        if(cnt[a[i]] == 0){
            for(int j = a[i]; j<1000005; j += a[i]){
                cnt[j]++;
            }
        }else{
            cnt[a[i]] = 2;
        }
    }
    int ans = 0;
    for(int i = 0; i<n;i++){
        if(cnt[a[i]] == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}