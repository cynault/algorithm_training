#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include <string>
#include<algorithm>
#include<iomanip>
using namespace std;

class Solution {
private:
    int n; // 表示多少个连加数
    vector<int> nums;
    

public:
    void input_data(){
        cin >> n;

        for (int i=0; i < n ; i++){
            int num;
            cin >> num;
            nums.push_back(num);
        }

        std::sort(nums.begin(), nums.end());

    }
    
    void output_opt(){
        int sum = 0; 
        for(int i = 0; i < n-1 ; i++){
            sum += (nums[i + 1] - nums[i]);
        }
        cout << sum;
    }
};

int main(){
    /*
    5
    1 2 4 2 5
    3
    1 - 2 * 4 /
    */
    Solution s;
    s.input_data();

    s.output_opt();

}