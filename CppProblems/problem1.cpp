// 2 ms runtime 16mb memory

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]] = i; 
        }

        for(int i = 0; i < nums.size(); i++){
            int needed = target - nums[i];
            if(map.contains(needed) && i != map[needed]){
                return {i, map[needed]};
            }
        }
        
        return {};
    }
}