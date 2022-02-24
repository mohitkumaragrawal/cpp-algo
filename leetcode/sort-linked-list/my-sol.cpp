// https://leetcode.com/problems/sort-list/
struct ListNode {
  ListNode* next;
  int val;

  ListNode(): next(nullptr), val(0) {}
  ListNode(int v): val(v) {}
  ListNode(int v, ListNode* n) : val(v), next(n) {}
};

class Solution {
  ListNode* findMid(ListNode* head) {
    ListNode* fastPointer = head->next;
    ListNode* slowPointer = head;
    
    while (fastPointer && fastPointer->next) {
      fastPointer = fastPointer->next->next;
      slowPointer = slowPointer->next;
    }
    return slowPointer;
  }
  
  ListNode* mergeList(ListNode* first, ListNode* second) {
    ListNode* newHead = new ListNode();
    ListNode* itr = newHead;
    
    while (first && second) {
      if (first->val < second->val) {
        itr->next = first;
        itr = itr->next;
        first = first->next;
      } else {
        itr->next = second;
        itr = itr->next;
        second = second->next;
      }
    }
    itr->next = first ? first : second;    
    return newHead->next;
  }
  
public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    
    ListNode* mid = findMid(head);
    ListNode* secondHead = mid->next;
    mid->next = nullptr;
    
    ListNode* firstHalfSorted = sortList(head);
    ListNode* secondHalfSorted = sortList(secondHead);
    
    return mergeList(firstHalfSorted, secondHalfSorted);        
  }
};