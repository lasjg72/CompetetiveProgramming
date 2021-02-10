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
    cin >> n;
    int r = 0;
    vector<char> stone(n);
    for(int i = 0; i< n; i++){
        cin >> stone[i];
        if(stone[i] == 'R') r++;
    }
    int res = r;
    for(int i = 0; i< res; i++){
        if(stone[i] == 'R') r--;
    }
    cout << r << endl;
    return 0;
}