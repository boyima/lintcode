class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        int n = A.size();
        if(n < 2) return;
        int begin = (n - 2) / 2;
        for(int i = begin; i >= 0; i--){
            int cur = i;
            while((cur * 2 + 1 <= n - 1) && A[cur * 2 + 1] < A[cur] || (cur * 2 + 2 <= n - 1) && A[cur * 2 + 2] < A[cur]){
                if(cur * 2 + 2 > n - 1){//only left exists
                    swap(A[cur], A[cur * 2 + 1]);
                    cur = cur * 2 + 1;
                }
                else{//both left and right exist
                    if(A[cur * 2 + 1] < A[cur * 2 + 2]){
                        swap(A[cur], A[cur * 2 + 1]);
                        cur = cur * 2 + 1;
                    }
                    else{
                        swap(A[cur], A[cur * 2 + 2]);
                        cur = cur * 2 + 2;
                    }
                }
            }
        }
    }
};
