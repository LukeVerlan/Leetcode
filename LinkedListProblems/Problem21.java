/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {

        if(list1 == null && list2 == null){
            return null;
        } else if(list1 == null){
            return list2;
        } else if(list2 == null){
            return list1;
        }

        ListNode l3Head;

        if(list1.val <= list2.val){ 
            l3Head = new ListNode(list1.val);
            list1 = list1.next; 
        } else {
            l3Head = new ListNode(list2.val);
            list2 = list2.next; 
        }

        ListNode l3 = l3Head;

        while(list1 != null && list2 != null) {
             if(list1.val <= list2.val){
                l3.next = list1;
                list1 = list1.next; 
             } else {
                l3.next = list2; 
                list2 = list2.next;
             }
             l3 = l3.next; 
        }
        
        if(list1 == null && list2 != null){
            l3.next = list2;
        } else if (list1 != null && list2 == null){
            l3.next = list1;
        }

        return l3Head; 
    }
}