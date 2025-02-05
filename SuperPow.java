class Solution {
    private static final int MOD = 1337;

    public int superPow(int a, int[] b) {
        a %= MOD;
        if (a == 0) return 0;
        
        int result = 1;
        for (int i = 0; i < b.length; i++) {
            result = modPow(result, 10) * modPow(a, b[i]) % MOD;
        }
        
        return result;
    }
    private int modPow(int base, int exp) {
        int result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = result * base % MOD;
            }
            base = base * base % MOD;
            exp /= 2;
        }
        return result;
    }
}
