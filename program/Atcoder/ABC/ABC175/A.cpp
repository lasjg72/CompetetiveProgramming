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
    string s;
    cin >> s;
    if(s == "SSR" || s == "SRS" || s == "RSS" || s == "RSR") cout << 1 << endl;
    else if(s == "SRR" || s == "RRS") cout << 2 << endl;
    else if(s == "RRR") cout << 3 << endl;
    else cout << 0 << endl;
    return 0;
}