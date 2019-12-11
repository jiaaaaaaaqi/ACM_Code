/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月06日 星期一 19时41分51秒
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

int n, m;
int cas, tol, T;

struct Node{
	char id;
	double val;
} node[maxn];
vector<double> vv;
int a[maxn];

int getid(double x) {
	return lower_bound(vv.begin(), vv.end(), x) - vv.begin() + 1;
}

void update(int l, int r) {
	a[l] = a[l]+1;
	a[r+1] = a[r+1]-1;
}

int main() {
	while(~scanf("%d", &n)) {
		mes(a, 0);
		vv.clear();
		int x1, y1, x2, y2;
		scanf("%d%d", &x1, &y1);
		tol = 0;
		int cnt = 0;
		for(int i=2; i<=n; i++) {
			scanf("%d%d", &x2, &y2);
			if(y1 == y2) {
				cnt ++;
				continue;
			}
			if(x1 == x2)	cnt++;
			double y = y1-y2;
			double x = x2-x1;
			node[++tol].val = x/y;
			if(y<0)	node[tol].id = '>';
			else	node[tol].id = '<';
			vv.push_back(node[tol].val);
		}
		sort(vv.begin(), vv.end());
		for(int i=1; i<=tol; i++) {
			int id = getid(node[i].val);
			if(node[i].id == '>')	update(id, vv.size());
			else	update(1, id);
		}
		for(int i=1; i<=vv.size(); i++) {
			a[i] = a[i-1]+a[i];
		}
		for(int i=1; i<=vv.size(); i++) {
			// printf("a[%d] = %d\n", i, a[i]);
		}
		int ans1, ans2;
		ans1 = -inf, ans2 = inf;
		for(int i=1; i<=vv.size(); i++) {
			ans1 = max(ans1, a[i]);
			ans2 = min(ans2, a[i]);
		}
		if(ans1 == -inf)	ans1 = 1;
		if(ans2 == inf)		ans2 = 1;
		printf("%d %d\n", ans2, ans1+cnt);
	}
	return 0;
}

/*
2
100 100
100 110
*/
