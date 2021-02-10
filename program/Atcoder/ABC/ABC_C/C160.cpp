#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;
    vector<int> a(n, 0);
    int len=0;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        if(i != 0){
            len = max(len, a[i]-a[i-1]);
        }
    }
    len = max(len, k-a[n-1] + a[0]);

    cout << k-len << endl;
    return 0;
}