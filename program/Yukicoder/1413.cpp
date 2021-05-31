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
    vector<int> a(n-1, 0);
    int tot = 0;
    for(int i= 0; i < n-1; i++){
        cin >> a[i];
        tot += a[i];
    }
    int ans = 0;
    for(int i = 0; i <= 100; i++){
        if((tot+i)%n == 0){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
