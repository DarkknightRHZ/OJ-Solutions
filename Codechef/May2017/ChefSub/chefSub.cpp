
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

const int mx = 2 * (1e5 + 5);
const int lim = 2 * (1e5);

char s[100005];

int ara[mx];
int arr[mx];
int tree[mx * 4];

void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = max (tree[Left], tree[Right]);
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return -1;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return max (p1, p2);
}
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = max (tree[Left], tree[Right]);
}


int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int n, k, p, i, j, l, x, y, cns = 0, cnt = 0, K;
    scanf("%d %d %d", &n, &K, &p);
    k = min(n, K);
    int beg = lim - n + 1;
    int en = lim;
    for (i = beg, j = 0; j < n ; i++, j++) {
        scanf("%d", &ara[i]);
    }
    for (j = lim, i = beg - 1; i >= 1; i--, j--) {
        ara[i] = ara[j];
    }
    scanf("%s", s);
    int len = strlen(s);
    for (i = 1; i <= k; i++) {
        if (ara[i] == 1) cnt++;
    }
    arr[k] = cnt;
    for (i = k + 1; i <= lim; i++) {
        if (ara[i - k] == 1) cnt--;
        if (ara[i] == 1) cnt++;
        arr[i] = cnt;
    }
    init(1,1,lim);
//    for (i = beg-2; i <= en; i++) {
//        cout << ara[i] << " ";
//    }
//    cout << endl;
//    for (i = beg-2; i <= en; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
    for (i = 0; i < len; i++) {
        if (s[i] == '!') {
            beg--;
            en--;
        }
        else {
            printf("%d\n", query(1,1,lim,beg + k - 1,en));
        }
    }
    return 0;
}

