class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> st;
        
        for(int i=0; i<nums.size(); ++i){
            st[nums[i]] = i;
        }
        
        for(int i=0; i<nums.size(); ++i){
            map<int, int>::iterator it = st.find(target - nums[i]);
            if(it != st.end() && it->second != i){
                return {i, it->second};
            }
        }
        
        return {};
    }
};
