#include<iostream>
#include<cstdio>
#include<stdlib.h>

using namespace std;

struct point
{
    double x,y;
};

double cross_product(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}

double Area(point [] vertices, int n)
{
    double sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=cross_product(vertices[i],vertices[(i+1)%n]);
    }
    return fabs(sum)/2.0;
}

int main()
{


    return 0;
}
