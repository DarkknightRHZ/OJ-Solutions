
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
#define PLL         pair <LL,LL>
#define PLLL        pair < LL, PLL >

//typedef unsigned long           LL;
typedef long long int           LL;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

const int mx = 1e5 + 5;
const LL INF = 10000000000000005;

int deg[mx];
int ans[mx];
bool removed[mx];
int degR[mx];

vector <int> vi[mx];
vector <PII> vi2;

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int t, n, m, u, v, i, j, x, y;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        for (i = 0; i < mx; i++) {
            vi[i].clear();
        }
        vi2.clear();
        memset(deg, 0, sizeof deg);
        memset(ans, 0, sizeof ans);
        memset(removed, 0, sizeof removed);
        memset(degR, 0, sizeof degR);
        for (i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            u--, v--;
            vi[u].PB(v);
            vi[v].PB(u);
            deg[u]++;
            deg[v]++;
        }
        for (i = 0; i < n; i++) {
            if (deg[i] > 0) {
                vi2.PB({deg[i], i});
            }
        }
        sort(vi2.begin(), vi2.end());
//        for (i = 0; i < vi2.size(); i++) {
//            cout << vi2[i].second << " " << vi2[i].first << endl;;
//        }
        for (i = 0; i < n; i++) {
            if (deg[i] == 0) {
                    ans[0]++;
                    removed[i] = 1;
            }
        }
        if (ans[0] == n) ans[0]--;
        int cns, cnt;
        for (i = 0; i < vi2.size(); i++) {
            x = vi2[i].second;
            if (removed[x]) continue;
            cns = vi2[i].first;
            cnt = 1;
            for (j = 0; j < vi[x].size(); j++) {
                y = vi[x][j];
                degR[y]++;
                if (degR[y] == deg[y] && !removed[y]) {
                    removed[y] = 1;
                    cnt++;
                }
            }
            ans[cns] += cnt;
            ans[cns] = min (ans[cns], n - 1);
            removed[x] = 1;
        }
        for (i = 1; i < n; i++) {
            ans[i] += ans[i - 1];
            ans[i] = min (ans[i], n - 1);
        }
        for (i = 0; i < n; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}

