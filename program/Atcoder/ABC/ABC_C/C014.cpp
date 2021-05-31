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
    vector<int> num(1000005, 0);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        num[a]++;
        num[b+1]--;
    }
    int ans = 0;
    for(int i = 0; i <= 1000000; i++){
        num[i+1] += num[i];
        ans = max(num[i], ans);
    }
    cout << ans << endl;    
    return 0;
}