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

const LL mx = 1e6 + 5;
const LL INF = 10000000000000005;

char s[mx];
//int ara[mx];

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int t, i, j, x, y, cns, mxx;
    scanf("%d", &t);
    while(t--) {
        //memset(ara, 0, sizeof ara);
        mxx = 1;
        scanf("%s", s);
        int len = strlen(s);
        for (i = 0; i < len; i++) {
//                cout << "HI" << endl;
            if (s[i] == '>') {
                cns = 2;
                i++;
                while (s[i] != '<' && i < len) {
                    if (s[i] == '>') {
                        cns++;
                    }
                    i++;
                }
                mxx = max (cns, mxx);
                i--;
            }
            else if (s[i] == '<') {
                cns = 2;
                i++;
                while (s[i] != '>' && i < len) {
                    if (s[i] == '<') {
                        cns++;
                    }
                    i++;
                }
                mxx = max (cns, mxx);
                i--;
            }
        }
        printf ("%d\n", mxx);
    }
    return 0;
}
