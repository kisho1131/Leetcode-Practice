class Solution {
public:
    bool isOdd(int n){
        return n % 2 !=0;
    }
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        vector<int>ans;
        int n = q.size();
        int sum =0;
        for(int j =0;j<n;++j){
                if(!(nums[j]&1))
                    sum += nums[j];
            }
        //cout<<sum;
        for(int i =0;i<n;++i){
            int val = q[i][0];
            int idx = q[i][1];
           // cout<<val<<"->"<<idx<<endl;
           // nums[idx] = nums[idx] + val;
            //cout<<nums[idx]<<" "<<endl;
            if(isOdd(nums[idx]) and !isOdd(nums[idx]+val))
                {sum += nums[idx] + val;
                cout<<"first"<<endl;}
            if(!isOdd(nums[idx]) and isOdd(nums[idx]+val))
                {sum -= nums[idx];
                cout<<"second"<<endl;}
            if(!isOdd(nums[idx]) and !isOdd(nums[idx]+val))
                {sum += val;
                cout<<"third"<<endl;}
            //cout<<sum<<" ";
            ans.push_back(sum);
            nums[idx] = nums[idx] + val;
            //cout<<nums[idx]<<" "<<endl;
        }
        return ans;
    }
};