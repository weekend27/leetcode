# Source : https://leetcode.com/problems/two-sum/
# Author : weekend27
# Date   : 2015-11-19

'''
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
'''

# How to do it:
# (1)sort; (2)two pointers: one from the beginning and the other one from the end.

class Solution(object):
    def twoSum(self, num, target):
        """
        :type num: List[int]
        :type target: int
        :rtype: List[int]
        """
        tmpNum = list(num)
        tmpNum.sort()
        i = 0
        j = len(tmpNum) - 1
        while i < j:
            sum = tmpNum[i] + tmpNum[j]
            if sum == target:
                num1 = tmpNum[i]
                num2 = tmpNum[j]
                break
            if sum > target:
                j = j - 1
            else:
                i = i + 1

        i = 0
        result = []
        while i < len(num):
            if num1 == num[i] or num2 == num[i]:
                result.append(i + 1)
            i = i + 1
        return result
