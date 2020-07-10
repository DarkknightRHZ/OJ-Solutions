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

bool morty[10004];
bool rick[10004];

int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    int n, m, i, j, k, x, y;
    bool tr = 0, del = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        memset(morty, 0, sizeof morty);
        memset(rick, 0, sizeof rick);
        scanf("%d", &k);
        tr = 0;
        for (j = 0; j < k; j++) {
            scanf("%d", &x);
            if (x < 0) {
                y = -x;
                rick[y] = 1;
                if (morty[y]) tr = 1;
            }
            else if (x >= 0) {
                y = x;
                morty[y] = 1;
                if (rick[y]) tr = 1;
            }
        }
        if (!tr) del = 1;
    }
    if (del) printf("YES\n");
    else printf("NO\n");
    return 0;
}
