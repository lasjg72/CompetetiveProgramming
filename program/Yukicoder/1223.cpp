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
    double n, k, t;
    cin >> n >> k >> t;
    if(abs(n/k) <= t){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}