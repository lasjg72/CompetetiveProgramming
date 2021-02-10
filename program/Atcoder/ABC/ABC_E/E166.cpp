#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<long long, int> M;
    vector<long long> a(n+1, 0), L(n+1, 0), R(n+1, 0);

    long long ans = 0;
    for(int i = 1; i<n+1; i++){
        cin >> a[i];
        ans += M[i-a[i]];
        M[i+a[i]]++;
    }
    
    cout << ans << endl;
    return 0;
}