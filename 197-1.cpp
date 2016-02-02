class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        return 1 + permutationIndex_sub(A);
        // Write your code here
    }
    
    long long permutationIndex_sub(vector<int>& A) {
        if(A.size() <= 1) return 0;
        int n = A.size();
        int countSmaller = 0;
        for(int i = 1; i < n; i++){
            if(A[i] < A[0]){
                countSmaller++;
            }
        }
        A.erase(A.begin());
        return countSmaller * factorial(n - 1) + permutationIndex_sub(A);
        // Write your code here
    }
    long long factorial(int a){
        long long res = 1;
        for(int i = 1; i <= a; i++){
            res = res * i;
        }
        return res;
    }
};
