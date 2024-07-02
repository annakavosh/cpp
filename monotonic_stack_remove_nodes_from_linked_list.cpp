#include <stack>
#include <iostream>


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};


class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        std::stack<ListNode*> stack; //create a stack 

        ListNode* current = head;
        while (current) {
            while (!stack.empty() && stack.top()-> val < current->val) {
                stack.pop(); // remove nodes from stack that are smalller than the 
                // current node
            }
            if (!stack.empty()) {
                stack.top() -> next = current; //update next pointer of the top
            }
            stack.push(current);
            current = current->next;
        }
        //get the first node
        current = nullptr;
        while (!stack.empty()) {
            current = stack.top();
            stack.pop();
        }

        return current; //return the head of the modified list
    }
};


//testing
int main() {
    Solution solution;

    //creating the linked list 5 -> 3 -> 7 -> 2 -> 1
    ListNode* head1 = new ListNode(5);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(7);
    head1->next->next->next = new ListNode(2);
    head1->next->next->next->next = new ListNode(1);
    head1 = solution.removeNodes(head1);

    //print the modified linked list
    ListNode* node = head1;
    while (node) {
        std::cout << node->val;
        if  (node -> next) {
            std::cout << " -> ";
        }
        node = node->next;
    }

    return 0;
}