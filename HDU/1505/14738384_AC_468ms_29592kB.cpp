#include<map>
#include<set>
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
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1200;
const int maxm = 30005;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
deque< pair<int, int> > q;
char str[maxn << 2][maxn << 2];
int maps[maxn][maxn];

void init() {
	memset(maps, 0, sizeof maps);
	memset(str, 0, sizeof str);
}

int solve(int num[]) {
	int ans = 0;
	q.clear();
	for(int i=1; i<=m; i++) {
		int y = 0;
		while(!q.empty() && q.back().first > num[i]) {
			q.back().second += y;
			ans = max(ans, q.back().second * q.back().first);
			y++;
			q.pop_back();
		}
		q.push_back(make_pair(num[i], 1));
	}
	int y = 0;
	while(!q.empty()) {
		q.back().second += y;
		ans = max(ans, q.back().first * q.back().second);
		y++;
		q.pop_back();
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		getchar();
		for(int i=1; i<=n; i++) {
			int j = 1;
			char ch;
			while(scanf("%c", &ch)) {
				if(ch == 'R')	maps[i][j] = 0, j++;
				else if(ch == 'F')	maps[i][j] = maps[i-1][j] + 1, j++;
				else	continue;
				if(j == m + 1)	break;
			}
		}
		int ans = 0;
		for(int i=1; i<=n; i++) {
			int res = solve(maps[i]);
			ans = max(ans, res);
		}
		printf("%d\n", ans * 3);
	}
	return 0;
}