#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> h(n), a(m), b(m);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    vector<bool> flag(n, true);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        if(h[a[i]-1] > h[b[i]-1]){
            flag[b[i]-1] = false;
        }else if (h[a[i]-1] < h[b[i]-1]){
            flag[a[i]-1] = false;
        }else if(h[a[i]-1] == h[b[i]-1]){
            flag[a[i]-1] = false;
            flag[b[i]-1] = false;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(flag[i]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}