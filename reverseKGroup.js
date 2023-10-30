function reverseKGroup(head, k) {
    if (!head || k === 1) {
      return head;
    }
    
    const dummy = new ListNode(0);
    dummy.next = head;
    let prev = dummy;
    
    let curr = head;
    let len = 0;
    
    while (curr) {
      len++;
      curr = curr.next;
    }
    
    curr = head;
    
    for (let i = 0; i < Math.floor(len / k); i++) {
      let first = curr;
      let prevTemp = prev;
      
      for (let j = 0; j < k; j++) {
        let temp = curr.next;
        curr.next = prevTemp;
        prevTemp = curr;
        curr = temp;
      }
      
      prev.next = prevTemp;
      first.next = curr;
      prev = first;
    }
    
    return dummy.next;
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
  
  const list = new ListNode(1);
  list.next = new ListNode(2);
  list.next.next = new ListNode(3);
  list.next.next.next = new ListNode(4);
  list.next.next.next.next = new ListNode(5);
  
  const k = 2;
  const reversedList = reverseKGroup(list, k);
  
  printList(reversedList);
  