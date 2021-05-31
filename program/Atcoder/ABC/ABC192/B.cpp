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
        if(i%2){
            if (!isupper(s[i])){
                cout << "No" << endl;
                return 0;
            }
        }else{
            if (isupper(s[i])){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}