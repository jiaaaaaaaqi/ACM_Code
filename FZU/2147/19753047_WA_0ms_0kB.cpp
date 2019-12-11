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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

ll n, m;
int cas, tol, T;

int main() {
//	for(int i=2; i<=20; i++) {
//		int ans = inf;
//		for(int j=1; j<=i; j++) {
//			ans = min(ans, i-i%j);
//		}
//		printf("%d %d\n", i, ans);
//	}
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld", &n, &m);
		ll ans = 0;
		while(n>m) {
			n = (n/2)+1;
			ans++;
		}
		printf("Case %d: %lld\n", cas++, ans);
	}
	return 0;
}
