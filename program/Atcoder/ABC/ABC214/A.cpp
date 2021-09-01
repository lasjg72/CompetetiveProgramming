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
    if(n <= 125){
        cout << 4 << endl;
    }else if(n <= 211){
        cout << 6 << endl;
    }else{
        cout << 8 << endl;
    }
    return 0;
}