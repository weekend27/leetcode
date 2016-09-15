public class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] result = {-1, -1};
        if (nums == null || nums.length == 0) {
            return result;
        }

        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                int rl = mid;
                for (int i = mid; i > -1; i--) {
                    if (nums[i] == nums[mid]) {
                        rl = i;
                    } else {
                        break;
                    }
                }
                int rr = mid;
                for (int i = mid; i < nums.length; i++) {
                    if (nums[i] == nums[mid]) {
                        rr = i;
                    } else {
                        break;
                    }
                }
                result[0] = rl;
                result[1] = rr;
                return result;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
}
