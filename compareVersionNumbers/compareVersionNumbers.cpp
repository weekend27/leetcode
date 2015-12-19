// Source : https://leetcode.com/problems/compare-version-numbers/
// Author : weekend27
// Date   : 2015-12-19

/**********************************************************************************

Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37

**********************************************************************************/

// How to do it:
// compare two parts: first compare the part before the dot, if they are equal, then compare the part after the dot


class Solution {
public:
    int compareVersion(string version1, string version2) {
        for (int i1 = 0, i2 = 0; i1 < version1.size() || i2 < version2.size(); i1++, i2++){

            int num1 = 0;
            while (version1[i1] != '.' && i1 < version1.size()){
                num1 = num1 * 10 + (version1[i1++] - '0');
            }

            int num2 = 0;
            while (version2[i2] != '.' && i2 < version2.size()){
                num2 = num2 * 10 + (version2[i2++] - '0');
            }

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }
        return 0;

    }
};
