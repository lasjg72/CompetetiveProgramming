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
    int num=0;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a == b){
            num++;
            if(num == 3){
                cout << "Yes" << endl;
                return 0;
            }
        }else{
            num = 0;
        }
    }
    cout << "No" << endl;
    return 0;
}