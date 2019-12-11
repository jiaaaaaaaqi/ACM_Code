#include<map>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
const int maxm = 1000;
using namespace std;

int n, m, tol;
struct Node {
	int u;
	int v;
	int w;
	int next;
};
Node node[maxn * maxn];
int head[maxn];
int dep[maxn];
queue<int > q;

void init() {
	tol = 0;
	memset(head, -1, sizeof(head));
	memset(node, 0, sizeof(node));
}

void addnode(int u, int v, int w) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].w = w;
	node[tol].next = head[u];
	head[u] = tol++;
}

bool bfs(int src, int des) {
	while(!q.empty())	q.pop();
	memset(dep, 0, sizeof(dep));
	dep[src] = 1;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(u == des)	return true;
		for(int i = head[u]; ~i; i = node[i].next) {
			int v = node[i].v;
			if(!dep[v] && node[i].w) {
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	return false;
}

int dfs(int src, int des, int flow) {
	if(src == des)	return flow;
	int ans = 0;
	for(int i = head[src]; ~i; i = node[i].next) {
		int v = node[i].v;
		if(dep[v] == dep[src] + 1 && node[i].w) {
			int tmp = dfs(v, des, min(node[i].w, flow - ans));
			node[i].w -= tmp;
			node[i^1].w += tmp;
			ans += tmp;
			if(ans == flow)	return ans;
		}
	}
	if(!ans)	dep[src] = -1;
	return ans;
}

int dinic(int src, int des) {
	int ans = 0;
	while(bfs(src, des)) {
		ans += dfs(src, des, inf);
	}
	return ans;
}

int main() {
	int T;
	scanf("%s", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		init();
		int x, y;
		int src = 1, des = 1;
		int minx = inf;
		int maxx = -inf;
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &x, &y);
			if(minx > x)	minx = x, src = i;
			if(maxx < x)	maxx = x, des = i;
		}
		int u, v, w;
		for(int i=1; i<=m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			addnode(u, v, w);
			addnode(v, u, w);
		}
		int ans = dinic(src, des);
		printf("%d\n", ans);
	}
	return 0;
}
