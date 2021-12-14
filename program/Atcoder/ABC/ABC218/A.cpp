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
    int n;
    string s;
    cin >> n >> s;
    if(s[n-1] == 'o') cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
