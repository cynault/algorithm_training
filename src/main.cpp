#include<vector>
#include<unordered_map>

#include "leetcode.h"
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if(len < 3)
            return res;
        for (int i = 0; i < len-2; i++){
            int left = i + 1, right = len - 1;
            if(nums[i] > 0){
                return res;
            }
            // 双指针
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    res.push_back({nums[i], nums[left], nums[right]});

                    do
                    {
                        left++;
                        right--;
                    }while( (left < right) && (nums[left] == nums[left-1]) && (nums[right] == nums[right+1]) );
                    
                }
                else if(sum < 0){
                    left ++;
                }
                else{
                    right --;
                }
            }
            while( (i < len -2) && nums[i] == nums[i+1] ){
                i++;
            }
        }
        return res;
    }
};

int main(){

    tools::LinkedList list{3,7};
    tools::LinkedList list1{9,2};
    vector<int> test = {0,0,0,0};
    vector<int> test1 = {-2,0,1,1,2};
    Solution s;
    time_t startTime = clock();
    auto res = s.threeSum(test1);
    time_t endTime = clock();

}