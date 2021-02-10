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
    map<string, int> ans;
    for(int i = 0; i< n; i++){
        string s;
        cin >> s;
        ans[s]++;
    }
    cout << "AC x " << ans["AC"] << endl;  
    cout << "WA x " << ans["WA"] << endl;
    cout << "TLE x " << ans["TLE"] << endl;
    cout << "RE x " << ans["RE"] << endl;
    return 0;
}