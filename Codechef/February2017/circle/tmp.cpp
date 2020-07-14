
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

int one[mx];
int ara[mx];

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int i, j, x, y, n, t, o1, o2, o, z,cnt;
    int tr = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &o1, &o2);
        memset(one, 0 , sizeof one);
        memset(ara, 0 , sizeof ara);
        n = o1 * o2;
        for(i = 1; i <= o1 * o2; i++) {
            scanf("%d", &ara[i]);
            one[i] = one[i-1];
            if (ara[i] == 1) {
                one[i]++;
            }
        }
        tr = 0;
        for (i = 1; i <= o2; i++) {
            o = z = 0;
            for (j = i, cnt = 1; cnt <= o1; cnt++, j += o2) {
                if (j + o2 - 1 <= n) {
                    x = one[j + o2 - 1] - one[j - 1];
                    y = o2 - x;
                }
                else {
                    x = one[n] - one[j - 1];
                    x += one[o2 - (n - j + 1)];
                    y = o2 - x;
                }
                if (x > y) {
                    o++;
                }
                else if (y > x) {
                    z++;
                }
            }
            if (o > z) {
                tr = 1;
                break;
            }
        }
//        cout << o << " " << z << endl;
        printf("%d\n",tr);
    }
    return 0;
}
