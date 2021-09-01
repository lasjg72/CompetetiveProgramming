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

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int now = a[0];
    for(int i = 1; i < n; i++){
        now = gcd(now, a[i]);
    }
    cout << now << endl;
    return 0;
}