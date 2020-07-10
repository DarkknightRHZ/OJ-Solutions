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

int inv(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
       return 0;
    while (a > 1)
    {
        q = a / m;

        t = m;
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }
    if (x1 < 0)
       x1 += m0;

    return x1;
}

int findMinX(int num[], int rem[], int k)
{
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        int pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }
    return result % prod;
}
int main()
{
    #ifdef PowerIsPrayed
        freopen("get2.txt","w+",stdout);
    #endif // PowerIsPrayed
    int ara1[2], ara2[2], i, j, rem, lcm;
    for (i = 0; i < 100; i++) {
        cout << i << endl;
        cout << rand() % 100 + 1<< " " << rand() % 100 + 1 << endl;
        cout << rand() % 100  + 1<< " " << rand() % 100 + 1 << endl;
        cout<< endl;
    }
//    while (~scanf("%d %d", &ara1[0], &ara2[0])) {
//        scanf("%d %d", &ara1[1], &ara2[1]);
//        if (__gcd(ara1[0], ara1[1]) != 1) {
//            printf("-1\n");
//            continue;
//        }
//         int k = sizeof(ara1)/sizeof(ara1[0]);
//        lcm = findMinX(ara1, ara2, k);
//        printf("%d\n", lcm);
//    }
    return 0;
}
