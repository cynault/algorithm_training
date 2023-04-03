#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include "leetcode.h"
#include <string>
#include <fmt/core.h>
#include <fmt/format.h>
using namespace std;

class Solution {
public:
    // dp记录出现字符位置
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> str_set;
        int len = s.length();
        vector<int> dp{0};
        for(auto word : wordDict){
            str_set.insert(word);
        }
        for(int i = 0; i <= len; i++){
            for(int j = 0; j < dp.size(); j++){
                int index_dp = dp[j];
                string sub_str = s.substr(index_dp, i-index_dp);
                if(str_set.find(sub_str) != str_set.end()){
                    dp.push_back(i);
                    break;
                }
            }
        }
        int res = dp[dp.size() - 1];
        return  res == (len - 1) || res == len;
    }
};

int main(){

    tools::LinkedList list{3,7};
    tools::LinkedList list1{9,2};
    vector<string> test = {"apple","pen"};
    string str = "applepenapple";
    Solution s;
    time_t startTime = clock();
    auto res = s.wordBreak(str, test);
    time_t endTime = clock();
    std::cout<<res<<'\n';
    std::cout << "TIME : " << double(endTime - startTime)/CLOCKS_PER_SEC << " s" << endl;
}