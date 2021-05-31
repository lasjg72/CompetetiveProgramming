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
    vector<int> v(n);
    map<int, int> num1, num2;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i % 2 == 0) num1[v[i]]++;
        else num2[v[i]]++;
    }
    
    return 0;
}