
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

const LL mx = 1e5 + 5;
const LL INF = 10000000000000005;

vector <int> vi;
int ara[mx];

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int t, n, i, j, x, y;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        vi.clear();
        vi.PB(-1);
        memset(ara, 0, sizeof ara);
        for (i = 0; i < 2 * n; i++) {
            scanf("%d", &x);
            vi.PB(x);
        }
        sort(vi.begin(), vi.end());
        for (i = 1; i <= n; i++) {
            ara[i * 2 - 1] = vi[i + n];
            ara[i * 2] = vi[i];
        }
        x = n / 2;
        x++;
        printf("%d\n", ara[x * 2 - 1]);
        for (i = 1; i <= 2 * n; i++) {
            printf("%d ", ara[i]);
        }
        printf("\n");
    }
    return 0;
}

