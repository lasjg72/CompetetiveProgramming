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
#include <stack> 

using namespace std;
using ll = long long;
vector<stack<int>> num(51);

int main()
{
    int n;
    cin >> n;
    int now = 0;
    for(int i = 0; i < n; i++){
        int w;
        cin >> w;
        bool ok = true;
        for(int j = 0; j < n; j++){
            if(num[j].size() > 0 && num[j].top() >= w) {
                num[j].push(w);
                ok = false;
                break;
            }
        }
        if(ok) {
            num[now].push(w);
            now++;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(num[i].size() > 0) ans++;
    }
    cout << ans << endl;
    return 0;
}