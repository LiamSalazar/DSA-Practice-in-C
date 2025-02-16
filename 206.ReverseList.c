# include <stdio.h>
# include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* nextNode = NULL; 
    struct ListNode* prev = NULL;
    while (head != NULL){
        nextNode = head -> next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}