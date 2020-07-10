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

int main()
{
    #ifdef O_Amay_Valo_Basheni
//        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int i,j,x,y,d,h,w,t,rem,div;
    scanf("%d",&t);
    while (t--){
        scanf("%d %d %d", &h, &w, &d);
        div = (w - 1) * 2;
        rem = h % div;
        if (rem <= w && rem > 0) {
            if (rem == d) {
                printf("Yes\n");
            }
            else printf("No\n");
        }
        else {
            if (rem == 0) rem = (w - 1) * 2;
            rem -= w;
            rem = w - rem;
            if (rem == d) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
