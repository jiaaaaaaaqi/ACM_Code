/***************************************************************
    > File Name    : b.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月21日 星期日 18时58分23秒
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
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[maxn];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s+1);
		int len = strlen(s+1);
		if(len == 1) {
			printf("Uncertain\n");
			return 0;
		} else {
			sort(s+1, s+1+len);
			ll ans1 = s[1]-'0';
			ll ans2=0;
			for(int i=len; i>=2; i--) {
				ans2 = ans2*10+s[i]-'0';			
			}
			printf("%lld\n", ans1+ans2);
		}
	}
	return 0;
}

