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
    int x, y;
    cin >> x >> y;
    if(x == y){
        cout << x << endl;
    }else{
        cout << 3-(x+y) << endl;
    }
    return 0;
}