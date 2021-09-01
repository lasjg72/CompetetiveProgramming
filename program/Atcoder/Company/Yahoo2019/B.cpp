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
    vector<int> num(4, 0);
    for(int i = 0; i < 3; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        num[a]++;
        num[b]++;
    }
    for(int i = 0; i < 4; i++){
        if(num[i] >= 3){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}