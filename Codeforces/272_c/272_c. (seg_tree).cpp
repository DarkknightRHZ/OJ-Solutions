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

const LL mx = 1e5 + 5;

struct info {
    LL prop, val;
} tree[mx * 4];

void update(LL node, LL b, LL e, LL i, LL j, LL x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].val = x;
        tree[node].prop = x;
        return;
    }
    LL Left = node * 2;
    LL Right = (node * 2) + 1;
    LL mid = (b + e) / 2;
    if (tree[node].prop != -1) {
        tree[Left].val = tree[Left].prop = tree[node].prop;
        tree[Right].val = tree[Right].prop = tree[node].prop;
        tree[node].prop = -1;
    }
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].val = max (tree[Left].val, tree[Right].val);
}

LL query(LL node, LL b, LL e, LL i, LL j)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].val;
    LL Left = node << 1;
    LL Right = (node << 1) + 1;
    LL mid = (b + e) >> 1;
    if (tree[node].prop != -1) {
        tree[Left].val = tree[Left].prop = tree[node].prop;
        tree[Right].val = tree[Right].prop = tree[node].prop;
        tree[node].prop = -1;
    }
    LL p1 = query(Left, b, mid, i, j);
    LL p2 = query(Right, mid + 1, e, i, j);

    return max (p1, p2);
}

int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    LL n, m, i, j, x, y, ret;
    scanf("%I64d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%I64d", &x);
        update(1, 1, n, i, i, x);
    }
    scanf("%I64d", &m);
    for (i = 1; i <= m; i++) {
        scanf("%I64d %I64d", &x, &y);
//        cout << x << " " << y << endl;
        ret = query(1, 1, n, 1, x);
        printf("%I64d\n", ret);
        update(1, 1, n, 1, x, ret + y);
    }
    return 0;
}
