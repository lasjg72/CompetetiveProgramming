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

int ans[1005];

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = a[i]; j <= b[i]; j++){
            ans[j]++;
        }
    }
    int num = 0;
    for(int i = 1; i <= 1000; i++){
        if(ans[i] == n) num++;
    }
    cout << num << endl;
    return 0;
}