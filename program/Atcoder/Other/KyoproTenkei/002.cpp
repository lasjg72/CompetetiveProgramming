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
    for(int bit = 0; bit<(1<<n); bit++){
        string tmp;
        for(int i = n-1; i >= 0; i--){
            if(bit&(1<<i)){
                tmp += ')';
            }else{
                tmp += '(';
            }
        }
        int num = 0;
        bool ok = true;
        for(int i = 0; i < n; i++){
            if(tmp[i] == '(') num++;
            if(tmp[i] == ')'){
                if(num < 1){
                    ok = false;
                    break;
                }else{
                    num--;
                }
            }
        }
        if(num != 0) ok = false;
        if(!ok) continue;
        else{
            cout << tmp << endl;
        }
    }
    return 0;
}