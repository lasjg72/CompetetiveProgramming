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
    set<int> d;
    for(int i = 0; i< n; i++){
        int a;
        cin >> a;
        d.insert(a);
    }
    cout << d.size() << endl;
    return 0;
}