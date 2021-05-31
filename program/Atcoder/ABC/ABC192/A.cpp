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
    int x;
    cin >> x;
    while(x >= 100){
        x -= 100;
    }
    cout << 100 -x << endl;
    return 0;
}