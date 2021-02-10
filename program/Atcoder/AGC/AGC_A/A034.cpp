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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    d--;
    string s;
    cin >> s;
    if(c < d){
        for(int i = a; i < d; i++){
            if(s[i] == '#' && s[i+1] == '#'){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }else if (c > d){
        for(int i = b; i < d+1; i++){
            if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.'){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    }else if (c == d){
        cout << "No" << endl;
    }
    return 0;
}