class Node(object):
    def __init__(self, value):
        self.value = value
        self.right = None
        self.left  = None

class BinarySearchTree(object):
    def __init__(self, root):
        self.root = root

    def insert(self, node):
        if self.root is None:
            self.root = node
        else:
            if self.root.value > node.value:
                if self.root.left is None:
                    self.root.left = node
                else:
                    self.insert_helper(self.root.left, node)
            else:
                if self.root.right is None:
                    self.root.right = node
                else:
                    self.insert_helper(self.root.right, node)

    def insert_helper(self, root, node):
        if root.value > node.value:
            if root.left is None:
                root.left = node
            else:
                self.insert_helper(root.left, node)
        else:
            if root.right is None:
                root.right = node
            else:
                self.insert_helper(root.right, node)        
                           
    
    def search_helper(self, start, value):
        if start:
            if start.value == value:
                return True
            if start.value > value:
                return self.search_helper(start.left, value)
            if start.value < value:
                return self.search_helper(start.right, value)
        return False

    def search(self, value):
        if self.root:
            if self.root.value == value:
                return True
            elif self.root.value > value:
                return self.search_helper(self.root.left, value)
            else:
                return self.search_helper(self.root.right, value)


    def preorder_print(self, start):
        a = []
        if start:
            a.append(start.value)
        if start.left:
            a += self.preorder_print(start.left)
        if start.right:
            a += self.preorder_print(start.right)
        return a

    def inorder_print(self, start):
        a = []
        if start:    
            if start.left:
                a += self.inorder_print(start.left)
            a.append(start.value)
            if start.right:
                a += self.inorder_print(start.right)
        return a

    def postorder_print(self, start):
        a = []
        if start:    
            if start.left:
                a += self.postorder_print(start.left)
            if start.right:
                a += self.postorder_print(start.right)
            a.append(start.value)
        return a


if __name__ == "__main__":
    bst = BinarySearchTree(Node(5))
    bst.insert(Node(3))
    bst.insert(Node(7))
    bst.insert(Node(16))
    bst.insert(Node(9))
    bst.insert(Node(25))
    bst.insert(Node(2))
    bst.insert(Node(1))
    print(bst.inorder_print(bst.root))
    print(bst.search(125))
    print(bst.search(25))
