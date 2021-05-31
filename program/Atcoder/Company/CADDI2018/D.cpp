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
    vector<int> a(n);
    bool ok = false;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]%2) ok = true;
    }
    if(ok){
        cout << "first" << endl;
    }else{
        cout << "second" << endl;
    }
    return 0;
}