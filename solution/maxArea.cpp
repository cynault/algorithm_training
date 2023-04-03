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
    int maxArea(vector<int>& height) {
        int max_area = 0, left = 0, right = height.size()-1;
        while(left < right){
            int area = (right - left) * min(height[right], height[left]);
            max_area = max(area, max_area);
            if(height[left] < height[right]){
                left ++ ;
            }
            else{
                right --;
            }
        }
        return max_area;
    }
};

int main(){

    tools::LinkedList list{3,7};
    tools::LinkedList list1{9,2};
    vector<int> test = {2,3,1,1,4};
    vector<int> test1 = {1,8,6,2,5,4,8,3,7};
    Solution s;
    time_t startTime = clock();
    auto res = s.maxArea(test1);
    time_t endTime = clock();
    std::cout<<res<<'\n';
    std::cout << "TIME : " << double(endTime - startTime)/CLOCKS_PER_SEC << " s" << endl;
}