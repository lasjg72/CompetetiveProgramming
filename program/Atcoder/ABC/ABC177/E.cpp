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
const int MAX = 1100000;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    //map<int, int> num;
    vector<int> num(MAX, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        num[a[i]]++;
    }
    bool coprime = true;
    vector<int> isPrime(MAX, true);
    for(int i = 2; i < MAX; i++){
        int sum = 0;
        if(isPrime[i]){
            for(int j = i; j < MAX; j+=i){
                sum += num[j];
                isPrime[j] = false;
            }
        }
        if(sum > 1){
            coprime = false;
            break;
        }
    }
    if(coprime){
        cout << "pairwise coprime" << endl;
        return 0;
    }

    int g = 0;
    for(int i = 0; i < n; i++){
        g = gcd(g, a[i]);
    }
    if(g == 1){
        cout << "setwise coprime" << endl;
    }else{
        cout << "not coprime " << endl;
    }
    return 0;
}