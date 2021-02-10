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
    int n = s.size();
    if(s[n-1] == 's'){
        cout << s + "es" << endl;
    }else{
        cout << s + 's' << endl;
    }
    return 0;
}