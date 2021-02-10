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
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for(int i = 0; i<n; i++){
        cin >> p[i];
    }
    for(int i = 0; i<n; i++){
        cin >> q[i];
    }
    int a = 1, b = 1;
    while(prev_permutation(p.begin(), p.end())){
        a++;
    }

    while(prev_permutation(q.begin(), q.end())){
        b++;
    }
    
    cout << abs(a-b) << endl;

    return 0;
}