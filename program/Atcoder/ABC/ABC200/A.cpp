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
    if(n%100 == 0){
        cout << n/100 << endl;
    }else{
        cout << n/100 + 1 << endl;
    }
    return 0;
}