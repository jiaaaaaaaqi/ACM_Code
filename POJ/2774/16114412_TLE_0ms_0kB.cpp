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
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  INOPEM     freopen("in.txt", "r", stdin)
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

ull seed = 131;
char s1[maxn];
char s2[maxn];
ull h1[maxn];
ull h2[maxn];
ull fp[maxn];

void init() {
    mes(s1, 0);
    mes(s2, 0);
    mes(h1, 0);
    mes(h2, 0);
}

bool find(ull ans, int l, int l2) {
    for (int i = 0; i + l <= l2; i++) {
        ull tmp = h2[i] - h2[i + l] * fp[l];
        if (tmp == ans)
            return true;
    }
    return false;
}

int main() {
    init();
    scanf("%s%s", s1, s2);
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    fp[0] = 1;
    for (int i = 1; i <= max(l1, l2); i++)
        fp[i] = fp[i-1] * seed;
    h1[l1] = 0;
    h2[l2] = 0;
    for (int i = l1 - 1; i >= 0; i--)
        h1[i] = h1[i + 1] * seed + s1[i];
    for (int i = l2 - 1; i >= 0; i--)
        h2[i] = h2[i + 1] * seed + s2[i];
    int ans = 0;
    for (int l = min(l1, l2); l > 0; l--) {
        for (int i = 0; i + l <= l1; i++) {
            ull tmp = h1[i] - h1[i + l] * fp[l];
            if (find(tmp, l, l2)) {
                ans = l;
                break;
            }
        }
        if (ans)
            break;
    }
    printf("%d\n", ans);
    return 0;
}