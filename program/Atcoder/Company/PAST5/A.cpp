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
    for(int i = 0; i < s.size()-2; i++){
        if(s[i] == 'o' && s[i+1] == 'o' && s[i+2] == 'o'){
            cout << "o" << endl;
            return 0;
        }else if(s[i] == s[i+1] && s[i+1] == s[i+2]){
            cout << 'x' << endl;
            return 0;
        }
    }
    cout << "draw" << endl;
    return 0;
}