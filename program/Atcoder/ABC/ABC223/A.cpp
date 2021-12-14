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
    if(x%100 == 0 && x > 0) cout << "Yes" << endl;
    else cout << "No" << endl; 
    return 0;
}
