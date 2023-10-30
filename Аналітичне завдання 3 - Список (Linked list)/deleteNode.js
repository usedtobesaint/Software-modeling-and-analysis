function deleteNodeByValue(head, targetValue) {
    if (head !== null && head.val === targetValue) {
      return head.next;
    }
  
    let current = head;
  
    while (current !== null && current.next !== null) {
      if (current.next.val === targetValue) {
        current.next = current.next.next; 
        return head; 
      }
      current = current.next;
    }
  
    return head; 
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
  
  const head = new ListNode(4);
  head.next = new ListNode(5);
  head.next.next = new ListNode(1);
  head.next.next.next = new ListNode(9);
  
  const targetValue = 1; 
  
  const newHead = deleteNodeByValue(head, targetValue);

  printList(newHead);
  