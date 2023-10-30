function partition(head, x) {
    let smallerHead = new ListNode(0);
    let smallerTail = smallerHead;
    let greaterHead = new ListNode(0);
    let greaterTail = greaterHead;
    
    while (head) {
      if (head.val < x) {
        smallerTail.next = head;
        smallerTail = smallerTail.next;
      } else {
        greaterTail.next = head;
        greaterTail = greaterTail.next;
      }
      head = head.next;
    }
    
    smallerTail.next = null;
    greaterTail.next = null;
    
    smallerTail.next = greaterHead.next;
    
    return smallerHead.next;
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
  const list = new ListNode(2);
    list.next = new ListNode(1);
    list.next.next = new ListNode(4);
    list.next.next.next = new ListNode(3);
    list.next.next.next.next = new ListNode(2);
    list.next.next.next.next.next = new ListNode(5);
    list.next.next.next.next.next.next = new ListNode(2);
    list.next.next.next.next.next.next.next = new ListNode(4);
  
  const x = 4;
  const partitionedList = partition(list, x); 
  printList(partitionedList);
  