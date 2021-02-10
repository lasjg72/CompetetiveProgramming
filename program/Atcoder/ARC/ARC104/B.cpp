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
    string s;
    cin >> s;
    map<char, int> c;
    ll ans = 0;
    for(int j = 0; j < n; j++){
        for(int i = j; i < n; i++){
            c[s[i]]++;
            if(s[i] == 'A' || s[i] == 'T'){
                if(c['A'] != 0 && c['A'] == c['T'] && c['C'] == c['G']) ans++;
            }else if(s[i] == 'C' || s[i] == 'G'){
                if(c['C'] != 0 && c['C'] == c['G'] && c['A'] == c['T']) ans++;
            }
        }
        c['A'] = 0;
        c['T'] = 0;
        c['C'] = 0;
        c['G'] = 0;
    }
    cout << ans << endl;
    return 0;
}