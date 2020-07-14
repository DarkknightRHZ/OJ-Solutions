
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

//typedef unsigned long           LL;
typedef long long int           LL;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

const int mx = 1e6 + 5;

int ara[100005];
vector <int> vi[100005];

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int t, n, k, p, i, j, distinct, x;
    scanf("%d", &t);
    while(t--) {
        distinct = 0;
        memset(ara, 0, sizeof ara);
        scanf("%d %d", &n, &k);
        for (i = 0; i < n; i++) vi[i].clear();
        for (i = 0; i < n; i++) {
            scanf("%d", &p);
            for (j = 0; j < p; j++) {
                scanf("%d", &x);
                ara[x]++;
                if (ara[x] == 1) {
                    distinct++;
                }
                vi[i].PB(x);
            }
        }
        if (distinct < k) {
            printf("sad\n");
            continue;
        }
        bool some = 0, tr = 0;
        for (i = 0; i < n; i++) {
            tr = 1;
            for (j = 0; j < vi[i].size(); j++) {
                x = vi[i][j];
                if (ara[x] == 1) tr = 0;
            }
            if (tr) {
                some = 1;
                break;
            }
        }
        if (some == 1) {
            printf("some\n");
        }
        else {
            printf("all\n");
        }
    }
    return 0;
}
