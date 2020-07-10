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

vector <int> vi[100005];
int range[100005];

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int cnt, n, m, k, i, j, x, y, l, r;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &x);
            vi[j].PB(x);
        }
    }
    cnt = 1;
    for (i = 0; i <= n; i++) {
        range[i] = 1;
    }
    for (i = 0; i < m; i++) {
        cnt = 1;
        for (j = 1; j < n; j++) {
            if (vi[i][j] >= vi[i][j-1]) {
                cnt++;
                range[j + 1] = max(range[j + 1], cnt);
            }
            else {
                cnt = 1;
            }
        }
    }
    scanf("%d", &k);
    for (i = 0; i < k; i++) {
        scanf("%d %d", &l, &r);
        cnt = r - l  + 1;
        if (cnt <= range[r]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
