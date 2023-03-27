#include<vector>
#include<unordered_map>
#include<iostream>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
int main(){
    std::vector<int> n = {2,7,11,15};
    Solution s;
    std::vector<int> res = s.twoSum(n, 9);
    std::cout<<res[0]<<" "<<res[1]<<"\n";
}