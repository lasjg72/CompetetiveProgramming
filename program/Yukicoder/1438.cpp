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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int num = 0;
    int i = 0;
    while(i+1 < n){
        if(a[i] > a[i+1]){
            int k = 1;
            while(i+1 < n && a[i] > a[i+1]){
                k++;
                i++;
            }
            num += k/2;
        }
        i++;
    }
    cout << n-num << endl;
    return 0;
}