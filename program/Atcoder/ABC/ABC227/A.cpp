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
    int n, k, a;
    cin >> n >> k >> a;
    for(int i = 0; i < k-1; i++){
        a = (a+1)%n;
        if(a == 0) a = n;
    }
    cout << a << endl;
    return 0;
}