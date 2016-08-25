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

    const int mx = 100002;

    struct info {
        int prop,zero,one,two;
    } tree[mx * 4];

    void update(int node, int b, int e, int i, int j)
    {
        if (i > e || j < b)
            return;
        if (b >= i && e <= j)
        {
            tree[node].prop++;
            int tmp = tree[node].zero;
            tree[node].zero = tree[node].two;
            tree[node].two = tree[node].one;
            tree[node].one = tmp;
            return;
        }
        int Left = node * 2;
        int Right = (node * 2) + 1;
        int mid = (b + e) / 2;
        update(Left, b, mid, i, j);
        update(Right, mid + 1, e, i, j);
        int prp = tree[node].prop,tmp;
        tree[node].zero = tree[Left].zero + tree[Right].zero;
        tree[node].one = tree[Left].one + tree[Right].one;
        tree[node].two = tree[Left].two + tree[Right].two;
        prp %= 3;
        while (prp)
        {
            tmp = tree[node].zero;
            tree[node].zero = tree[node].two;
            tree[node].two = tree[node].one;
            tree[node].one = tmp;
            prp--;
        }
    }

    int query(int node, int b, int e, int i, int j, int carry = 0)
    {
        if (i > e || j < b)
            return 0;

        if (b >= i and e <= j)
            {
                carry %= 3;
                int tmp,z,o,t;
                z = tree[node].zero;
                o = tree[node].one;
                t = tree[node].two;
                while (carry)
                {
                    tmp = z;
                    z = t;
                    t = o;
                    o = tmp;
                    carry--;
                }
    //            cout<<"e "<<node<<" "<<tree[node].zero<<endl;
                return z;
            }

        int Left = node << 1;
        int Right = (node << 1) + 1;
        int mid = (b + e) >> 1;
        int p1 = 0,p2 = 0;
        if (mid >= i) p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
        if (mid <= j) p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

        return p1 + p2;
    }

    void init(int node, int b, int e)
    {
    //    test;
        if (b == e)
        {
            tree[node].prop = 0;
            tree[node].zero = 1;
            tree[node].one = 0;
            tree[node].two = 0;
    //        if (b == 10) cout<<"b "<<node<<" "<<tree[node].zero<<endl;
    //        cout<<b<<endl;
    //        test;
            return;
        }
        int Left = node * 2;
        int Right = (node * 2) + 1;
        int mid = (b + e) / 2;
    //    cout<<mid<<endl;
        init(Left,b,mid);
        init(Right,mid+1,e);
        tree[node].zero = e - b + 1;
        tree[node].one = 0;
        tree[node].two = 0;
        tree[node].prop = 0;
        return;
    }

    int main()
    {
        #ifdef LU_SERIOUS
            freopen("get.txt","r",stdin);
            freopen("got.txt","w+",stdout);
        #endif // LU_SERIOUS
        int t,cs=0,n,q,i,j,ans,x,y,d;
        scanf("%d",&t);
        while (t--)
        {
            ans = 0;
    //        for (i=0;i<100002 * 4;i++)
    //        {
    //            tree[i].prop = 0;
    //        }
    //        test;
            scanf("%d %d",&n,&q);
            init(1,1,n);
            printf("Case %d:\n",++cs);
            for (i=0;i<q;i++)
            {
                scanf("%d",&d);
                if (d == 0)
                {
                    scanf("%d %d",&x,&y);
                    update(1,1,n,x+1,y+1);
                }
                else
                {
                    scanf("%d %d",&x,&y);
                    ans = query(1,1,n,x+1,y+1);
                    printf("%d\n",ans);
                }
            }
        }
        return 0;
    }

