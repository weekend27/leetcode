// Source : https://leetcode.com/problems/repeated-dna-sequences/
// Author : weekend27
// Date   : 2015-12-23

/**********************************************************************************

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].

**********************************************************************************/

// How to do it:
// ref: http://yucoding.blogspot.sg/2015/03/leetcode-question-repeated-dna-sequences.html
/*
This problem is straightforward (no need to think about KMP algorithm), only dictionary (hashmap) can pass the OJ.
Since there are many restrictions in this problem, it becomes much easier. E.g., only four chars are occurred in the sequence (A,T,C,and G), only length-10 substr is needed.
So the algorithm goes as follows:
1. Search from the start of the string, get every substr with length 10.
2. Construct and look up a hashmap, add 1 to the value.
3. After the whole search, check every entry in the hashmap, if the value is greater than 1, output.

Note that in the C++ OJ, when using string as the map key, the will cause an memory exceeded error. So, I map the string to long int, which is used as the key. Results are mapped back to string and output.
*/

class Solution {
public:
    long str2long(string s){
        long res = 0;
        for (int i = 0; i < 10; i++){
            if (s[i] == 'A'){res = res * 10 + 1;}
            if (s[i] == 'T'){res = res * 10 + 2;}
            if (s[i] == 'C'){res = res * 10 + 3;}
            if (s[i] == 'G'){res = res * 10 + 4;}
        }
        return res;
    }

    string long2str(long s){
        string res = "";
        for (int i = 0; i < 10; i++){
            int d = s % 10;
            if (d == 1){res = "A" + res;}
            if (d == 2){res = "T" + res;}
            if (d == 3){res = "C" + res;}
            if (d == 4){res = "G" + res;}
            s /= 10;
        }
        return res;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        map<long, int> d;
        vector<string> res;
        for (int i = 0; i < n - 9; i++){
            string sub = s.substr(i, 10);
            long index = str2long(sub);
            if (d.find(index) == d.end()){
                d[index] = 0;
            }
            else{
                d[index]++;
            }
        }
        for (auto it = d.begin(); it != d.end(); it++){
            if (it->second >= 1){
                res.push_back(long2str(it->first));
            }
        }

        return res;
    }
};
