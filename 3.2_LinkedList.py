
class Node:
    def __init__(self,val):
        self.val = val
        self.next = None


class LinkedList:
    def __init__(self,arr):
        self.head = None
        self.createLinkedList(arr)

    def createLinkedList(self, arr):
        for num in arr:
            self.insertAtTail(num)

    def insertAtHead(self, val):
        newNode = Node(val)
        newNode.next = self.head
        self.head = newNode

    def insertAtTail(self, val):
        newNode = Node(val)

        if self.head is None:
            self.head = newNode
            return
        
        current = self.head
        while current.next:
            current = current.next
        current.next = newNode

    def traverseLinkedList(self):

        if not self.head:
            print("Empty Linked List.")
            return
         
        current = self.head
        index = 0
        while current:
            print(f"Node{index} = {current.val}", end="-> ")
            index += 1
            current = current.next
        print()

    def deleteAtHead(self):
        if not self.head:
            print("Empty Linked List.")
            return
        
        self.head = self.head.next

    def deleteAtTail(self):
        if not self.head:
            print("Empty Linked List.")
            return
        
        if not self.head.next:     ## Only one Node in Linked List
            self.head = Node

        current = self.head
        while current.next.next:
            current = current.next
        current.next = None

    def searchNode(self, target):

        if not self.head:
            print("Empty Linked List.")
            return
        
        current = self.head
        index = 0
        while current:
            if current.val == target:
                return index
            current = current.next
            index += 1
        
        return None
    



if __name__ == "__main__":
    
    arr = []
    print("Now create your linked list. Press 'q' to quit.")
    while True:
        user_input = input("Please input Integer: ")
        
        if user_input == 'q':
            break

        try:
            num = int(user_input)
            arr.append(num)
        except ValueError:
            print("Please input valid Integer or use 'q' to quit.")
    
    ListNode = LinkedList(arr)
    ListNode.traverseLinkedList()

    res = ListNode.searchNode(int(input("Input your target value: ")))
    print(res)
    
    ListNode.deleteAtHead()
    ListNode.insertAtHead(input("Insert at head: "))
    ListNode.insertAtHead(input("Insert at head: "))
    ListNode.insertAtTail(input("Insert at tail: "))
    ListNode.deleteAtTail()
    ListNode.deleteAtTail()
    
    print()
    ListNode.traverseLinkedList()


