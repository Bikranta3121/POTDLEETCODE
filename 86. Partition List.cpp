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
    ListNode* partition(ListNode* head, int x) {
      vector<int> before_nodes;
      vector<int> after_nodes;
      ListNode *temp=head;
      while(temp!=NULL) 
      {
        if(temp->val < x) before_nodes.push_back(temp->val);
        else after_nodes.push_back(temp->val);  
        temp=temp->next;
      } 
      temp=head;
     
      for(int i=0;i<before_nodes.size();i++)
      {
          temp->val=before_nodes[i];
          temp=temp->next;
      }
      for(int j=0;j<after_nodes.size();j++)
      {
          temp->val=after_nodes[j];
          temp=temp->next;
      }
      return head;
    }
};
