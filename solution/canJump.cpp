#include<vector>
#include<unordered_map>
#include<iostream>
#include "leetcode.h"
#include <string>
#include <fmt/core.h>
#include <fmt/format.h>
using namespace std;

class Solution {
public:
// max 能达到的最大下标
// 当 max >= len - 1时，能够跳出成功
// 当 max < i, 代表不能往后跳跃，代表跳出失败
    bool canJump(vector<int>& nums) {
        int len = nums.size();

        int max = 0;
        
        for (int i = 0 ; i < len ; i++ ){
            if(i>max){
                return false;
            }
            max = ((i + nums[i]) > max) ? (i + nums[i]) : max;
        } 
        return true;
    }
};

int main(){

    tools::LinkedList list{3,7};
    tools::LinkedList list1{9,2};
    vector<int> test = {2,3,1,1,4};
    vector<int> test1 = {3,2,1,0,4};
    Solution s;
    time_t startTime = clock();
    auto res = s.canJump(test1);
    time_t endTime = clock();
    std::cout<<res<<'\n';
    std::cout << "TIME : " << double(endTime - startTime)/CLOCKS_PER_SEC << " s" << endl;
}