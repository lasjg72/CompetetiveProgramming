#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i<n;i++){
        cin >> a[i];
    }
    vector<long long> num(n,0);
    for(int i = 0 ; i < k; i++){
        for(int j =0; j < n ; j++){
            for(int k =0; k<= a[j]; k++){
                if(j + k < n)
                num[j + k] += 1;
                if(k!=0 && j-k >= 0)
                num[j-k] += 1;
            }
        }
        for(int j = 0; j< n; j++){
            a[j] = num[j];
            num[j] = 0;
        }
    }
    for(int i = 0; i< n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}