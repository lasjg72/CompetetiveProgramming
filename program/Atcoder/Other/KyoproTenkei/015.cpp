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
    ll a, b, c;
    cin >> a >> b >> c;
    ll mx = max(a, b);
    ll mx = max(mx, c);
    ll tar = 0;
    for(int i = 1; i*i <= mx; i++){
        if(a%i==0 && b%i==0 && c%i == 0) tar = i;
    }
    cout << a/tar-1+b/tar-1+c/tar-1 << endl;
    return 0;
}