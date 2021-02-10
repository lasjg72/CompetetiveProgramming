#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    int x;
    cin >> x;
    vector<bool> pr(100100, true);
    pr[0] = pr[1] = false;
    for(int i = 2; i < 100100; i++){
        if(pr[i]){
            for(int j = 2*i; j < 100100; j += i){
                
                pr[j] = false;
            }
        }
    }
    for(int i = x; i < 100100; i++){
        if(pr[i] == true){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}