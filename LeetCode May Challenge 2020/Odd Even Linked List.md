## Odd Even Linked List

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

### Example 1:

```
Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
```
### Example 2:
```
Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
```
### Note:

- The relative order inside both the even and odd groups should remain as it was in the input.
- The first node is considered odd, the second node even and so on ...

### Approach:

The intuitive idea is to traverse through to find the odd nodes first. Then iterate again to find even nodes, and finally string together.

But there are two problems, if you do not modify the node, you need to use additional space, the space complexity is N. If modified, it will affect the second traversal (traversing even nodes).

> Therefore, a method can be adopted: iterate once and modify two nodes at the same time in each step, so that the above two problems can be avoided.

### Key point analysis
>Use virtual nodes to simplify operations

> The end condition of the loop is set to odd && odd.next && even && even.next, it should not be odd && even, otherwise it is necessary to record the last node of the odd node, which complicates the operation

### SOLUTION:

```cpp
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
    ListNode* oddEvenList(ListNode* head) {
                if (head == nullptr) return head;
        auto odd = head, evenHead = head->next, even = head->next;
        // because "after each loop "odd before even", the loop condition can only judge whether even and even-> next are empty, and modify the operations of odd and even can also simplify
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
```

> ## Resources:
> - [Medium Article](https://medium.com/@saurav.agg19/odd-even-linked-list-a1cce50e737b)
> - [Tutorial](https://www.techiedelight.com/rearrange-linked-list-separating-odd-nodes-even/)


***