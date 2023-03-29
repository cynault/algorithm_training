#include<vector>
#include<unordered_map>
#include<iostream>
#include "leetcode.h"
#include <string>
#include <fmt/core.h>
#include <fmt/format.h>
using namespace tools;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return 0;
        }
        std::vector<int> arr;
        int remainder;
        while(x != 0){ // 将回文数放入arr
            remainder = x%10;
            x = x/10;
            arr.push_back(remainder);
        }
        //fmt::println("{}", fmt::join(arr,", "));
        int l = 0, r = arr.size() - 1;
        while(l < r){
            if(arr[l] != arr[r]){
                return 0;
            }
            l ++;
            r --;
        }
        return 1;
    }
};

int main(){

    tools::LinkedList list{3,7};
    tools::LinkedList list1{9,2};
    Solution s;
    bool res = s.isPalindrome(1211);
    std::cout<<res<<'\n';
}