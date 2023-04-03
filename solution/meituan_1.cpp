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

    }
    
    void output_opt(){
        double sum = 0; 
        for (auto num : nums){
            sum += num;
        }
        for(int i = 0 ; i < m ; i++){ // m个操作符，输出三次
            double the_sum = sum;
            int the_num = opts[2*i]; //代表操作符的数字索引
            char the_opt = (char)opts[2*i+1]; // 当前操作符
            double the_val;

            the_sum -= (nums[the_num - 1] + nums[the_num]);
                switch (the_opt)
                {
                case '+':
                    the_val = nums[the_num - 1] + nums[the_num];
                    break;
                
                case '-':
                    the_val = nums[the_num - 1] - nums[the_num];
                    break;

                case '*':
                    the_val = nums[the_num - 1] * nums[the_num];
                    break;

                case '/':
                    the_val = (double)nums[the_num - 1] / (double)nums[the_num];
                    break;         
                default:
                    break;
                }

            the_sum += the_val;

            cout <<setiosflags(ios::fixed)<<setprecision(1)<< the_sum<< " ";
        }
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