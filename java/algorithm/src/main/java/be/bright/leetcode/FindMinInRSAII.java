package be.bright.leetcode;

import java.util.Arrays;
import java.util.Comparator;

/**
 * Created by barroco on 10/25/14.
 * https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 */
public class FindMinInRSAII {
    public static void main(String[] args) {
        int[] numbers = {3, 1};
        System.out.println(findMin(numbers));
    }
    public static int findMin(int[] num) {
        int len=num.length;
        int start=0;
        int end=num.length-1;
        if(num[start]<num[end])
            return num[start];
        int mid=start+(end-start)/2;
        while(start!=end){
            if(num[mid]<num[0]){
                end=mid;
            }else if (num[mid]>num[0]){
                start=mid+1;
            }else{
                if(num[mid]>num[end]){
                    start=mid+1;
                }else{
                    --end;
                }
            }
            mid=start+(end-start)/2;
        }
        return num[mid];
    }

}
