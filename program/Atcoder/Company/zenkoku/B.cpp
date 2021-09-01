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
    string a, b, c;
    cin >> n >> a >> b >> c;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i] && b[i] != c[i] && a[i] != c[i]){
            ans += 2;
        }else if(a[i] == b[i] && b[i] == c[i]){
            continue;
        }else{
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}