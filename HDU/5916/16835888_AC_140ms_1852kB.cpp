#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;
int ans[maxn];
bool vis[maxn];

int solve(int a[], int n) {
	int ans = 0;
	for(int i=1; i<n; i++) {
		ans += __gcd(a[i], a[i+1]);
	}
	return ans;
}

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		mes(ans, 0);
		mes(vis, 0);
		scanf("%d%d", &n, &m);
		int cnt = 1;
		for(int i=1; i<=m; i++) {
			ans[cnt++] = 2*i;
			vis[2*i] = true;
		}
		for(int i=1; i<=n; i++) {
			if(vis[i])	continue;
			ans[cnt++] = i;
		}
		printf("Case #%d: ", cas++);
		for(int i=1; i<=n; i++)
			printf("%d%c", ans[i], i==n ? '\n' : ' ');
	}
	return 0;
}
