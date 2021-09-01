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
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    vector<string> ans(s+1, "");
    if(a[0] <= s) ans[a[0]] = "A";
    if(b[0] <= s) ans[b[0]] = "B";
    for(int i = 1; i < n; i++){
        for(int j = s; j >= 0; j--){
            int num = ans[j].size();
            if(num == i){
                if(j+a[i] <= s) ans[j+a[i]] = ans[j]+"A";
                if(j+b[i] <= s) ans[j+b[i]] = ans[j]+"B";
            }
        }
    }
    int num = ans[s].size();
    if(num != n){
        cout << "Impossible" << endl;
    }else{
        cout << ans[s] << endl;
    }
    return 0;
}