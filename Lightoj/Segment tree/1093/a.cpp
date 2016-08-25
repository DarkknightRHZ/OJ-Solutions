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

#define test        cout<<"thiq ase boss"<<endl;
#define PB          push_back
#define PF          push_front
#define PII         pair <int,int>
#define MII         map <int,int>
#define MSI         map <string,int>
#define MIS         map <int,string>
#define MLI         map <long long int,int>
#define MIL         map <int,long long int>
typedef long long int           LL;
typedef vector <string>         VS;
typedef vector <int>            VI;
typedef vector <char>           VC;
typedef vector <LL>             VLL;

/* Functions */

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

#define mx 100002

const int INF = 100000005;

int arr[mx];
int tree[mx * 3];
int tree2[mx * 3];
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
    tree[node] = max(tree[Left] , tree[Right]);
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
    return max(p1 , p2);
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
    tree[node] = max(tree[Left] , tree[Right]);
}

void init2(int node, int b, int e)
{
    if (b == e) {
        tree2[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init2(Left, b, mid);
    init2(Right, mid + 1, e);
    tree2[node] = min(tree2[Left] , tree2[Right]);
}
int query2(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return INF;
    if (b >= i && e <= j)
        return tree2[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query2(Left, b, mid, i, j);
    int p2 = query2(Right, mid + 1, e, i, j);
    return min(p1 , p2);
}
void update2(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree2[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update2(Left, b, mid, i, newvalue);
    update2(Right, mid + 1, e, i, newvalue);
    tree2[node] = min(tree2[Left] , tree2[Right]);
}

int main()
{
    #ifdef LU_SERIOUS
        freopen("get.txt","r",stdin);
    #endif // LU_SERIOUS
    int t,cs=0,n,d,i,j,mxv,mnv,mxd;
    scanf("%d",&t);
//    cout<<INF<<endl;
    while (t--)
    {
        scanf("%d%d",&n,&d);
        for (i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
//            cout<<arr[i]<<" ";
        }
//        cout<<endl;
//        memset(tree,0,sizeof tree);
//        memset(tree2,0,sizeof tree2);
        init(1,1,n);
        init2(1,1,n);
        mxd = 0;
        for (i=1,j=d;j<=n;i++,j++)
        {
            mxv = query(1,1,n,i,j);
            mnv = query2(1,1,n,i,j);
//            cout<<mxd<<" "<<mxv<<" "<<mnv<<" "<<d<<endl;
            mxd = max(mxd, mxv - mnv);
        }
        printf("Case %d: %d\n",++cs,mxd);
    }
    return 0;
}


