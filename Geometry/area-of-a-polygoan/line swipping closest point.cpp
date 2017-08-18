#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 10050
#define sl(a) scanf("%lld",&a)
#define si(a) scanf("%d",&a)
#define sd(a) scanf("%lf",&a)
#define py first
#define px second
#define ll long long int
#define EPS 1e-7


#define pii pair<double,double>

pii points[Max];

set<pii> s;
set<pii> :: iterator it;

bool cmp(pii a, pii b)
{
    return a.px < b.px;
}

int main()
{

   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    ll n;
    int test;
    double a,b;

    si(test);

    for(int Case = 1 ;Case<=test;Case++)
    {
        sl(n);
        s.clear();

        for(int i=0;i<n;i++)
        {
            sd(a); sd(b);

            points[i] = make_pair(b,a);
        }

        sort(points,points+n,cmp);

        double res = 1000000000000000000.0;

        s.insert(points[0]);

        int left=0;

        for(int i=1;i<n;i++)
        {
            while(left<i && points[i].px - res > points[left].px)
            {
                s.erase(points[left]);
                left++;
            }

            for(it = s.lower_bound(make_pair(points[i].py-res,points[i].px-res)); it!=s.end() && points[i].py + res >= it->py; it++)
            {
                double p = (points[i].px - it->px)*(points[i].px - it->px)+(points[i].py - it->py)*(points[i].py - it->py);
                res = min(res,sqrt(p));
            }

            s.insert(points[i]);
        }

        printf("%.4f\n",res);

    }

    return 0;
}

