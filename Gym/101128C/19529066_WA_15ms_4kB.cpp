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

int n, m;
int cas, tol, T;
multiset<ll> st;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		ll x;
		ll ans = 0;
		for(int i=1; i<=n; i++) {
			scanf("%lld", &x);
			st.insert(x);
		}
		if(n == 1) {
			printf("0\n");
			continue;
		}
		while(!st.empty()) {
			ll sum = 0;
			ll one = *st.begin();
			st.erase(st.begin());
			sum += one;
			if(!st.empty()) {
				ll two = *st.begin();
				st.erase(st.begin());
				sum += two;
				ans += sum;
				if(st.empty())	break;
				st.insert(sum);
			} else {
				ans += sum;
				st.insert(sum);
				break;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
