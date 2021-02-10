#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    long long a;
    double b;
    cin >> a >> b;
    long long c = b *100 + 0.1;
    cout << a * c/100 << endl;
    return 0;
}
