#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define N 50000
#define MINV -15009

int A[N];
int mx[2*N+2];

int initial(int node,int b,int e){
    if(b>e){
        return MINV;
    }else if(b==e){
        mx[node] = A[b];
        return A[b];
    }else{
        int a1 = initial(2*node+1,b,b+(e-b)/2);
        int a2 = initial(2*node+2,b+(e-b)/2+1,e);
        mx[node] = a1>a2?a1:a2;
        return mx[node];
    }
}

int update(int node,int b,int e, int index, int value){
    if(index<b || index>e) {
        return MINV;
    }else{
        if(b==e){
            A[b] = value;
            return value;
        }
        int a1 = update(2*node+1,b,b+(e-b)/2,index,value);
        int a2 = update(2*node+2,b+(e-b)/2+1,e,index,value);
        mx[node] = a1>a2?a1:a2;
        return mx[node];
    }
}

int find(int node,int b,int e,int x,int y){
     
    if(y<b || x>e ) return MINV;

    if(x<=b && e<=y) return mx[node];
    
    int a1= find(2*node+1, b, b+(e-b)/2, x, y);
    int a2= find(2*node+2, b+(e-b)/2 + 1, e, x, y);
    if(a1>a2) return a1;
    else return a2;
}

int main(){
    int n,m,xi,yi;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>A[i];
    for(int i=0;i<n;++i)
        cout<<A[i]<<"\t";
    cout<<endl;
    initial(0,0,n-1);
    for(int i=0;i<2*n-1;++i)
        cout<<mx[i]<<"\t";
    cout<<endl;

    cin>>m;
    for(int i=0;i<m;++i){
        cin>>xi>>yi;
        cout<<find(0,0,n-1,xi-1,yi-1)<<endl;
    }

    return 0;
}
