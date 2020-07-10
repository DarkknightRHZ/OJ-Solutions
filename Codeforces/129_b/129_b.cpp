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

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}
int mark[105];
int deg[105];
int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    vector <int> vi[105];
    int n, m, i, j, cnt = 0, x, y;
    bool tr;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        vi[x].PB(y);
        vi[y].PB(x);
        deg[x]++;
        deg[y]++;
    }
    while (1) {
        tr = 0;
        memset(mark, 0, sizeof mark);
        for (i = 1; i <= n; i++) {
            if (deg[i] == 1) {
                mark[i] = 1;
                tr = 1;
            }
        }
        if (!tr) break;
        cnt++;
        for (i = 1; i <= n; i++) {
            if (mark[i] && deg[i] == 1) {
                deg[i]--;
                for (j = 0; j < vi[i].size(); j++) {
                    x = vi[i][j];
                    deg[x]--;
                }
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
