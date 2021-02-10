#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int tmp = 0;
    for(int i = 0; i< n; i++){
        cin >> a[i];
        tmp ^= a[i];
    }
    vector<int> ans(n);
    for(int i =0; i< n; i++){
        ans[i] = a[i]^tmp;
    }
    for(int i = 0; i<n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}