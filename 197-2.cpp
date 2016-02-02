class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        int n = A.size();
        if(n < 2) return 1;
        int position = 2;
        long long res = 1;
        long long factor = 1;
        for(int i = n - 2; i >= 0; i--){
            int countSmaller = 0;
            for(int j = i + 1; j < n; j++){
                if(A[i] > A[j]) countSmaller++;
            }
            res = res + countSmaller * factor;
            factor = factor * position;
            position++;
        }
        return res;
    }
};
