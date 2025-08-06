//1.leetcode 25 K 个一组翻转链表    

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head){
            return nullptr;
        }
        ListNode* start = head;
        ListNode* end = teamEnd(start, k);
        if(end == nullptr){
            return head;
        }
        head = end;
        reverse(start, end);
        ListNode* lastTeamEnd = start;
        while(lastTeamEnd->next){
            start = lastTeamEnd->next;
            end = teamEnd(start, k);
            if(end == nullptr){
                return head;
            }
            reverse(start, end);
            lastTeamEnd->next = end;
            lastTeamEnd = start;
        }
        return head;
    }

    ListNode* teamEnd(ListNode* s, int k){
        while(--k > 0 && s){
            s = s->next;
        }
        return s;
    }

    void reverse(ListNode* start, ListNode* end){
        end = end->next;
        ListNode* cur = start;
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while(cur != end){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        start->next = end;
    }
};


//2.leetcode 160 相交链表

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        int dift = 0;
        ListNode* a1 = h1;
        ListNode* a2 = h2;
        while(a1->next){
            dift++;
            a1 = a1->next;
        }
        a2 = h2;
        while(a2->next){
            dift--;
            a2 = a2->next;
        }
        if(a1 != a2){
            return nullptr;
        }
        a1 = dift > 0? h1 : h2;
        a2 = dift > 0? h2 : h1;
        dift = abs(dift);
        while(--dift >= 0){
            a1 = a1->next;
        }
        while(a1 && a2){
            if(a1 == a2){
                return a1;
            }
            a1 = a1->next;
            a2 = a2->next;
        }
        return a1;
    }
};
