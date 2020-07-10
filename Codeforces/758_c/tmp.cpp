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
const LL INF = 1e18;
int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

LL ara[210][210];

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL n,m,k,x,y,i,j,rowC,remS,row,rem,div,ansMin,ansMax,ansX, cns;
    while (~scanf("%I64d %I64d %I64d %I64d %I64d", &n, &m, &k, &x, &y)) {
        memset(ara, 0, sizeof ara);
        row = n + max(0LL,n - 2);
        remS = k % m;
        rowC = k / m;
        rem = rowC % row;
        div = rowC / row;
//        cout << "row "  << row << " remS " << remS << " rowC " << rowC << " rem " << rem << " div " << div << endl;
        for (i = 1; i <= row; i++) {
            for (j = 1; j <= m; j++) {
                ara[i][j] = div;
                if (i <= rem) {
                    ara[i][j]++;
                }
                else if (i == rem + 1 && j <= remS) {
                    ara[i][j]++;
                }
            }
        }
        ansX = ara[x][y];
        if (x > 1 && x < n) ansX += ara[row + 2 - x][y];
        ansMin = INF;
        ansMax = 0;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cns = ara[i][j];
                if (i > 1 && i < n) {
                    cns += ara[row - i + 2][j];
                }
                ansMin = min(ansMin, cns);
                ansMax = max(ansMax, cns);
            }
        }
        printf("%I64d %I64d %I64d\n", ansMax, ansMin, ansX);
    }
    return 0;
}
