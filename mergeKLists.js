function mergeKLists(lists) {
    if (lists.length === 0) return null;
    if (lists.length === 1) return lists[0];
  
    function mergeTwoLists(l1, l2) {
      const dummy = new ListNode(0);
      let current = dummy;
  
      while (l1 && l2) {
        if (l1.val < l2.val) {
          current.next = l1;
          l1 = l1.next;
        } else {
          current.next = l2;
          l2 = l2.next;
        }
        current = current.next;
      }
  
      current.next = l1 || l2;
  
      return dummy.next;
    }
  
    const merge = (lists, left, right) => {
      if (left === right) return lists[left];
      const mid = Math.floor((left + right) / 2);
      const l1 = merge(lists, left, mid);
      const l2 = merge(lists, mid + 1, right);
      return mergeTwoLists(l1, l2);
    };
  
    return merge(lists, 0, lists.length - 1);
  }
  
  function ListNode(val) {
    this.val = val;
    this.next = null;
  }

  function printList(head) {
    const result = [];
    while (head) {
      result.push(head.val);
      head = head.next;
    }
    console.log(result);
  }
  
  const list1 = new ListNode(1);
  list1.next = new ListNode(4);
  list1.next.next = new ListNode(5);
  
  const list2 = new ListNode(1);
  list2.next = new ListNode(3);
  list2.next.next = new ListNode(4);
  
  const list3 = new ListNode(2);
  list3.next = new ListNode(6);
  
  const mergedList = mergeKLists([list1, list2, list3]);
  printList(mergedList); 
  