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
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int j = 0; j < n; j++){
            cin >> a[j];
        }
        if(n % 2 == 1){
            cout << "Second" << endl;
        }else{
            cout << "First" << endl;
        }
    }
    return 0;
}