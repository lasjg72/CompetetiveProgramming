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
    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            if(s[i] == '1'){
                cout << "Takahashi" << endl;
                return 0;
            }
        }else{
            if(s[i] == '1'){
                cout << "Aoki" << endl;
                return 0;
            }
        }
    }
    return 0;
}