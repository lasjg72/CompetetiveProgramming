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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p;
    int tmp = m;
    for(int i = 2; i*i <= m; i++){
        int num = 0;
        while(tmp%i == 0){
            tmp /= i;
            num++;
        }
        p.emplace_back(i, num);
    }
    if(tmp != 1) 　
    return 0;
}