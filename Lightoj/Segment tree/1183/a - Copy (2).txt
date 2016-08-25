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
#define PII         pair <LL,LL>
#define MII         map <LL,LL>
#define MSI         map <string,LL>
#define MIS         map <LL,string>
#define MLI         map <long long LL,LL>
#define MIL         map <LL,long long LL>
typedef long long int           LL;
typedef vector <string>         VS;
typedef vector <LL>            VI;
typedef vector <char>           VC;
typedef vector <LL>             VLL;

/* Functions */

LL GCD (LL x, LL y){if (x%y==0) return y; else return (GCD(y,x%y));}

const LL mx = 100002;

struct info {
    LL prop,sum;
} tree[mx * 4];

void update(LL node, LL b, LL e, LL i, LL j, LL val)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].prop = val;
        tree[node].sum = (e - b + 1) * val;
        return;
    }
    LL Left = node * 2;
    LL Right = (node * 2) + 1;
    LL mid = (b + e) / 2;
    if (tree[node].prop != -1)
    {
        tree[Left].prop = tree[Right].prop = tree[node].prop;
        tree[Left].sum = tree[node].prop * (mid - b + 1);
        tree[Right].sum = tree[node].prop * (e - mid);
        tree[node].prop = -1;
    }
    update(Left, b, mid, i, j, val);
    update(Right, mid + 1, e, i, j, val);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
    return;
}

LL query(LL node, LL b, LL e, LL i, LL j)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        {
            return tree[node].sum;
        }
    LL Left = node << 1;
    LL Right = (node << 1) + 1;
    LL mid = (b + e) >> 1;
    LL p1 = 0,p2 = 0;
    if (tree[node].prop != -1)
    {
        tree[Left].prop = tree[Right].prop = tree[node].prop;
        tree[Left].sum = tree[node].prop * (mid - b + 1);
        tree[Right].sum = tree[node].prop * (e - mid);
        tree[node].prop = -1;
    }
    if (mid >= i) p1 = query(Left, b, mid, i, j);
    if (mid <= j) p2 = query(Right, mid + 1, e, i, j);

    return p1 + p2;
}

void init(LL node, LL b, LL e)
{
//    test;
    if (b == e)
    {
        tree[node].prop = -1;
        tree[node].sum = 0;
        return;
    }
    LL Left = node * 2;
    LL Right = (node * 2) + 1;
    LL mid = (b + e) / 2;
//    cout<<mid<<endl;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node].prop = -1;
    tree[node].sum = 0;
    return;
}

int main()
{
    #ifdef LU_SERIOUS
        freopen("get.txt","r",stdin);
    #endif // LU_SERIOUS
    LL t,cs=0,n,q,i,j,sum,nom,denom,gcd,x,y,d,v;
    scanf("%lld",&t);
    while (t--)
    {
        scanf("%lld %lld",&n,&q);
        init(1,1,n);
        printf("Case %lld:\n",++cs);
        for (i=0;i<q;i++)
        {
            scanf("%lld",&d);
            if (d == 1)
            {
                scanf("%lld %lld %lld",&x,&y,&v);
                update(1,1,n,x+1,y+1,v);
            }
            else
            {
                scanf("%lld %lld",&x,&y);
                sum = query(1,1,n,x+1,y+1);
                nom = sum, denom = y - x + 1;
                gcd = GCD(nom,denom);
                nom /= gcd, denom /= gcd;
                if (denom == 1)
                {
                    printf("%lld\n",nom);
                }
                else if (nom == 0)
                {
                    printf("%lld\n",0);
                }
                else
                {
                    printf("%lld/%lld\n",nom,denom);
                }
            }
        }
    }
    return 0;
}


