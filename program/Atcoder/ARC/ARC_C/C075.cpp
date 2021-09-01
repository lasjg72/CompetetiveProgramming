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
    vector<int> s(n);
    int tot = 0;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        tot += s[i];
    }
    sort(s.begin(), s.end());
    if(tot % 10 == 0){
        int pos = 0;
        while(tot%10 == 0 && pos < n){
            if(s[pos]%10 != 0) tot -= s[pos];
            pos++;
        }
        if(tot%10 == 0) cout << 0 << endl;
        else cout << tot << endl;
    }else{
        cout << tot << endl;
    }
    return 0;
}