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
    int tmp1 = -1, tmp2 = -1, tmp3 = -1;
    if(n >= 36*36){
        tmp1 = n/(36*36);
        //cout << "tmp1: " << tmp1 << endl;
        n -= 36*36*tmp1;
    }
    if(n >= 36){
        tmp2 = n/36;
        //cout << "tmp2: " << tmp2 << endl;
        n -= 36*tmp2;
    }
    tmp3 = n;
    //cout << "tmp3: " << tmp3 << endl;
    char c1, c2, c3;
    if(tmp1 > 9){
        c1 = 'A' + tmp1 - 10;
    }else if(tmp1 >= 0){
        c1 = tmp1 + '0';
    }else if(tmp1 == -1){
        c1 = ' ';
    }
    //cout << "c1: " << c1 << endl;
    if(tmp2 > 9){
        c2 = 'A' + tmp2 - 10;
    }else if(tmp2 >= 0){
        c2 = tmp2 + '0';
    }else if(tmp2 == -1){
        c2 = ' ';
    }
    //cout << "c2: " << c2 << endl;
    if(tmp3 > 9){
        c3 = 'A' + tmp3 - 10;
    }else if(tmp3 >= 0){
        c3 = tmp3 + '0';
    }else if(tmp3 == -1){
        c3 = ' ';
    }
    //cout << "c3: " << c3 << endl;
    if(c1 == ' ' && c2 == ' '){
        cout << c3 << endl;    
    }else if(c1 == ' '){
        cout << c2 << c3 << endl;
    }else{
        cout << c1 << c2 << c3 << endl;
    }
    
    return 0;
}