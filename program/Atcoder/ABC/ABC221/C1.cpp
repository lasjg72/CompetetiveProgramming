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
    string s;
    cin >> s;
    sort(s.rbegin(), s.rend());
    int ans = 0;
    do{
        for(int i = 0; i < s.size()-1; i++){
            string t, u;
            t = s.substr(0, i+1);
            u = s.substr(i+1, s.size()-(i+1));
            //cout << "t u " << t << " " << u << " " << endl;
            int a = stoi(t), b = stoi(u);
            ans = max(ans, a*b);
        }
    }while(next_permutation(s.rbegin(), s.rend()));
    cout << ans << endl;
    return 0;
}