/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月22日 星期三 19时40分05秒
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
const int    maxn = 2e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int block;
struct Node{
	int cnt, id;
} node[maxn];
int a[maxn], bel[maxn];

int L(int x) {
	return (x-1)*block+1;
}

void update(int p, int v) {
	a[p] = v;
	int r = p + v;
	if(r > n) {
		node[p].cnt = 1;
		node[p].id = n+1;
	} else if(bel[p] == bel[r]) {
		node[p].cnt = node[r].cnt + 1;
		node[p].id = node[r].id;
	} else {
		node[p].cnt = 1;
		node[p].id = r;
	}
	for(int i=p-1; i>=L(bel[p]); i--) {
		if(i + a[i] == p) {
			node[i].cnt = node[p].cnt+1;
			node[i].id = node[p].id;
		}
	}
}

int query(int x) {
	int id = x;
	int ans = 0;
	while(id <= n) {
		ans += node[id].cnt;
		id = node[id].id;
	}
	return ans-1;
}

int main() {
	scanf("%d", &n);
	block = sqrt(n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		bel[i] = (i-1)/block + 1;
	}
	for(int i=n; i>=1; i--) {
		int r = i+a[i];
		if(r > n) {
			node[i].cnt = 1;
			node[i].id = n+1;
		} else if(bel[i] == bel[r]) {
			node[i].cnt = node[r].cnt+1;
			node[i].id = node[r].id;
		} else {
			node[i].cnt = 1;
			node[i].id = r;
		}
	}
	// for(int i=1; i<=n; i++) {
	//     printf("%d cnt = %d id = %d\n", i, node[i].cnt, node[i].id);
	// }
	scanf("%d", &T);
	while(T--) {
		int id, x, y;
		scanf("%d", &id);
		if(id == 1) {
			scanf("%d", &x);
			int ans = query(x);
			printf("%d\n", ans);
		} else {
			scanf("%d%d", &x, &y);
			update(x+1, y);
		}
	}
	return 0;
}

