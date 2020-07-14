
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


const int mx = 1e5 + 5;
int arr[mx];
int ara[mx];
int tree[mx * 4];
PII boundary[mx];

void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = b;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    if (arr[tree[Left]] < arr[tree[Right]]) {
        tree[node] = tree[Right];
    }
    else tree[node] = tree[Left];
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    if (arr[p2] > arr[p1]) return p2;
    else return p1;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int n,m,i,j,k,cns,cnt,x,y,a,b,l,r;
    scanf("%d %d",&n,&m);
    memset(arr,0,sizeof arr);
    memset(tree,0,sizeof tree);
    for (i = 1; i <= n; i++) {
        scanf("%d", &ara[i]);
    }
    for (i = 1; i <= n; i++) {
        x = ara[i];
        cnt = 0;
        j = i;
        while (ara[j] == x && j <= n) {
            cnt++;
            j++;
        }
        a = i, b = j - 1;
        for (k = i; k < j; k++) {
            arr[k] = cnt;
            boundary[k] = {a,b};
        }
        i = j - 1;
    }
    init(1,1,n);
    for (i = 1; i <= m; i++) {
        scanf("%d %d %d",&x,&y,&k);
        if (k > (y - x + 1)){
            printf("-1\n");
            continue;
        }
        a = boundary[x].first;
        b = boundary[x].second;
        if (b > y) b = y;
        if (a < x) a = x;
        if (b - a + 1 >= k) {
            printf("%d\n", ara[x]);
            continue;
        }
        l = x;
        x = boundary[x].second + 1;
        a = boundary[y].first;
        b = boundary[y].second;
        if (b > y) b = y;
        if (a < x) a = x;
        if (b - a + 1 >= k) {
            printf("%d\n", ara[y]);
            continue;
        }
        y = boundary[y].first - 1;
        if (x > y) {
            printf("-1\n");
            continue;
        }
        cns = query(1,1,n,x,y);
        if (arr[cns] >= k) printf("%d\n",ara[cns]);
        else printf("%d\n",-1);
    }
    return 0;
}
