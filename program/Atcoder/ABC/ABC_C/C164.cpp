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
    map<string, int> s;
    int ans = 0;
    for(int i = 0; i< n; i++){
        string t;
        cin >> t;
        s[t]++;
        if(s[t] == 1){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}