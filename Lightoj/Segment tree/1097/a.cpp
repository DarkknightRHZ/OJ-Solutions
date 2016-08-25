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

const int MX = 1429432;

int tree[3 * MX];
//int ara[MX];
int itemCnt,lft,rght,mid;

void genMid(int node, int b, int e)
{
    lft = node * 2;
    rght = lft + 1;
    mid = (b + e) / 2;
}

void build(int node, int b, int e)
{
    if (b == e)
    {
        //ara[b] = 1;
        tree[node] = 1;
        itemCnt++;
        return;
    }
    genMid(node,b,e);
    int l,r,m;
    l = lft, r = rght, m = mid;
    build(l,b,m);
    build(r,m+1,e);
    tree[node] = tree[l] + tree[r];
    return;
}

int query(int node, int b, int e, int pos, int del)
{
    if (b == e)
    {
        if (del)
        {
            tree[node] = 0;
            itemCnt--;
        }
//        if (pos = 1 ) cout<<"b "<<b<<endl;
        return b;
    }
    int l,r,m,x;
    genMid(node,b,e);
    l = lft, r = rght, m = mid;
    if (pos <= tree[l])
    {
        x = query(l,b,m,pos,del);
    }
    else
    {
        x = query(r,m+1,e,pos-tree[l],del);
    }
    tree[node] = tree[l] + tree[r];
    return x;
}

void pre()
{
//    test;
    int i,j,x,y;
    itemCnt = 0;
    build(1,1,MX-1);
//    test;
//    cout<<itemCnt<<endl;
    for (i=1;i<=itemCnt;i++)
    {
        if (i == 1) x = 2;
        else x = query(1,1,MX-1,i,0);
//        test;
//        if (i == 2) cout<<"x "<<x<<" "<<i<<endl;
        for (j = x; j <= itemCnt; j += (x-1))
        {
            query(1,1,MX-1,j,1);
        }
//        if (i == 2) cout<<i<<" "<<itemCnt<<endl;
    }
//    cout<<itemCnt<<endl;
//    test;
    return;
}

int main()
{
    #ifdef LU_SERIOUS
        freopen("get.txt","r",stdin);
    #endif // LU_SERIOUS
    int t,cs=0,x;
    pre();
//    test;
//    cout<<tree[1]<<endl;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&x);
        printf("Case %d: %d\n",++cs,query(1,1,MX-1,x,0));
    }
    return 0;
}


