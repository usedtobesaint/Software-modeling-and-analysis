function doubleNumber(head) {
  let number = 0;
  let current = head;

  while (current !== null) {
    number = number * 10 + current.val;
    current = current.next;
  }

  number *= 2; 

  const result = [];
  while (number > 0) {
    result.push(number % 10);
    number = Math.floor(number / 10);
  }

  let dummy = new ListNode(0);
  let curr = dummy;
  while (result.length > 0) {
    curr.next = new ListNode(result.pop());
    curr = curr.next;
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

const head1 = new ListNode(1);
head1.next = new ListNode(8);
head1.next.next = new ListNode(9);

const doubledList1 = doubleNumber(head1);
printList(doubledList1); 

const head2 = new ListNode(9);
head2.next = new ListNode(9);
head2.next.next = new ListNode(9);

const doubledList2 = doubleNumber(head2);
printList(doubledList2);