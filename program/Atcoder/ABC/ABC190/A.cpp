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
    int a, b, c;
    cin >> a >> b >> c;
    if(c == 0){
        while(1){
            a--;
            if(a == 0){
                cout << "Aoki" << endl;
                return 0;
            }
            b--;
            if(b == 0){
                cout << "Takahashi" << endl;
                return 0;
            }
        }
    }else{
        while(1){
            b--;
            if(b == 0){
                cout << "Takahashi" << endl;
                return 0;
            }
            a--;
            if(a == 0){
                cout << "Aoki" << endl;
                return 0;
            }
        }
    }

    return 0;
}
