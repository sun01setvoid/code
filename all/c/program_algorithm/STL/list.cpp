//leetcode234
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        auto pre=head,last=head;
        //前指针下中位数，后指针可看看元素奇偶性
        while (last->next!=nullptr && last->next->next!=nullptr){
            pre=pre->next;
            last=last->next->next;
        }
        ListNode* pre0=nullptr,*cur0=nullptr,*next0=nullptr;
        if (last->next!=nullptr) cur0=pre->next,pre->next=nullptr;
        else cur0=pre;
        while (cur0!=nullptr){
            next0=cur0->next;
            cur0->next=pre0;
            pre0=cur0;
            cur0=next0;
        }
        for (auto lt1=head,lt2=pre0;lt1!=nullptr && lt2!=nullptr;lt1=lt1->next,lt2=lt2->next){
            if (lt1->val!=lt2->val) return 0;
        }
        return 1;
    }
};
*/