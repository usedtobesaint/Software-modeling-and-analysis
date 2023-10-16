class ListNode {
    constructor(val) {
      this.val = val;
      this.next = null;
    }
  }
  
  function addNode(head, val) {

    if (val < 0 || val > 100) {
        console.error("Invalid node value:", val);
        return head;
    }

    const newNode = new ListNode(val);
  
    if (head === null) {
      return newNode;
    }
  
    let current = head;
    while (current.next !== null) {
      current = current.next;
    }
  
    current.next = newNode;
  
    return head; 
  }
  
  function swapPairs(head) {
    if (head === null || head.next === null) {
        return head;
      }
      const nextNode = head.next;

      head.next = swapPairs(nextNode.next);
    
      nextNode.next = head;
    
      return nextNode;
  }
  
  let head=null;
  head=addNode(head,1);
  head=addNode(head,2);
  head=addNode(head,3);
  head=addNode(head,4);
  head=addNode(head,5);
  head=addNode(head,6);
  
  const newHead = swapPairs(head);
  
    let current = newHead;
    while (current != null) {
      console.log(current.val);
      current = current.next;
    }
    
  