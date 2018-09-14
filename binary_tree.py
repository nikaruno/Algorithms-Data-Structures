class Node(object):
    def __init__(self, value):
        self.value = value
        self.right = None
        self.left  = None

class BinaryTree(object):
    def __init__(self, root):
        self.root = root

    def preorder_search(self, start, value):
        if start:
            if start.value == value:
                return True
            if self.preorder_search(start.left, value):
                return True
            if self.preorder_search(start.right, value):
                return True
        return False

    def search(self, value):
        if self.root:
            if self.root.value == value:
                return True
            if self.preorder_search(self.root.left, value):
                return True
            if self.preorder_search(self.root.right, value):
                return True
        return False

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

tree = BinaryTree(Node(1))
tree.root.left = Node(2)
tree.root.right = Node(3)
tree.root.left.left = Node(4)
tree.root.left.right = Node(5)
tree.root.right.left = Node(6)
tree.root.right.right = Node(7)

if __name__ == "__main__":
    # Test search
    # Should be True
    print (tree.search(4))
    # Should be False
    print (tree.search(9))
    print (tree.preorder_print(tree.root))
    print (tree.postorder_print(tree.root))
