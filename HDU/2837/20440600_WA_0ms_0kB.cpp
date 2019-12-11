/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月15日 星期一 10时16分55秒
 ***************************************************************/

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

ll phi(ll x) {
	ll ans = x;
	for(int i=2; i*i<=x; i++) {
		if(x%i == 0) {
			ans = ans/i*(i-1);
			while(x%i == 0) {
				x /= i;
			}
		}
	}
	if(x > 1)	ans = ans/x*(x-1);
	return ans;
}

ll fpow(ll a, ll b, ll mod) {
	if(a == 0)	return b==0;
	ll ans = 1;
	while(b) {
		if(b&1)	ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	if(ans == 0)	ans = mod;
	return ans;
}

ll f(ll x, ll mod) {
	if(x < 10)	return x;
	ll ph = phi(mod);
	ll p = f(x/10, ph)+ph;
	return fpow(x%10, p, mod);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld", &n, &m);
		printf("%lld\n", f(n, m)%m);
	}
    return 0;
}

