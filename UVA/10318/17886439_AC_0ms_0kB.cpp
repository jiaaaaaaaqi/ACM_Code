/*
		  .
		 ';;;;;.
		'!;;;;;;!;`
	   '!;|&#@|;;;;!:
	  `;;!&####@|;;;;!:
	 .;;;!&@$$%|!;;;;;;!'.`:::::'.
	 '!;;;;;;;;!$@###&|;;|%!;!$|;;;;|&&;.
	 :!;;;;!$@&%|;;;;;;;;;|!::!!:::;!$%;!$%`	'!%&#########@$!:.
	 ;!;;!!;;;;;|$$&@##$;;;::'''''::;;;;|&|%@$|;;;;;;;;;;;;;;;;!$;
	 ;|;;;;;;;;;;;;;;;;;;!%@#####&!:::;!;;;;;;;;;;!&####@%!;;;;$%`
	`!!;;;;;;;;;;!|%%|!!;::;;|@##%|$|;;;;;;;;;;;;!|%$#####%;;;%&;
	:@###&!:;;!!||%%%%%|!;;;;;||;;;;||!$&&@@%;;;;;;;|$$##$;;;%@|
	;|::;;;;;;;;;;;;|&&$|;;!$@&$!;;;;!;;;;;;;;;;;;;;;;!%|;;;%@%.
   `!!;;;;;;;!!!!;;;;;$@@@&&&&&@$!;!%|;;;;!||!;;;;;!|%%%!;;%@|.
%&&$!;;;;;!;;;;;;;;;;;|$&&&&&&&&&@@%!%%;!||!;;;;;;;;;;;;;$##!
!%;;;;;;!%!:;;;;;;;;;;!$&&&&&&&&&&@##&%|||;;;!!||!;;;;;;;$&:
':|@###%;:;;;;;;;;;;;;!%$&&&&&&@@$!;;;;;;;!!!;;;;;%&!;;|&%.
 !@|;;;;;;;;;;;;;;;;;;|%|$&&$%&&|;;;;;;;;;;;;!;;;;;!&@@&'
  .:%#&!;;;;;;;;;;;;;;!%|$$%%&@%;;;;;;;;;;;;;;;;;;;!&@:
  .%$;;;;;;;;;;;;;;;;;;|$$$$@&|;;;;;;;;;;;;;;;;;;;;%@%.
	!&!;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;|@#;
	 `%$!;;;;;;;;;;;$@|;;;;;;;;;;;;;;;;;;;;;;;;!%$@#@|.
	   .|@%!;;;;;;;;;!$&%||;;;;;;;;;;;;;;;;;!%$$$$$@#|.
		   ;&$!;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;%#####|.
		   |##$|!;;;;;;::'':;;;;;;;;;;;;;!%$$$@#@;
		  ;@&|;;;;;;;::'''''':;;;;;;;|$&@###@|`
		.%##@|;;;;:::''''''''''::;!%&##$'
	  `$##@$$@@&|!!;;;:'''''::::;;;;;|&#%.
	;&@##&$%!;;;;;;::''''''''::;!|%$@#@&@@:
	 .%@&$$|;;;;;;;;;;:'''':''''::;;;%@#@@#%.
	:@##@###@$$$$$|;;:'''':;;!!;;;;;;!$#@@#$;`
	 `%@$$|;;;;;;;;:'''''''::;;;;|%$$|!!&###&'
	 |##&%!;;;;;::''''''''''''::;;;;;;;!$@&:`!'
	:;!@$|;;;;;;;::''''''''''':;;;;;;;;!%&@$:				 !@#$'
	  |##@@&%;;;;;::''''''''':;;;;;;;!%&@#@$%:			  '%%!%&;
	  |&%!;;;;;;;%$!:''''''':|%!;;;;;;;;|&@%||`			'%$|!%&;
	  |@%!;;!!;;;||;:'''''':;%$!;;;;!%%%&#&%$&:		   .|%;:!&%`
	  !@&%;;;;;;;||;;;:''::;;%$!;;;;;;;|&@%;!$;		  `%&%!!$&:
	  '$$|;!!!!;;||;;;;;;;;;;%%;;;;;;;|@@|!$##;		 !$!;:!$&:
	   |#&|;;;;;;!||;;;;;;;;!%|;;;;!$##$;;;;|%'	  `%$|%%;|&$'
		|&%!;;;;;;|%;;;;;;;;$$;;;;;;|&&|!|%&&;  .:%&$!;;;:!$@!
		`%#&%!!;;;;||;;;;;!$&|;;;!%%%@&!;;;!!;;;|%!;;%@$!%@!
		!&!;;;;;;;;;||;;%&!;;;;;;;;;%@&!;;!&$;;;|&%;;;%@%`
	   '%|;;;;;;;;!!|$|%&%;;;;;;;;;;|&#&|!!||!!|%$@@|'
	   .!%%&%'`|$;	   :|$#%|@#&;%#%.
*/
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

int dcnt;
int ans;
int a[100];
int ana[100];
int dis[10][2];
int maps[10][10];

void init() {
	dcnt = 0;
	mes(a, 0);
	mes(dis, 0);
	mes(ana, 0);
	mes(maps, 0);
}

void dfs(int x, int y, int cnt) {
//	printf("%d %d\n",x, y);
    if(x == n + 1) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(maps[i][j] == 0) {
                    return ;
                }
            }
        }
        if(cnt <= ans) {
            for(int i=1; i<=cnt; i++) {
                ana[i] = a[i];
            }
            ans = cnt;
        }
        return ;
    }
    for(int i=1; i<=x-2; i++) {
        for(int j=1; j<=m; j++) {
            if(maps[i][j] == 0) {
                return ;
            }
        }
    }
    if(cnt >= ans)	return ;
    int tx, ty;
    if(y != m) {
		tx = x;
        ty = y+1;
    } else {
        tx = x+1;
        ty = 1;
    }
    dfs(tx, ty, cnt);
    if(tx > n)	return ;
    a[cnt+1] = (tx-1)*m+ty;
    for(int i=1; i<=dcnt; i++) {
        int nx = tx + dis[i][0];
        int ny = ty + dis[i][1];
        if(nx <= 0 || ny <= 0 || nx > n || ny > m)
            continue;
        maps[nx][ny] = !maps[nx][ny];
    }
    dfs(tx, ty, cnt+1);
    a[cnt+1] = 0;
    for(int i=1; i<=dcnt; i++) {
        int nx = tx + dis[i][0];
        int ny = ty + dis[i][1];
        if(nx <= 0 || ny <= 0 || nx > n || ny > m)
            continue;
        maps[nx][ny] = !maps[nx][ny];
    }
}

int main() {
    cas = 1;
    while(scanf("%d%d", &n, &m), n||m) {
		init();
        char s[4][4];
        for(int i=1; i<=3; i++) {
            scanf("%s", s[i]+1);
            for(int j=1; j<=3; j++) {
                if(s[i][j] == '*') {
                    dcnt++;
                    dis[dcnt][0] = i-2;
                    dis[dcnt][1] = j-2;
                }
            }
        }
        ans = inf;
        dfs(1, 0, 0);
        printf("Case #%d\n", cas++);
        if(ans == inf)	printf("Impossible.\n");
        else {
            for(int i=1; i<=ans; i++) {
                printf("%d%c", ana[i], i==ans ? '\n' : ' ');
            }
        }
    }
    return 0;
}
