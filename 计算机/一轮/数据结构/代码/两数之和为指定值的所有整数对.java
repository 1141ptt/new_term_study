package 两数之和为指定值的所有整数对;

import java.util.*;

public class Main {
    public static void expectSum_bySort(int[] arr, int expectSum) {
        if(arr == null || arr.length == 0)
            return;
        Arrays.sort(arr);
        int left = 0, right = arr.length - 1;

        while(left < right) {
            if(arr[left] + arr[right] > expectSum)
                right--;
            else if(arr[left] + arr[right] < expectSum)
                left++;
            else {
                System.out.println(arr[left] + " + " + arr[right] + " = " + expectSum);
                left++;
                right--;
            }
        }
    }
    public static void expectSum_bySet(int[] arr, int expectSum) {
        if(arr == null || arr.length == 0)
            return;
        HashSet<Integer> intSets = new HashSet<Integer>(arr.length);
        int suplement;
        for (int i : arr) {
            suplement = expectSum - i;
            if(!intSets.contains(suplement)){
                intSets.add(i);
            } else {
                System.out.println(i + " + " + suplement + " = " + expectSum);
            }
        }
    }
}
