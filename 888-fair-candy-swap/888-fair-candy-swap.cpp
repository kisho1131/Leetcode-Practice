class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0;
        int sumB = 0;
        for(auto ele : A)
            sumA+= ele;
        for(auto ele : B)
            sumB+= ele;
        
        // sumA - x + y = sumB -y+x
        int target = (sumA-sumB)/2;
        set<int>bob;
        for(int i =0;i<B.size();i++){
            bob.insert(B[i] + target);
        }
        for(int i = 0;i<A.size();i++){
            if(bob.find(A[i]) != bob.end())
                return {A[i], A[i]-target};
        }
        return {};
    }
};