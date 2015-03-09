package be.bright.leetcode;

import java.util.Arrays;
import java.util.Comparator;

/**
 * Craeted by barroco on 10/25/14.
 */
public class MedianTwoSortedArrays {
    public static void main(String[] args) {
        int[] A= new int[]{0};
        int[] B= new int[]{1};
        System.out.println(new MedianTwoSortedArrays().findMedianSortedArrays(A,B));
    }

    public double findMedianSortedArrays(int A[], int B[]) {
        int as,ae,bs,be;

        as=bs=0;
        ae=A.length-1;
        be=B.length-1;
        boolean bEven= (A.length+B.length)%2==0;
        while(as<=ae && bs<=be ){
            if(as==ae &&bs==be)break;
            if(A[as]<B[bs]){
                ++as;
            }else ++bs;

            if(A[ae]<B[be]){
                --be;
            }else --ae;
        }

        if(!bEven){
            int m= as>ae?(bs+(be-bs)/2):(as+(ae-as)/2);
            return as>ae?B[m]:A[m];
        }
        else{
            if(as==ae){
                return (A[as] + B[bs])/2.0;
            }else if(as>ae){
                int m=bs+(be-bs)/2;
                return (B[m]+B[m+1])/2.0;
            }else{
                int m=as+(ae-as)/2;
                return (A[m]+A[m+1])/2.0;
            }

        }
    }

}
