class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        if(L.empty()) return 0;
        // write your code here
        sort(L.begin(), L.end());
        int res = 0;
        int n = L.size();
        int start = 1;
        int end = L[n - 1];
        while(start <= end){
            int mid = start + (end - start) / 2;
            int numPiece = 0;
            for(int i = 0; i < n; i++){
                numPiece = numPiece + L[i] / mid;
            }
            if(numPiece < k){
                end = mid - 1;
            }
            else{
                if(mid > res){
                    res = mid;
                }
                start = mid + 1;
            }
        }
        return res;
    }
};
