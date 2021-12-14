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
    int n, k, a;
    cin >> n >> k >> a;
    int nk = k%n;
    int ans = (nk+a-1)%n;
    if(ans == 0){
        cout << n << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}