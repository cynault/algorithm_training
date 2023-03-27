#include<vector>
#include<unordered_map>
#include<iostream>
#include "leetcode.h"
#include <string>
#include <fmt/core.h>

using namespace tools;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        int plus = 0;
        int sum = 0;
        while(l1->next != nullptr && l2->next != nullptr){//  当l1 或 l2 出现next为空指针的情况，跳出循环
            sum = (l1 -> val) + (l2 -> val) + plus; //  res[i] = l1[i] + l2[i] 
            plus = sum / 10;                        //  商
            l1 -> val = sum % 10;                   //  余
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        if(l1 ->next != nullptr){ // l1 非空，加上plus，返回l1头 (l1.size > l2.size)
            sum = (l1 -> val) + (l2 -> val) + plus; //  res[i] = l1[i] + l2[i] 
            plus = sum / 10;                        //  商
            l1 -> val = sum % 10; 
            l1 = l1 ->next;
        }
        else if(l2 ->next != nullptr){ // l2 非空，需要给l1加上l2后续链表，返回l2头 (l1.size < l2.size)
            sum = (l1 -> val) + (l2 -> val) + plus; //  res[i] = l1[i] + l2[i] 
            plus = sum / 10;                        //  商
            l1 -> val =  sum % 10; 
            l1 -> next = l2 -> next;
            l1 = l1  ->next;
        }
        else{ // 都为空
            sum = (l1 -> val) + (l2 -> val) + plus; //  res[i] = l1[i] + l2[i] 
            plus = sum / 10;                        //  商
            l1 -> val = sum % 10; 
            b = l1;
            l1 = l1 ->next;
        }
        ListNode * b ;
        while(plus && l1 != nullptr){ // plus 不为0
            sum = l1 ->val + plus;
            l1 -> val = sum %10;
            plus = sum /10;
            b = l1;
            l1 = l1 -> next;
        }
        if(plus){
            b->next = new ListNode(1);
        }

        return head;
    }
};

int main(){

    tools::LinkedList list{3,7};
    tools::LinkedList list1{9,2};
    Solution s;
    ListNode* res = s.addTwoNumbers(list.takeOwnedHead(), list1.takeOwnedHead());
    std::cout<<to_string(LinkedList(res))<<'\n';
}