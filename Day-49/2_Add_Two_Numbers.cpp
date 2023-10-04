#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;

    ListNode* result = new ListNode();
    ListNode* temp = result;
    int carry = 0;

    while (temp1 != nullptr || temp2 != nullptr || carry > 0) {
        int sum = carry;
        if (temp1 != nullptr) {
            sum += temp1->val;
            temp1 = temp1->next;
        }
        if (temp2 != nullptr) {
            sum += temp2->val;
            temp2 = temp2->next;
        }

        carry = sum / 10;
        sum = sum % 10;
        ListNode* newnode = new ListNode(sum);
        temp->next = newnode;
        temp = temp->next;
    }

    return result->next;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Create two linked lists to represent the numbers
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Call the addTwoNumbers function
    ListNode* result = addTwoNumbers(l1, l2);

    // Print the result
    cout << "Result: ";
    printLinkedList(result);

    // Clean up memory (not shown in the original code)
    // You should delete the dynamically allocated nodes to avoid memory leaks.

    return 0;
}
