#include<iostream>
using namespace std;
//A simple code to show how to implement a max-heap

/**
 * suppose for a node i, left[i] and right[i]  are already maxHeaps 
 * where:
 *  i =[0,len-1]
 *  left = 2*i +1
 *  right = 2*i +2
 *  i= (left-1)/2 = (right-1)/2 
 */
void maxHeap(int *arr,int len,int idx){
    int mx=idx;
    int left=2*idx+1;
    int right=left+1;
    if(mx<len && left<len && arr[mx]<arr[left])
        mx=left;
    if(mx<len && right<len && arr[mx]<arr[right])
        mx=right;
    if(mx!=idx){//exchange largest with idx
        int tmp=arr[mx];
        arr[mx]=arr[idx];
        arr[idx]=tmp;
        maxHeap(arr,len,mx);
    }
}
/**
 * given an array, build a max-heap 
 *  note that : 
 *      i =[0,len-1] and 
 *      i = (left-1)/2 = (right-1)/2 
 */
void buildHeap(int *arr,int len){
    int start=(len-2)/2;
    while(start>=0){
        maxHeap(arr,len,start);
        --start;
    }
}
/** 
 * sort an array by using a max-heap
 */
void sortHeap(int *arr,int len){
    buildHeap(arr,len);
    int last=len-1;
    int tmp=0;
    while(last>0){
        tmp=arr[last]; //exchange the last element with the first one
        arr[last]=arr[0];
        arr[0]=tmp;
        maxHeap(arr,last,0); //note that the last index always go down
        --last;
    }
}

int main(){
    int a[10]={4,30,2,10,3,0,-10,500,1,22};
    sortHeap(a,10);
    for(int i=0;i<10;++i)
        cout<<a[i]<<"\t";
    cout<<endl;
    return 0;
}
