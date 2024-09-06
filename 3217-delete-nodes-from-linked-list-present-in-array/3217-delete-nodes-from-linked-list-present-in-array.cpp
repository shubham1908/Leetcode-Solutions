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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int, int> mp;
        for(auto num: nums){
            mp[num] = 1;
        }
        return fun(head, new ListNode(0, head), mp);
    }
    
    ListNode* fun(ListNode* cur, ListNode* pre, map<int, int> &mp){
        if(cur == NULL){
            return NULL;
        }
        if(mp[cur->val] == 1){
            cur = fun(cur->next, pre, mp);
        } else {
            cur->next = fun(cur->next, cur, mp);
        }
        return cur;
    }
};