#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    int n; 
    string s;
    cin >> n >> s;
    int ans = 1;
    for(int i = 0; i < n-1; i++){
        if(s[i] == s[i+1]){
            continue;
        }else{
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}