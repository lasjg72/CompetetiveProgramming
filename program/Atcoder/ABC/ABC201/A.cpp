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
    vector<int> a(3);
    for(int i = 0; i < 3; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int tmp = a[1]-a[0];
    if(a[2]-a[1] == tmp) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}