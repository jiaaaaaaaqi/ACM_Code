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
const int    maxn = 3e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct SAM {
	struct Node{
        int next[27];
        int fa, len;
        void init() {
            fa = len = 0;
            mes(next, 0);
        }
    } node[maxn<<1];
    int sz, last;
    void init() {
        sz = last = 1;
        node[sz].init();
    }
    void insert(int x) {
        int p = last, np = last = ++sz;
        node[np].init();
        node[np].len = node[p].len + 1;
        for(; p&&!node[p].next[x]; p=node[p].fa)    node[p].next[x] = np;
        if(p == 0) {
            node[np].fa = 1;
        } else {
            int q = node[p].next[x];
            if(node[q].len == node[p].len+1) {
                node[np].fa = q;
            } else {
                int nq = ++sz;
                node[nq] = node[q];
                node[np].fa = node[q].fa = nq;
                node[nq].len = node[p].len + 1;
                for(; p&&node[p].next[x]==q; p=node[p].fa)  node[p].next[x] = nq;
            }
        }
    }
	int solve(char *s) {
		int len = strlen(s+1);
		int res = 0, p = 1, ans = 0;
		for(int i=1; i<=len; i++) {
			int k = s[i]-'a'+1;
			while(p && !node[p].next[k]) {
				p = node[p].fa;
				res = node[p].len;
			}
			if(!p) {
				p = 1;
				res = 0;
			} else {
				p = node[p].next[k];
				res++;
			}
			ans = max(ans, res);
		}
		return ans;
	}
} sam;
char s[maxn], t[maxn];

int main() {
	scanf("%s%s", s+1, t+1);
	sam.init();
	int len = strlen(s+1);
	for(int i=1; i<=len; i++) {
		sam.insert(s[i]-'a'+1);
	}
	int ans = sam.solve(t);
	printf("%d\n", ans);
	return 0;
}
