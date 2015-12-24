// Source : https://leetcode.com/problems/super-ugly-number/
// Author : weekend27
// Date   : 2015-12-24

/**********************************************************************************

Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.

**********************************************************************************/

// How to do it:
// look at the code


class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> superUglyNumbers;
        superUglyNumbers.push_back(1);
        int numPrimes = primes.size();
        vector<int> index(numPrimes, 0);
        // add super ugly number up to nth
        while (superUglyNumbers.size() < n)
        {
            int nextSuperUglyNumber = superUglyNumbers[index[0]] * primes[0];
            for (int i = 0; i < numPrimes; i++)
            {
                nextSuperUglyNumber = min(nextSuperUglyNumber, superUglyNumbers[index[i]] * primes[i]);
            }
            for (int i = 0; i < numPrimes; i++)
            {
                if (nextSuperUglyNumber == superUglyNumbers[index[i]] * primes[i])
                {
                    index[i]++;
                }
            }
            superUglyNumbers.push_back(nextSuperUglyNumber);
        }

        return superUglyNumbers[n-1];
    }
};
