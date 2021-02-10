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
    int n, x, t;
    cin >> n >> x >> t;
    int num = n / x;
    if(n % x == 0){
        cout << num * t << endl;;
    }else{
        cout << (num + 1) * t << endl;
    }
    return 0;
}