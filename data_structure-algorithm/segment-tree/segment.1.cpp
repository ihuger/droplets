#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;

//http://www.topcoder.com/tc?d1=tutorials&d2=lowestCommonAncestor&module=Static
//http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/

int a[100];

int main(){
    memset(a, 0 , sizeof(a));
    int n,s,e;
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>> s >> e;
        join(s , e);
    }

    cout<<a[0]<<"\t";
    for ( int i=1; i< 100; ++i){
        a[i] += a[i-1];
        cout<<a[i]<<"\t";
    }
    cout<<endl;

    return 0;
}
