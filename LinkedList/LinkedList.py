class Node:
    '''
        ini
    '''
    def __init__(self,data=0) -> None:
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self) -> None:
        self.head = None

    def insert_at_the_first(self,data) -> None:
        '''
                Adding element in the Head of Linked List
        '''
        new_node = Node(data)
        if self.head is None :
            self.head = new_node
        else:
            temp = self.head
            self.head = new_node
            self.head.next = temp

    def insert_at_the_last(self,data) -> None:
        '''
                Adding element in the tail of Linked List
        '''
        if self.head is None :
            print("Linked List is Empty use method 'insert at the first' ")
        else:
            new_node = Node(data)
            temp = self.head
            while True :
                if temp.next is None :
                    temp.next = new_node
                    break
                temp = temp.next

    def insert(self,data,p) -> None:
        '''
                Adding element after another element (p)
        '''
        if self.head is None:
            print("Linked List is Empty use method 'insert at the first' ")
        else:
            new_node=Node(data)
            temp = self.head
            while True:
                if temp.data == p:
                    c= temp.next
                    temp.next = new_node
                    new_node.next = c
                    break
                temp = temp.next


    def delet_last(self) -> None:
        '''
                Delet the tail of Linked List
        '''
        if self.head is None :
            return "Linked List is Empty "
        temp = self.head
        while True:
            if (temp.next).next is None:
                temp .next = None
                break
            temp = temp.next

    def delet(self ,data) -> None:
        '''
                Delet element in Linked List By value
        '''
        if self.head is None :
            return " Linked List is Empty "
        temp = self.head
        while True:
            if (temp.next).data == data:
                c = (temp.next).next
                temp.next = c
                break
            temp = temp.next
    def delet_head(self) -> None:
        '''
                Delet the head of Linked List
        '''
        self.head = self.head.next


    def search(self,d) -> bool:
        '''
                Search element in Linked List if exist or Not 
        '''
        found = False
        temp = self.head
        while temp is not None :
            if temp.data == d:
                found = True
                break
            temp = temp.next
        return found


    def print(self) -> str:
        current = self.head
        while(current):

            print(str(current.data )+" -->",end=" ")
            current = current.next
# test
'''
ll = LinkedList()
ll.insert_at_the_first(6)
ll.insert_at_the_first(7)
ll.insert_at_the_last(9)
ll.insert_at_the_last(7)
ll.insert(88,6)
ll.insert(16,6)
ll.delet_last()
ll.delet(88)
ll.delet_head()
print(ll.search(6))
print(ll.search(88))
ll.print()
'''