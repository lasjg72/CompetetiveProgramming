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
    int ans = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a > 10){
            ans += (a-10);
        }
    }
    cout << ans << endl;
    return 0;
}