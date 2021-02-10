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
    string s, t;
    cin >> s >> t;
    s += s;
    t += t;
    cout << s << endl;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < t.size()/2; j++){
            cout << "i: " << i  << " " << "s[i]: " << s[i] << endl;
            cout << "j: " << j << "t[j]" << t[j] << endl;
            if(j == t.size()-1 && s[i] == t[j]){
                cout << "Yes" << endl;
                return 0;
            }
            if(s[i] == t[j]) continue;
            else break;
        }
    }
    cout << "No" << endl;
    return 0;
}