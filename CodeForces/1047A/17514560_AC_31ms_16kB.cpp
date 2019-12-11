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
#define  lowbit(x)    x & (-x)
#define  mes(a, b)    memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  INOPEM        freopen("in.txt", "r", stdin)
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

int main() {
    ll a;
    while (~scanf("%lld", &a)) {
        if ((a - 2) % 3 != 0) {
            printf("1 1 %lld\n", a - 2);
        } else {
            printf("1 2 %lld\n", a - 3);
        }
    }
    return 0;
}