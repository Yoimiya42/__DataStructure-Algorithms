

class Node:
    def __init__(self, value):
        self.val = value
        self.left = None;
        self.right = None;

    def insert(self, value):
        if value < self.val:
            if self.left is Node:
                self.left = Node(value)
            else:
                self.left.insert(value)
        elif value > self.val:
