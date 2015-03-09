package be.bright.leetcode;

import javafx.util.Pair;

import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by barroco on 10/25/14.
 */
public class TwoSum {
    public static void main(String[] args) {
        int[] numbers = {3, 4, 5, 1, 0, 9, 10};
        System.out.println(Arrays.toString(twoSum(numbers, 4)));
    }

    public int[] twoSumN2(int[] numbers, int target) {
        //n2
        //for i=0:length-2
        //    for j=i+1:end
        int[] results = new int[2];
        for (int i = 0; i < numbers.length - 1; ++i) {
            for (int j = 0; j < numbers.length; ++j) {
                if (numbers[i] + numbers[j] == target) {
                    results[0] = i + 1;
                    results[1] = j + 1;
                }
            }
        }
        return results;
    }

    public static int[] twoSum(int[] numbers, int target) {
        //nlogn
        //sort
        //find
        int[][]a=new int[numbers.length][2];
        for(int i=0;i<numbers.length;++i){
            a[i][0]=numbers[i];
            a[i][1]=i+1;
        }
        Arrays.sort(a,new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0]-o2[0];
            }
        });
        int i = 0;
        int j = numbers.length - 1;
        int sum;
        while (i < j && j > 0) {
            sum = a[i][0] + a[j][0];
            if (sum == target) {
                break;
            } else if (sum < target) ++i;
            else --j;
        }

        System.out.println(Arrays.toString(numbers));
        System.out.println(Arrays.deepToString(a));
        if(a[i][1]<a[j][1]){
            return new int[]{a[i][1],a[j][1]};
        }else{
            return new int[]{a[j][1],a[i][1]};
        }
    }

}
