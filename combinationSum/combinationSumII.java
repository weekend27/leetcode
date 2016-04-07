// Source : https://leetcode.com/problems/combination-sum-ii/
// Author : weekend27
// Date   : 2016-04-07

/**********************************************************************************

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

**********************************************************************************/

// How to do it:
// ref: https://leetcode.com/discuss/94790/share-my-java-solution-almost-identical-to-combination-sum

public class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(candidates);
        combinationSum(result, 0, candidates, new ArrayList<>(), target);
        return result;
    }

    private void combinationSum(List<List<Integer>> result, int start, int[] candidates, List<Integer> tmp, int targetRemaining) {
        if (targetRemaining == 0) {
            result.add(tmp);
            return;
        }

        for (int i = start; i < candidates.length;) {
            if (candidates[i] <= targetRemaining) {
                List<Integer> next = new ArrayList<>(tmp);
                next.add(candidates[i]);
                combinationSum(result, i+1, candidates, next, targetRemaining - candidates[i]);
            }
            i++;
            while (i < candidates.length && candidates[i] == candidates[i - 1]) {
                i++;
            }
        }
    }
}
