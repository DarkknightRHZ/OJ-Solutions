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

const int INF = 1e9 + 5;

vector <int> vi[1005];
//vector <PII> vp;
int ara[1005];
int cost[1005];
bool taken[1005];

int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    int n, m, i, j, x, y;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &ara[i]);
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        vi[x].PB(y);
        vi[y].PB(x);
    }
//    cout << "P" << endl;
    for (i = 1; i <= n; i++) {
        x = 0;
        for (j = 0; j < vi[i].size(); j++) {
            y = vi[i][j];
            x += ara[y];
        }
//        vp.PB({x, i});
        cost[i] = x;
    }
//    cout << "YES" << endl;
//    sort (vp.begin(), vp.end());
    int ans = 0;
    int mx = -1, mxi = 0;
    for (i = 1; i < n; i++, mx = -1) { /// mx should be -1, I got WA for setting mx = 0..Damn -_-
        for (j = 1; j <= n; j++) {
            if (!taken[j] && ara[j] > mx) {
                mx = ara[j];
                mxi = j;
            }
            else if (!taken[j] && ara[j] == mx && cost[j] < cost[mxi]) {
                mxi = j;
            }
        }
//        cout << mxi << " " << ara[mxi] << " " << cost[mxi] << endl;
        taken[mxi] = 1;
        ans += cost[mxi];
        for (j = 0; j < vi[mxi].size(); j++) {
            x = vi[mxi][j];
            cost[x] -= ara[mxi];
        }
    }
    printf("%d\n", ans);
    return 0;
}
