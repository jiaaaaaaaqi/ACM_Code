/*
          .
         ';;;;;.
        '!;;;;;;!;`
       '!;|&#@|;;;;!:
      `;;!&####@|;;;;!:
     .;;;!&@$$%|!;;;;;;!'.`:::::'.
     '!;;;;;;;;!$@###&|;;|%!;!$|;;;;|&&;.
     :!;;;;!$@&%|;;;;;;;;;|!::!!:::;!$%;!$%`    '!%&#########@$!:.
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
    :;!@$|;;;;;;;::''''''''''':;;;;;;;;!%&@$:                 !@#$'
      |##@@&%;;;;;::''''''''':;;;;;;;!%&@#@$%:              '%%!%&;
      |&%!;;;;;;;%$!:''''''':|%!;;;;;;;;|&@%||`            '%$|!%&;
      |@%!;;!!;;;||;:'''''':;%$!;;;;!%%%&#&%$&:           .|%;:!&%`
      !@&%;;;;;;;||;;;:''::;;%$!;;;;;;;|&@%;!$;          `%&%!!$&:
      '$$|;!!!!;;||;;;;;;;;;;%%;;;;;;;|@@|!$##;         !$!;:!$&:
       |#&|;;;;;;!||;;;;;;;;!%|;;;;!$##$;;;;|%'      `%$|%%;|&$'
        |&%!;;;;;;|%;;;;;;;;$$;;;;;;|&&|!|%&&;  .:%&$!;;;:!$@!
        `%#&%!!;;;;||;;;;;!$&|;;;!%%%@&!;;;!!;;;|%!;;%@$!%@!
        !&!;;;;;;;;;||;;%&!;;;;;;;;;%@&!;;!&$;;;|&%;;;%@%`
       '%|;;;;;;;;!!|$|%&%;;;;;;;;;;|&#&|!!||!!|%$@@|'
       .!%%&%'`|$;       :|$#%|@#&;%#%.
*/
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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 66666;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

ll n, m;
int cas, tol, T;

struct Node {
    int id;
    ll ans;
    int next;
} node[maxn];
int head[maxn];

void addnode(ll x, int id) {
    ll u = x % mod;
    node[tol].id = id;
    node[tol].ans = x;
    node[tol].next = head[u];
    head[u] = tol++;
}

int find(ll x) {
    ll u = x % mod;
    for(int i=head[u]; ~i; i=node[i].next) {
        if(node[i].ans == x)    return node[i].id;
    }
    return -1;
}

ll bsgs(ll a, ll b, ll p) {
    if(b == 1)  return 0;
    m = sqrt(1.0*p);
    ll ans = 1ll;
    for(int i=0; i<m; i++) {
        addnode(ans * b % p, i);
        // printf("%lld %d\n", ans*b%p, i);
        ans = ans * a % p;
    }
    ll Am = ans;
    ans = 1ll;
    for(ll i=m; ; i+=m) {
//        printf("%lld\n", ans);
        int j = find(ans = Am * ans % p);
        if(j != -1) return i-j;
        if(i > p)   break;
    }
    return -1;
}

int main() {
    ll a, b, p;
    while(~scanf("%lld%lld%lld", &p, &a, &b)) {
        tol = 0;
        mes(head, -1);
        ll ans = bsgs(a, b, p);
        if(ans == -1) {
            printf("no solution\n");
        } else {
            printf("%lld\n", ans);
        }
    }
    return 0;
}
