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
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int tmp1 = i, tmp2 = i;
        bool flag = false;
        //cout << "i: " << i << endl;
        while(tmp1 != 0){
            int num = tmp1 % 10;
            //cout << "num: " << num << endl;
            if(num == 7){
                ans++;
                //cout << "---------" << endl;
                flag = true;
                break;
            }
            tmp1 /= 10;
            //cout << "tmp1: " << tmp1 << endl;
        }
        if(flag) continue;
        while(tmp2 != 0){
            int num = tmp2 % 8;
            //cout << "num: " << num << endl;
            if(num == 7){
                ans++;
                //cout << "---------" << endl;
                flag = true;
                break;
            }
            tmp2 /= 8;
            //cout << "tmp2: " << tmp2 << endl;
        }
    }
    cout << n-ans << endl;
    return 0;
}