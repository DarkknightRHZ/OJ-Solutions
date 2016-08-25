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
    LL prop, sum;
} tree[mx * 3];
void update(LL node, LL b, LL e, LL i, LL j, LL x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    LL Left = node * 2;
    LL Right = (node * 2) + 1;
    LL mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}

LL query(LL node, LL b, LL e, LL i, LL j, LL carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);

    LL Left = node << 1;
    LL Right = (node << 1) + 1;
    LL mid = (b + e) >> 1;

    LL p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    LL p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

int main()
{
    #ifdef LU_SERIOUS
        freopen("get.txt","r",stdin);
        freopen("got.txt","w+",stdout);
    #endif // LU_SERIOUS
    LL t,cs=0,n,q,d,x,y,v,i,j;
    scanf("%lld",&t);
    while (t--)
    {
        scanf("%lld %lld",&n,&q);
        for (i=0;i<3*mx - 1;i++)
        {
            tree[i].prop = 0;
            tree[i].sum = 0;
        }
//        cout<<"P"<<endl;
        printf("Case %lld:\n",++cs);
        for (i=0;i<q;i++)
        {
            scanf("%lld",&d);
            if (d == 0)
            {
                scanf("%lld %lld %lld",&x,&y,&v);
                update(1,1,n,x+1,y+1,v);
            }
            else
            {
                scanf("%lld %lld",&x,&y);
                printf("%lld\n",query(1,1,n,x+1,y+1,0));
            }
//            cout<<"P"<<endl;
        }
    }
    return 0;
}


