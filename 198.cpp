class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        int n = A.size();
        if(n < 2) return 1;
        int position = 2;
        long long res = 1;
        long long factor = 1;
        for(int i = n - 2; i >= 0; i--){
            unordered_map<int, int> count;
            count[A[i]] = 1;
            int countSmaller = 0;
            for(int j = i + 1; j < n; j++){
                if(count.find(A[j]) != count.end()){
                    count[A[j]]++;
                }
                else{
                    count[A[j]] = 1;
                }
                if(A[i] > A[j]) countSmaller++;
            }
            long long denom = 1;
            for(auto it = count.begin(); it != count.end(); it++){
                denom = denom * factorial(it->second);
            }
            res = res + countSmaller * factor / denom;
            factor = factor * position;
            position++;
        }
        return res;
    }
    long long factorial(int a){
        long long res = 1;
        for(int i = 1; i <= a; i++){
            res = res * i;
        }
        return res;
    }
};
