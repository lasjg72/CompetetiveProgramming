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

int a, b, c;

int solve(int b, int c){
    //cout << "---" << endl;
    vector<int> num(10, -1);
    vector<int> can;
    int pos = 0, base = b;
    while(num[b] == -1){
        num[b] = pos;
        can.push_back(b);
        b = b*base%10;
        pos++;
        //cout << "b: " << b << "pos: " << pos << endl;
    }
    int cyc = pos-num[b];
    //cout << "cyc: " << cyc << " num[b]: " << num[b] << endl;
    int tmp;
    if(c == 0) tmp = 1;
    else if(c <= num[b]) {
        tmp = can[c-1];
    }
    else{
        c -= num[b]+1;
        c %= cyc;
        tmp = can[num[b]+c];
    }
    return tmp;
}

int main()
{
    cin >> a >> b >> c;
    a = a%10;
    b = b%10;
    cout << solve(a, solve(b, c)) << endl;
    return 0;
}