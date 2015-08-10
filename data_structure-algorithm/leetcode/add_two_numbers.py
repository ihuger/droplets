# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def addTwoNumbers(self, l1, l2):
        if l1 is None:
            return l2

        if l2 is None:
            return l1

        l3 = ListNode(0)
        cur = l3
        up = 0

        while l1 is not None or l2 is not None:

            if l1 is None:
                v1 = 0
            else:
                v1 = l1.val

            if l2 is None:
                v2 = 0
            else:
                v2 = l2.val

            cur.next  = ListNode(0)
            cur = cur.next

            val = v1 + v2 + up
            if val>=10 :
                up = 1
            else:
                up = 0
            val %= 10
            cur.val = val

            if l1 is not None:
                l1 = l1.next

            if l2 is not None:
                l2 = l2.next
        if up != 0:
            cur.next  = ListNode(up)

        return l3.next

if __name__ == "__main__":
    l1 = ListNode(5)
    #l0.next = ListNode(2)

    l2 = ListNode(5)

    l3 =  Solution().addTwoNumbers(l1,l2)
    while l3 is not None:
        print l3.val
        l3 = l3.next


