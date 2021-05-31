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
    int n, L, k;
    cin >> n >> L >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 0, r = L/(k+1)+1;
    while(r-l>1){
        int mid = (l+r)/2;
        //cout << "-----" << endl;
        //cout << "mid: " << mid << endl;
        int pre = 0, num = 0;
        for(int i = 0; i < n; i++){
            if(a[i]-pre >= mid){
                num++;
                pre = a[i];
            }
            if(num == k){
                //cout << "L-pre: " << L-pre << endl;
                if(L-pre >= mid){
                    l = mid;
                    //cout << "l: " << l << endl;
                    break;
                }else{
                    r = mid;
                    //cout << "r1: " << r << endl;
                    break;
                }
            }
        }
        if(num != k){
            r = mid;
            //cout << "r2: " << r << endl;
        }
    }
    cout << l << endl;
    return 0;
}