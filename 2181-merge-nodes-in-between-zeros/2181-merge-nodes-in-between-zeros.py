class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur_l = head
        cur_r = head.next
        running_sum = 0
        
        while cur_r is not None:
            if cur_r.val != 0:
                running_sum += cur_r.val
                cur_r = cur_r.next
            elif cur_r.val == 0:
                cur_l.next.val = running_sum
                cur_l = cur_l.next
                cur_l.next = cur_r
                running_sum = 0
                cur_r = cur_r.next
                
        cur_l.next = None
        
        return head.next
