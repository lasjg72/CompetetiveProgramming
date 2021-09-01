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
    set<int> ans;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        while(a%2 == 0){
            a /= 2;
        }
        ans.insert(a);
    }
    cout << ans.size() << endl;
    return 0;
}