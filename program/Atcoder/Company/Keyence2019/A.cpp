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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> x(10, 0);
    x[a]++;
    x[b]++;
    x[c]++;
    x[d]++;
    if(x[1] == 1 && x[9] == 1 && x[7] == 1 && x[4] == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;    
    }
    return 0;
}