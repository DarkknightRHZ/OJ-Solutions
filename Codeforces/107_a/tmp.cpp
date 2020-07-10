/**


  ######                                                                     ######   #     #  #######
  #     #    ##    #####   #    #  #    #  #    #  #   ####   #    #  #####  #     #  #     #       #
  #     #   #  #   #    #  #   #   #   #   ##   #  #  #    #  #    #    #    #     #  #     #      #
  #     #  #    #  #    #  ####    ####    # #  #  #  #       ######    #    ######   #######     #
  #     #  ######  #####   #  #    #  #    #  # #  #  #  ###  #    #    #    #   #    #     #    #
  #     #  #    #  #   #   #   #   #   #   #   ##  #  #    #  #    #    #    #    #   #     #   #
  ######   #    #  #    #  #    #  #    #  #    #  #   ####   #    #    #    #     #  #     #  #######



**/
/*

    BismiLLAHIR RAHMANIR RAHIM
    It's not how you look or who you are underneath, it's what you do that defines you

                                ------********-------

    Status : ;
    TC: xxx/xxx;
    DOS: ;
    OJ: ;

*/

#include <bits/stdc++.h>

using namespace std;

#define PB          push_back
#define PF          push_front
#define  V          vector
#define PII         pair <int,int>

typedef long long int           LL;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int INF = 1e9 + 5;

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

struct node {
    int x, y, d;
    node() {
        x = y = d = 0;
    }
};

int to[1005];
int from[1005];
int dm[1005][1005];


int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    int n, m, i, j, x, y, cns, u, v, d;
    vector <node> vi;
    node nd;
    memset(to, -1, sizeof to);
    memset(from, -1, sizeof from);
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &d);
        to[x] = y;
        from[y] = x;
        dm[x][y] = d;
    }
    for (i = 1; i <= n; i++) {
        if (from[i] == -1 && to[i] != -1) { ///I have to check both - if there's an incoming pipe and if there's an outgoing pipe. Got a WA for not doing the second check
            u = i;
            cns = INF;
            for (j = u; to[j] != -1; j = to[j]) {
                cns = min(cns, dm[j][to[j]]);
            }
            v = j;
            nd.x = u; nd.y = v; nd.d = cns;
            vi.PB(nd);
        }
    }
    printf("%d\n", vi.size());
    for (i = 0; i < vi.size(); i++) {
        printf("%d %d %d\n", vi[i].x, vi[i].y, vi[i].d);
    }
    return 0;
}
