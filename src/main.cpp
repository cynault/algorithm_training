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
    /*
        1. max note most long size； pre ：pre index location
        2. 当窗口没有重复，正常往下滑，将字符串对应字符和其在串中的索引加入到hashtable
        3. 出现重复 s[x] = s[i]
            1. 记录长度，比较大小
            2. 将出现重复的点，到pre处的字符，从hash表中消除
            3. 重新定位pre
    */
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> hashtable;
        int max = 0, pre = 0, cur = 0;
        int len = s.length();

        int i;
        for(i=0;i<len;i++){
            
            auto it = hashtable.find(s[i]);
            if(it == hashtable.end()){ // 窗口没有重复，滑动窗口向前
                hashtable.insert({s[i], i});
                continue;
            }
            // 出现重复，比较大小
            cur = i - pre ;
            if (max < cur){
                max = cur;
            }
            // 消除s[pre ... it->second)
            int find_repeat = it -> second;
            for (int j = pre; j <= find_repeat ; j++){
                auto eit = hashtable.find(s[j]);
                hashtable.erase(eit);
                if(j == find_repeat){
                    hashtable.insert({s[i],i});
                }
            }
            pre = find_repeat + 1;
        }

        cur = i - pre;
            if (max < cur){
                max = cur;
            }
        
        return max;
    }
};

int main(){

    tools::LinkedList list{3,7};
    tools::LinkedList list1{9,2};
    Solution s;
    int res = s.lengthOfLongestSubstring("abcabcbb");
    std::cout<<res<<'\n';
}