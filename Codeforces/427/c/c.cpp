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

int ans[15][105][105];
int cum[15][105][105];
bool pick[105][105];
vector <PII> vpi;
vector <int> vi[105][105];

int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    int n, q, c, i, j, x, y, s, k, cns, sum, t1, x1, y1, x2, y2;
    scanf("%d %d %d", &n, &q, &c);
//    cout << n << " " << q << " " << c << endl;
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &y, &s);
        vi[x][y].PB(s);
        if (!pick[x][y]) {
                vpi.PB({x,y});
                pick[x][y] = 1;
        }
    }
    for (i = 0; i <= c; i++) {
        for (j = 0; j < vpi.size(); j++) {
            x = vpi[j].first;
            y = vpi[j].second;
            sum = 0;
            for (k = 0; k < vi[x][y].size(); k++) {
                s = vi[x][y][k];
                cns = s + (i);
                cns %= (c+1);
                sum += cns;
            }
            ans[i][x][y] = sum;
        }
    }
    for (k = 0; k <= c; k++) {
        for (i = 0; i < 105; i++) {
            for (j = 104; j >= 0; j--) {
                cum[k][i][j] = ans[k][i][j] + cum[k][i][j+1];
            }
        }
    }
//    cout << q << endl;
    for (i = 0; i < q; i++) {
        scanf("%d %d %d %d %d", &t1, &x1, &y1, &x2, &y2);
//        cout << t1 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        cns = t1 % (c+1);
        sum = 0;
        for (j = x1; j <= x2; j++) {
            sum += (cum[cns][j][y1] - cum[cns][j][y2+1]);
        }
        printf ("%d\n", sum);
    }
    return 0;
}
