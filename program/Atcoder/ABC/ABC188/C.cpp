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
    int num = pow(2, n);
    vector<int> a(num);
    for(int i = 0; i< num; i++){
        cin >> a[i];
    }
    //cout << "ko" << endl;
    int m1 =0, m2 = 0;
    for(int i = 0; i < num/2; i++){
        m1 = max(m1, a[i]);
        //cout << a[i] << endl;
    }
    //cout << m1 << endl;
    for(int i = num/2; i < num; i++){
        m2 = max(m2, a[i]);
    }
    //cout << m2 << endl;
    int ans = min(m1, m2);
    for(int i = 0; i < num; i++){
        if(a[i] == ans){
            cout << i+1 << endl;
        }
    }
    return 0;
}