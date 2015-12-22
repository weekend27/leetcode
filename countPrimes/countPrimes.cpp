// Source : https://leetcode.com/problems/count-primes/
// Author : weekend27
// Date   : 2015-12-22

/**********************************************************************************

Description:

Count the number of prime numbers less than a non-negative number, n.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Hint:

Let's start with a isPrime function. To determine if a number is prime, we need to check if it is not divisible by any number less than n.
The runtime complexity of isPrime function would be O(n) and hence counting the total prime numbers up to n would be O(n2).
Could we do better?

**********************************************************************************/

// How to do it:
// ref: 2015/06/leetcode-question-count-primes.html
/*
This is a classic algorithm question.  Here I'd like to introduce one of the famous algorithm called "Sieve of Eratosthenes." The general idea is to use a "sieve", to filter the numbers form 2 to n, each time, we get the next prime number in the array, and remove the multiples of this prime number. Iterating this process until the square of next prime number is greater than the last number n.  The numbers now left in the array are all primes.

In this problem, just be careful that the last number is not included.

According to the literature, the time complexity of this algorithm is nloglogn.
*/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> nums(n, true);
        int i = 2;
        while (i * i < n){
            for (int j = 2; j*i < n; j++){
                nums[j*i] = false;
            }

            i++;

            while (nums[i] == false && i*i < n){
                i++;
            }
        }

        int result = 0;
        for (int i = 2; i < n; i++){
            if (nums[i] == true){
                result++;
            }
        }

        return result;
    }
};
