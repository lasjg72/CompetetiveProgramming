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
    map<int, int> seq;
    for(int i = 0; i< n; i++){
        cin >> a[i];
        seq[a[i]]++;
    }
    int ans = 0;
    for(int i = 0; i< n; i++){
        if(seq[a[i]] > a[i]){
            ans += seq[a[i]] - a[i];
            seq[a[i]] = a[i];
        }else if(seq[a[i]] < a[i]){
            ans += seq[a[i]];
            seq[a[i]] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}