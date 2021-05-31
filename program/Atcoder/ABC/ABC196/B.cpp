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
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.'){
            for(int j = 0; j < i; j++){
                cout << s[j];
            }
            cout << endl;
            return 0;
        }
    }
    cout << s << endl;
    return 0;
}