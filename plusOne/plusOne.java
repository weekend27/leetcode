public class Solution {
    public int[] plusOne(int[] digits) {
        int c = 1;
        for(int i = digits.length - 1; i >= 0; i--) {
            digits[i] = digits[i] + c;
            c = digits[i] / 10;
            digits[i] = digits[i] % 10;
        }
        if (c != 0) {
            int[] result = new int[digits.length + 1];
            result[0] = c;
            for (int i = 1; i < result.length; i++) {
                result[i] = digits[i - 1];
            }
            return result;
        }
        return digits;
    }
}
