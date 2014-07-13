#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;

int a[100];

//http://dongxicheng.org/structure/segment-tree/
//线段[start,end]
//        -------------
//                  ----------
//      ----     -------
//   _______________________________
//      0  1  2  3  4  5  6  7  8
//     +1 +1 -1 +1 +1 -1 +1    -1
//                 +1    -1
void join(int start,int end){
    a[start] += 1;
    a[end + 1] += -1;
}

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
