// Source : https://leetcode.com/problems/combination-sum/
// Author : weekend27
// Date   : 2016-04-06

/**********************************************************************************

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]

**********************************************************************************/

// How to do it:
// ref: http://www.programcreek.com/2014/02/leetcode-combination-sum-java/
// DFS

public class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();

        if (candidates == null || candidates.length == 0) return result;

        List<Integer> curr = new ArrayList<Integer>();
        Arrays.sort(candidates);

        combinationSum(candidates, target, 0, curr, result);

        return result;
    }

    public void combinationSum(int[] candidates, int target, int j, List<Integer> curr, List<List<Integer>> result) {
        if (target == 0) {
            List<Integer> temp = new ArrayList<Integer>(curr);
            result.add(temp);
            return;
        }

        for (int i = j; i < candidates.length; i++) {
            if (target < candidates[i]) {
                return;
            }

            curr.add(candidates[i]);
            combinationSum(candidates, target-candidates[i], i, curr, result);
            curr.remove(curr.size()-1);
        }
    }
}
