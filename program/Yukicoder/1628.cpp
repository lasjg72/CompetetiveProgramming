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
    vector<int> num(10);
    for(int i = 0; i < 9; i++) cin >> num[i+1];
    string ans = "";
    for(int i = 9; i >= 1; i--){
        while(num[i] > 0){
            ans += i+'0';
            num[i]--;
        }
    }
    cout << ans << endl;
    return 0;
}