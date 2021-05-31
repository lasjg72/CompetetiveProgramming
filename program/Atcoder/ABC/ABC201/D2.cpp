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
#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;

const int INF = 1001001001;

int h, w;
int a[2005][2005];

bool visited[2005][2005];
int memo[2005][2005];
int f(int i, int j) {
  cout << "i: " << i << " j: " << j << endl;
  if (i == h-1 && j == w-1) return 0;
  if (visited[i][j]) return memo[i][j];
  visited[i][j] = true;
  int res = -INF;
  if (j+1 < w) res = max(res, a[i][j+1]-f(i,j+1));
  if (i+1 < h) res = max(res, a[i+1][j]-f(i+1,j));
  return memo[i][j] = res;
}

int main() {
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  rep(i,h)rep(j,w) a[i][j] = s[i][j]=='+' ? 1 : -1;
  int score = f(0,0);
  if (score == 0) cout << "Draw" << endl;
  if (score < 0) cout << "Aoki" << endl;
  if (score > 0) cout << "Takahashi" << endl;
  return 0;
}