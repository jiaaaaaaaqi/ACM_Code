#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
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
const int    maxn = 1e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

vector<int> fib(20);
vector<int> sg(maxn, -1);

int dfs(int x) {
	if(sg[x] != -1)	return sg[x];
	vector<bool> vis(maxn, false);
	for(int i=1; i<=16; i++) {
		if(x >= fib[i]) {
			sg[x-fib[i]] = dfs(x-fib[i]);
			vis[sg[x-fib[i]]] = true;
		}
	}
	for(int i=0; ; i++) {
		if(!vis[i]) {
			sg[x] = i;
			return sg[x];
		}
	}
}

int main() {
	fib[1] = 1, fib[2] = 2;
	for(int i=3; i<=16; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}
	sg[0] = 0;
	dfs(1000);
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c), a||b||c) {
		ll ans = (sg[a] ^ sg[b] ^ sg[c]);
		if(ans)	printf("Fibo\n");
		else	printf("Nacci\n");
	}
	return 0;
}