
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

const LL mx = 1e3 + 5;
const LL INF = 10000000000000005;
LL mod;
LL pCnt[mx];
bool prime[mx];
vector <LL> pR, lst;
//LL fac[mx];
LL dp[55][55];


LL m, k;

void makePrime() {
    LL i, j;
    for (i = 4; i < mx; i+= 2) {
        prime[i] = 1;
    }
    for (j = 3; j * j < mx; j++) {
        if (prime[j] == 0) {
            for (i = j * j; i < mx; i += j) {
                prime[i] = 1;
            }
        }
    }
    for (i = 2; i < mx; i++) {
        if (prime[i] == 0) pR.PB(i);
    }
}

LL solve (LL box, LL ball) {
    if (box == 1 && ball <= k) {
        return 1LL;
    }
    else if (box == 1) {
        return 0LL;
    }
    if (dp[box][ball] != -1) return dp[box][ball];
    LL i, j, res = 0, cns;
    cns = (box - 1) * k;
    i = max (ball - cns, 1LL);
    for (i = 1; i <= min (ball - box + 1, k); i++) {
        res += solve(box - 1, ball - i);
    }
//    cout << "box " << box << " " << res <<endl;
    return dp[box][ball] = res;
}

LL gcd(LL a, LL b);

LL power (LL x, LL y, LL M);

LL modInverse(LL a, LL M) {
    LL g = __gcd(a, M);
    if (g != 1LL) {
        return -1LL;
    }
    else {
        return power(a, M-2LL, M);
    }
}

LL power(LL x, LL y, LL M) {
    if (y == 0) {
        return 1LL;
    }
    LL p = power(x, y/2LL, M) % M;
    p = (p * p) % M;
    return (y%2LL == 0) ? p : (x * p) % M;
}

LL gcd(LL a, LL b) {
    if (a == 0) {
        return b;
    }
    return gcd(b%a, a);
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int t;
    bool isP = 0;
    LL n, rem, res, cns, div, i, j, l;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld %lld", &n, &k, &mod);
        isP = 1;
        LL sq = sqrt(mod);
        for (i = 2; i <= sq; i++) {
            if (mod % i == 0) {
                isP = 0;
                break;
            }
        }
        rem = n%k;
        if (n <= k) {
            printf ("1 1\n");
        }
        else if (rem == 0) {
            res = n / k;
            printf("%lld 1\n", res % mod);
        }
        else if (n <= 50 && k <= 50) {
            div = n / k;
            div++;
            cns = k - rem;
            memset(dp, -1, sizeof dp);
//            cout << div << " " << n << endl;
            res = solve(div, n);
            printf("%lld %lld\n", div, res % mod);
        }
        else if (isP == 0) {
//            cout << "YES" << endl;
            div = n / k;
            div++;
            cns = k - rem;
            LL cn = min(cns, div - 1LL);
            LL cnM = max (cns, div - 1LL);
            LL sum = cns + div - 1;
            unsigned long long int re = 1LL;
            re = 1LL;
            for (i = cnM + 1LL, j = 2LL; i <= sum; i++) {
                l = i;
                while (l % j == 0 && j <= cn) {
                    l /= j;
                    j++;
                }
                re *= l;
                while (re % j == 0 && j <= cn) {
                    re /= j;
                    j++;
                }
            }
            printf("%lld %llu\n", div, re % mod);
        }
        else {
            div = n / k;
            div++;
            cns = k - rem;
//            memset(dp, -1, sizeof dp);
//            cout << div << " " << n << endl;
//            res = solve(div, n);
//            fac[0] = 1LL;
//            for (i = 1; i < mx; i++) {
//                fac[i] = (i * fac[i-1]) % mod;
//            }
            LL cn = min (cns, div - 1LL);
            res = 1LL;
            for (i = max (cns, div - 1LL) + 1LL; i <= cns + div - 1LL; i++) {
                if (i % mod == 0) {
                    res = 0LL;
                    break;
                }
                res *= (i % mod);
                res %= mod;
            }
            LL sc = 1LL;
            for (i = 1; i <= cn; i++) {
                if (i % mod == 0) {
                    sc = 0LL;
                    break;
                }
                sc *= (i % mod);
                sc %= mod;
            }
            LL s = modInverse(sc, mod);
            res *= s;
            printf("%lld %lld\n", div, res % mod);
        }
    }
    return 0;
}

