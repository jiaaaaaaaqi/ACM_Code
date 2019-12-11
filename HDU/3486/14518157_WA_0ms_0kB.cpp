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
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 200005;
const int maxm = 305;
using namespace std;

int n, m, tol;
deque< pair<int, int> > q;
int num[maxn];
int dp[maxn][20];

void RMQ_ST() {
    for(int i=1; i<=n; i++) {
        dp[i][0] = num[i];
    }
    for(int j=1; (1<<j)<=n; j++) {
        for(int i=1; i<=n; i++) {
			dp[i][j] = dp[i][j-1];
			if(i + (1<<(j - 1)) <= n)
				dp[i][j] = max(dp[i][j - 1], dp[i + (1<<(j - 1))][j - 1]);
        }
    }
}

int RMQ_FIND(int l, int r) {
    int k = log2(r - l + 1);
    return max(dp[l][k], dp[r - (1 << k) + 1][k]);
}

int find(int x, int y) {
    int ans = 0;
    for(int i=1; i<=x; i++) {
        ans += RMQ_FIND((i-1)*y+1, i*y);
    }
    return ans;
}

int main() {
    while(scanf("%d%d", &n, &m), n!=-1 && m!=-1) {
        int sum = 0;
        int x = 0;
        for(int i=1; i<=n; i++) {
            scanf("%d", &num[i]);
            sum += num[i];
            x = max(x, num[i]);
        }
        if(sum < m) {
            printf("-1\n");
            continue;
        }
        if(x > m) {
            printf("1\n");
            continue;
        }
        RMQ_ST();
        int left = 1;
        int right = n;
        int ans;
        while(left < right) {
        	int mid = (left + right) >> 1;
        	int now = find(n/mid, mid);
        	if(now <= m) {
        		right = mid - 1;
        	} else {
        		ans = mid;
        		left = mid + 1;
        	}
        }
        printf("%d\n", ans);
    }
    return 0;
}
