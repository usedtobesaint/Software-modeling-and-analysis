function reorderList(head) {
  if (!head || !head.next) {
    return head;
  }

  let slow = head;
  let fast = head;

  while (fast.next && fast.next.next) {
    slow = slow.next;
    fast = fast.next.next;
  }

  let middle = slow.next;
  slow.next = null;

  let prev = null;
  let current = middle;

  while (current) {
    let next = current.next;
    current.next = prev;
    prev = current;
    current = next;
  }

  let first = head;
  let second = prev;

  while (second) {
    let firstNext = first.next;
    let secondNext = second.next;

    first.next = second;
    second.next = firstNext;

    first = firstNext;
    second = secondNext;
  }
}

function ListNode(val) {
  this.val = val;
  this.next = null;
}

const head1 = new ListNode(1);
head1.next = new ListNode(2);
head1.next.next = new ListNode(3);
head1.next.next.next = new ListNode(4);

const head2 = new ListNode(1);
head2.next = new ListNode(2);
head2.next.next = new ListNode(3);
head2.next.next.next = new ListNode(4);
head2.next.next.next.next = new ListNode(5);

reorderList(head1);
reorderList(head2);

function printList(head) {
  const result = [];
  while (head) {
    result.push(head.val);
    head = head.next;
  }
  console.log(result);
}

printList(head1); 
printList(head2);
