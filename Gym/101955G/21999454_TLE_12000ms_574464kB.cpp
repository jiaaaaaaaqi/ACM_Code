/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Mon 30 Sep 2019 10:38:35 PM CST
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
#include <unordered_map>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 6e3 + 10;
const int    maxm = 1e7;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int maps[maxn][maxn];
vector<pii> vv[maxm+10];

bool ok(int x) {
	if(x<0 || x>6000)	return false;
	return true;
}

int main() {
	// freopen("in", "r", stdin);
	for(int i=-3200; i<=3200; i++) {
		for(int j=-3200; j<=3200; j++) {
			if(i*i+j*j <= maxm)
				vv[i*i+j*j].pb(make_pair(i, j));
		}
	}
	scanf("%d", &T);
	cas = 1;
	while(T--) {
		printf("Case #%d:\n", cas++);
		mes(maps, 0);
		scanf("%d%d", &n, &m);
		for(int i=1, x, y, w; i<=n; i++) {
			scanf("%d%d%d", &x, &y, &w);
			maps[x][y] += w;
		}
		int ans = 0;
		int id, x, y, w, k;
		while(m--) {
			scanf("%d%d%d", &id, &x, &y);
			x = (x+ans)%6000+1;
			y = (y+ans)%6000+1;
			if(id == 1) {
				scanf("%d", &w);
				maps[x][y] += w;
			} else if(id == 2) {
				maps[x][y] = 0;
			} else if(id == 3) {
				scanf("%d%d", &k, &w);
				int tx, ty;
				for(auto i : vv[k]) {
					tx = x+i.fi, ty = y+i.se;
					if(ok(tx) && ok(ty) && maps[tx][ty])	maps[tx][ty] += w;
					// tx = x-i.fi, ty = y+i.se;
					// if(ok(tx) && ok(ty) && maps[tx][ty])	maps[tx][ty] += w;
					// tx = x+i.fi, ty = y-i.se;
					// if(ok(tx) && ok(ty) && maps[tx][ty])	maps[tx][ty] += w;
					// tx = x-i.fi, ty = y-i.se;
					// if(ok(tx) && ok(ty) && maps[tx][ty])	maps[tx][ty] += w;
				}
			} else {
				scanf("%d", &k);
				int tx, ty;
				ans = 0;
				for(auto i : vv[k]) {
					tx = x+i.fi, ty = y+i.se;
					if(ok(tx) && ok(ty) && maps[tx][ty])	ans += maps[tx][ty];
					// tx = x-i.fi, ty = y+i.se;
					// if(ok(tx) && ok(ty) && maps[tx][ty])	ans += maps[tx][ty];
					// tx = x+i.fi, ty = y-i.se;
					// if(ok(tx) && ok(ty) && maps[tx][ty])	ans += maps[tx][ty];
					// tx = x-i.fi, ty = y-i.se;
					// if(ok(tx) && ok(ty) && maps[tx][ty])	ans += maps[tx][ty];
				}
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}

