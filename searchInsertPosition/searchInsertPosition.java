public class Solution {
    public int searchInsert(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        if (target < nums[0]) {
            return 0;
        }
        else if (target > nums[nums.length - 1]) {
            return nums.length;
        }
        else {
            int left = 0;
            int right = nums.length - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (nums[mid] == target) {
                    return mid;
                } else if (target > nums[left] && target < nums[right] && (left == right - 1)) {
                    return right;
                } else if (nums[left] == target) {
                    return left;
                } else if (nums[right] == target) {
                    return right;
                } else if (nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }
}
