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
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> x = {a, b, c};
    sort(x.begin(), x.end());
    if(x[1] == a){
        cout << "A" << endl;
        return 0;
    }else if(x[1] == b){
        cout << "B" << endl;
        return 0;
    }else{
        cout << "C" << endl;
        return 0;
    }
    return 0;
}