function mergeTwoSortedLists(list1, list2) {
    if (!list1) {
      return list2;
    }
    if (!list2) {
      return list1;
    }
  
    if (list1.val < list2.val) {
      list1.next = mergeTwoSortedLists(list1.next, list2);
      return list1;
    } else {
      list2.next = mergeTwoSortedLists(list1, list2.next);
      return list2;
    }
  }
  
  function ListNode(val) {
    this.val = val;
    this.next = null;
  }
  
  const list1 = new ListNode(1);
  list1.next = new ListNode(2);
  list1.next.next = new ListNode(4);
  
  const list2 = new ListNode(1);
  list2.next = new ListNode(3);
  list2.next.next = new ListNode(4);
  
  const mergedList = mergeTwoSortedLists(list1, list2);
  
  function printList(head) {
    const result = [];
    while (head) {
      result.push(head.val);
      head = head.next;
    }
    console.log(result);
  }
  
  printList(mergedList); 
  