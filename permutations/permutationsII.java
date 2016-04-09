// Source : https://leetcode.com/problems/permutations-ii/
// Author : weekend27
// Date   : 2016-04-09

/**********************************************************************************

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

**********************************************************************************/

// How to do it:
// ref: http://www.programcreek.com/2013/02/leetcode-permutations-ii-java/
// For each number in the array, swap it with every element after it. To avoid duplicate, we need to check the existing sequence first.


public class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        permuteUnique(nums, 0, result);
        return result;
    }

    private void permuteUnique(int[] nums, int start, List<List<Integer>> result) {
        if (start >= nums.length) {
            ArrayList<Integer> item = convertArray2List(nums);
            result.add(item);
        }

        for (int j = start; j <= nums.length - 1; ++j) {
            if (containsNoDuplicates(nums, start, j)) {
                swap(nums, start, j);
                permuteUnique(nums, start+1, result);
                swap(nums, start, j);
            }
        }
    }

    private ArrayList<Integer> convertArray2List(int[] nums) {
        ArrayList<Integer> item = new ArrayList<Integer>();
        for (int i = 0; i < nums.length; ++i) {
            item.add(nums[i]);
        }
        return item;
    }

    private boolean containsNoDuplicates(int[] nums, int start, int end) {
        for (int i = start; i < end; ++i) {
            if (nums[i] == nums[end]) {
                return false;
            }
        }
        return true;
    }

    private static void swap(int[] nums, int i, int j) {
        /*
        nums[i] = nums[i] ^ nums[j];
        nums[j] = nums[i] ^ nums[j];
        nums[i] = nums[i] ^ nums[j];
        */
        
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
