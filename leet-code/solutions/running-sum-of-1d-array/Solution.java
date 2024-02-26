package runningsumof1darray;

import java.util.Arrays;

class Solution {
    public static int[] runningSum(int[] nums) {
        int[] sumArr = new int[nums.length];
        int sum = 0;

        for(int i=0; i<nums.length; i++) {
            sum += nums[i];
            sumArr[i] = sum;
        }

        return sumArr;
    }


    public static void main(String[] args) {
        int[] nums;
        int[] result;

        nums = new int[] {1,2,3,4};
        result = new int[] {1,3,6,10};
        assert(Arrays.equals(result, runningSum(nums)));

        nums = new int[] {1,1,1,1,1};
        result = new int[] {1,2,3,4,5};
        assert(Arrays.equals(result, runningSum(nums)));

        nums = new int[] {3,1,2,10,1};
        result = new int[] {3,4,6,16,17};
        assert(Arrays.equals(result, runningSum(nums)));
    }
}