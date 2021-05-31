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
    int m = 0;
    for(int i = 1; i <= 1000; i++){
        if(i*(i+1) == 2*n) m = i+1;
    }
    if(m == 0){
        cout << "No" << endl;
        return 0;
    }
    // 1組の要素数
    int num = 2*n/m;
    int s[m][num+1];
    for(int i = 0; i < m; i++){
        s[i][0] = num;
        int now = 1;
        now += (i+1)*i/2;
        s[i][1] = now;
        for(int j = 0; j < i; j++){
            now++;
            s[i][1+j+1] = now;
        }
        for(int j = 0; j < num-1-i; j--){
            now += (i+1+j);
            s[i][]
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < num+1; j++){
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}