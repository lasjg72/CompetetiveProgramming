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
    int num1 = 0, num2 = 0, num3 = 0, ab = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        
        if(s[0] == 'B' && s.back() == 'A') num1++;
        else if(s[0] == 'B') num2++;
        else if(s.back() == 'A') num3++;

        int m = s.size();
        for(int j = 0; j < m-1; j++){
            if(s[j] == 'A' && s[j+1] == 'B') ab++;
        }
    }
    if(num1 == 0){
        cout << ab+min(num2, num3) << endl;
    }else{
        if(num2 + num3 > 0){
            cout << ab+num1+min(num2, num3) << endl;
        }else{
            cout << ab+num1-1 << endl;
        }
    }
    return 0;
}