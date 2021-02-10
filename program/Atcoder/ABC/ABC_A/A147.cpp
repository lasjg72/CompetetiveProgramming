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
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    if(a1+a2+a3 >= 22){
        cout << "bust" << endl;
    }else{
        cout << "win" << endl;
    }
    return 0;
}