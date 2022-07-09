class Solution {
public:
    const long long int mod = 1000000007;
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        int n = hc.size();
        int m = vc.size();
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        vector<int>height = {hc[0]};
        vector<int>width = {vc[0]};
        
        for(int i =1;i<n;i++){
            height.push_back(hc[i] - hc[i-1]);
        }
        height.push_back(h - hc[n-1]);
        
        for(int i = 1;i<m;i++){
            width.push_back(vc[i] - vc[i-1]);
        }
        width.push_back(w-vc[m-1]);
        
        int maxh = *max_element(height.begin(), height.end());
        int maxw = *max_element(width.begin(), width.end());
        
        return maxh%mod * maxw%mod;
    }
};