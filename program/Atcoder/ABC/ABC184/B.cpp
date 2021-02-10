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
    int n, x;
    string s;
    cin >> n >> x >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'o'){
            x++;
        }else{
            if(x == 0){

            }else{
                x--;
            }
        }
    }
    cout << x << endl;
    return 0;
}