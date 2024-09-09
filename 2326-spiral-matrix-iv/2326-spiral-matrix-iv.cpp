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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int i=0, j=0;
        vector<vector<int>> ans(m, vector<int> (n, -1));
        ListNode* temp = head;
        int top = 0, left = 0;
        int bottom = m-1, right = n-1;
        int row = 0, col = 0;
        while (temp != NULL) {
            for (col = left; col <= right && temp != NULL; col++) {
                ans[top][col] = temp->val;
                temp = temp->next;
            }
            top++;
            for (row = top; row <= bottom && temp != NULL; row++) {
                ans[row][right] = temp->val;
                temp = temp->next;
            }
            right--;
            for (col = right; col >= left && temp != NULL; col--) {
                ans[bottom][col] = temp->val;
                temp = temp->next;
            }
            bottom--;
            for (row = bottom; row >= top && temp != NULL; row--) {
                ans[row][left] = temp->val;
                temp = temp->next;
            }
            left++;
        }

        return ans;
    }
};