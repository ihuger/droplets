#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define N 50001
//http://www.spoj.com/problems/GSS1/
int A[N];

int query(int b, int e){
    int sum=-1;
    int bsum = 0;
    int maxx = A[b];
    int countv = 0;
    for(int i=b; i<=e; ++i){
        if(sum<0)
            sum = A[i];
        else
            sum += A[i];
        if(sum > maxx)
            maxx=sum;
    }
    return sum>maxx?sum:maxx;
}

int main(){
    int n,m,xi,yi;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&A[i]);

    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d %d",&xi,&yi);
        printf("%d\n",query(xi-1,yi-1));
    }

    return 0;
}
