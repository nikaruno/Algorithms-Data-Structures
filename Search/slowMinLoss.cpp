class Node{
    public:
        long value;
        Node* left;
        Node* right;
        Node(){
            left = NULL;
            right = NULL;
            value = 0;
        };
        Node(int v) : value(v){
            left = NULL;
            right = NULL;
        };
        ~Node(){
            delete left;
            delete right;
        }
        Node* insert(Node* root, long value, long& min);
};

Node* Node::insert(Node *root, long value, long& min){
    if (!root){
        return new Node(value);
    }
    
    if(value>root->value){
        root->right = insert(root->right, value, min);
    }
    
    if(value<root->value){
        if (value - root->value > min){
            min = value - root->value;
        }
        root->left = insert(root->left, value, min);
    }  
    
    return root;  
}

long minimumLoss(vector<long> price) {

    int n = price.size();
    
    long min = -9223372036854775807;
    
    Node* root = NULL;
    Node bst;

    root = bst.insert(root, price[0], min);
    
    for(int i = 1; i<n; ++i){
        bst.insert(root, price[i], min);
    }
    
    return (-min);
}
