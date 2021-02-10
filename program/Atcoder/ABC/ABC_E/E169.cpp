#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int n;
    int ans = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(n%2==1){
        int L = a[(n-1)/2];
        int R = b[(n-1)/2];
        ans = R-L+1;
        cout << ans << endl;
    }else if(n%2==0){
        int L = a[n/2-1]+a[n/2];
        int R = b[n/2-1]+b[n/2];
        ans = R-L+1;
        cout << ans << endl;
    }

    return 0;
}