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

//int inv(int a, int m)
//{
//    int m0 = m, t, q;
//    int x0 = 0, x1 = 1;
//
//    if (m == 1)
//       return 0;
//    while (a > 1)
//    {
//        q = a / m;
//
//        t = m;
//        m = a % m, a = t;
//
//        t = x0;
//
//        x0 = x1 - q * x0;
//
//        x1 = t;
//    }
//    if (x1 < 0)
//       x1 += m0;
//
//    return x1;
//}
//
//int findMinX(int num[], int rem[], int k)
//{
//    int prod = 1;
//    for (int i = 0; i < k; i++)
//        prod *= num[i];
//    int result = 0;
//    for (int i = 0; i < k; i++)
//    {
//        int pp = prod / num[i];
//        result += rem[i] * inv(pp, num[i]) * pp;
//    }
//    return result % prod;
//}
int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
        //freopen("got2.txt","w+",stdout);
    #endif // PowerIsPrayed

    ///Always remember, Codeforces A number problems get Accepted in time limit of 1 second with a constraint as big as 10^8 -_-

    int a, b, c, d, i, j;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    for (i = 0; i <= 10000; i++) {
        for (j = 0; j <= 10000; j++) {
            if (a * i + b == j * c + d) {
                printf("%d\n", a * i + b);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}