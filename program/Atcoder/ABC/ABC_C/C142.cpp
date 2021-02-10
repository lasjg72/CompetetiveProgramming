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
    vector<pair<int, int>> a(n+1);
    for(int i = 1; i < n+1; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    for(int i = 1; i < n+1 ; i++){
        cout << a[i].second << " ";
    }
    cout << endl;
    return 0;
}