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
    for(int i = 0; i< s.size(); i++){
        int x = s[i] - 'A';
        x = (x + n) % 26;
        s[i] = x + 'A';
    }
    cout << s << endl;
    return 0;
}