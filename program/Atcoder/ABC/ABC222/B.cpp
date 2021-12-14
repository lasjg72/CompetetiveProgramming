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
    int n, p;
    cin >> n >> p;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a < p) ans++;
    }
    cout << ans << endl;
    return 0;
}