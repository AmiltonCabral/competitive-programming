package findpivotindex;

class Solution {
    public static int pivotIndex(int[] nums) {
        int sumL = 0;
        int sumR = 0;
        for(int i = 1; i<nums.length; i++) {
            sumR += nums[i];
        }

        for(int i=0; i<nums.length-1; i++) {
            if(sumL == sumR) return i;
            sumL += nums[i];
            sumR -= nums[i+1];
        }

        if(sumL == 0) {
            return nums.length - 1;
        } else {
            return -1;
        }
    }


    public static void main(String[] args) {
        int[] nums;
        int result;

        nums = new int[] {1,7,3,6,5,6};
        result = 3;
        assert(pivotIndex(nums) == result);

        nums = new int[] {1,2,3};
        result = -1;
        assert(pivotIndex(nums) == result);

        nums = new int[] {2,1,-1};
        result = 0;
        assert(pivotIndex(nums) == result);

        nums = new int[] {1,-1,9};
        result = 2;
        assert(pivotIndex(nums) == result);
    }
}