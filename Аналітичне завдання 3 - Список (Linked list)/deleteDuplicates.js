function deleteDuplicates(head) {
    let current = head;
  
    while (current && current.next) {
      if (current.val === current.next.val) {
        current.next = current.next.next;
      } else {
        current = current.next;
      }
    }
  
    return head;
  }
  
  function ListNode(val) {
    this.val = val;
    this.next = null;
  }
  
  const head1 = new ListNode(1);
  head1.next = new ListNode(1);
  head1.next.next = new ListNode(2);
  
  const head2 = new ListNode(1);
  head2.next = new ListNode(1);
  head2.next.next = new ListNode(2);
  head2.next.next.next = new ListNode(3);
  head2.next.next.next.next = new ListNode(3);
  
  const result1 = deleteDuplicates(head1);
  const result2 = deleteDuplicates(head2);
  
  function printList(head) {
    const result = [];
    while (head) {
      result.push(head.val);
      head = head.next;
    }
    console.log(result);
  }
  
  printList(result1); 
  printList(result2); 
  