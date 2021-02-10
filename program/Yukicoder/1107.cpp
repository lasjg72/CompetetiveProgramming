#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a < b && c > d){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}