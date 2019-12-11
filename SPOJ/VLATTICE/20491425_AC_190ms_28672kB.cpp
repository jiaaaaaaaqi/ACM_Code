/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月16日 星期二 18时54分24秒
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
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

ll n, m;
int cas, tol, T;

int pri[maxn], mob[maxn], phi[maxn];
bool ispri[maxn];

void handle() {
	mes(pri, 0);
	mes(ispri, 1);
	tol = 0;
	int mx = 1e6;
	mob[1] = 1;
	phi[1] = 0;
	for(int i=2; i<=mx; i++) {
		if(ispri[i]) {
			phi[i] = i-1;
			pri[++tol] = i;
			mob[i] = -1;
		}
		for(int j=1; j<=tol&&i*pri[j]<=mx; j++) {
			ispri[i*pri[j]] = false;
			if(i%pri[j] == 0) {
				phi[i*pri[j]] = phi[i]*pri[j];
				mob[i*pri[j]] = 0;
				break;
			} else {
				phi[i*pri[j]] = phi[i]*(pri[j]-1);
				mob[i*pri[j]] = -mob[i];
			}
		}
	}
}

ll calc(ll i, ll n) {
	return 1ll*(n/i)*(n/i)*(n/i) + 3ll*(n/i)*(n/i) + 3ll*(n/i);
}

int main() {
	handle();
	scanf("%d", &T);
	// for(int i=1; i<=5; i++) {
	//     printf("mob%d = %d\n", i, mob[i]);
	// }
	while(T--) {
		scanf("%lld", &n);
		ll ans = 0ll;
		for(int i=1; i<=n; i++) {
			ans += 1ll*mob[i]*calc(i, n);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

