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

const int NMX = 100010;
const int QMX = 50010;
const int MX = NMX + QMX;

int itemCnt, treeMx, n, q, mxIndex, lft, rght, mid;

int tree[4 * MX];
unsigned int ara[MX];

void genMid(int node,int b, int e)
{
    lft = node * 2;
    rght = lft + 1;
    mid = (b + e)/2;
    return;
}

int query(int node, int b, int e, int pos)
{
    if (b == e)
    {
        tree[node] = 0;
        treeMx--;
        return b;
    }
    int l,r,m;
    genMid(node,b,e);
    l = lft;
    r = rght;
    m = mid;
    int ans;
//    if (pos == 4)
//    {
//        cout<<"here "<<tree[lft]<<" "<<tree[rght]<<endl;
//    }
    if (pos <= tree[l])
    {
        ans = query(l,b,m,pos);
        //tree[lft] = l;
    }
    else
    {
        ans = query(r,m+1,e,pos - tree[l]);
    }
    tree[node] = tree[l] + tree[r];
//    if (pos == 4) cout<<tree[node]<<endl;
    return ans;
}

void update (int node, int b, int e, int idx, unsigned int val)
{
    if (b == e)
    {
        tree[node] = 1;
        treeMx++;
        ara[idx] = val;
//        cout<<"b "<<b<<" "<<node<<endl;
        return;
    }
    int l,r,m;
    genMid(node,b,e);
    l = lft;
    r = rght;
    m = mid;
    if (idx <= m)
    {
        update(l,b,m,idx,val);
    }
    else
    {
        update(r,m+1,e,idx,val);
    }
    tree[node] = tree[l] + tree[r];
//    cout<<"PK "<<tree[node]<<endl;
//    cout<<"bal "<<tree[lft]<<" "<<tree[rght]<<" "<<tree[node]<<endl;
    return;
}

void add(unsigned int x)
{
    //treeMx++;
    update(1,1,mxIndex,++itemCnt,x);
//     cout<<"ele "<<tree[1]<<endl;
    return;
}

void init()
{
    memset(ara,0,sizeof ara);
    memset(tree,0,sizeof tree);
    itemCnt = 0;
    treeMx = 0;
    mxIndex = n+q+5;
    return;
}

void solve()
{
    int i,j,k,y,p,idx;
    unsigned int x;
    char ch;
    scanf("%d %d",&n,&q);
    init();
//    test;
    for (i=1;i<=n;i++)
    {
        scanf("%u",&x);
        add(x);
//        test;
    }
    //cout<<n<<" "<<itemCnt<<endl;
    for (i=1;i<=q;i++)
    {
        scanf(" %c",&ch);
        if (ch == 'a')
        {
//            test;
            scanf("%u",&x);
            add(x);
//            cout<<"P "<<ara[itemCnt]<<endl;
        }
        else
        {
            scanf("%d",&p);
            if (p > treeMx)
            {
                printf("none\n");
            }
            else
            {
                idx = query (1,1,mxIndex,p);
//                cout<<idx<<" "<<ara[idx]<<" "<<p<<endl;
                printf("%u\n",ara[idx]);
            }
        }
    }
    return;
}

int main()
{
    #ifdef LU_SERIOUS
        freopen("get.txt","r",stdin);
        //freopen("got.txt","w+",stdout);
    #endif // LU_SERIOUS
    int t,cs=0;
    scanf("%d",&t);
    while (t--)
    {
        printf("Case %d:\n",++cs);
        solve();
    }
    return 0;
}


