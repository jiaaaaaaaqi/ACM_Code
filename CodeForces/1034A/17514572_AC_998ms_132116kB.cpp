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
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)	x & (-x)
#define  mes(a, b)	memset(a, b, sizeof a)
#define  fi 		first
#define  se 		second
#define  INOPEM		freopen("in.txt", "r", stdin)
#define  OUTOPEN	freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1.5e7 + 10;
const int    maxm = 1e7 + 6e5;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn];
bool ispri[maxn];
int cnt[maxn];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
    scanf("%d", &n);
    int g = 0;
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        g = gcd(g, a[i]);
    }
    for(int i=1; i<=n; i++) {
        a[i] /= g;
        cnt[a[i]]++;
    }
    int ans = inf;
    mes(ispri, true);
    for(int i=2; i<maxn; i++) {
        if(ispri[i]) {
            int res = cnt[i];
            for(int j=2; i*j<maxn; j++) {
                ispri[i*j] = false;
                res += cnt[i*j];
            }
            ans = min(ans, n - res);
        }
    }
    printf("%d\n", ans == n ? -1 : ans);
    return 0;
}