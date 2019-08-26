#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> inorder, postorder;
int n;

class Node {
    public:
    Node * left;
    Node * right;
    int val;
    Node (int val) {
        this->left = NULL;
        this->right = NULL;
        this->val = val;
    }
};

Node * get_node(int in_s, int in_e, int po_s, int po_e) {
    if (po_s > po_e) {
        return NULL;
    }  
    int root = postorder[po_e];
//    cout<<root<<endl;
    Node * node = new Node(root);
    
    if (po_s == po_e) {
        return node;
    }
    
    int middle = in_e;
    // Find root
    for(int i = in_s; i <= in_e; i++) {
        if (inorder[i] == root) {
            middle = i;
            break;
        }
    }
    node->left = get_node(in_s, middle - 1, po_s, po_s + (middle - in_s) - 1);
    node->right = get_node(middle + 1, in_e, po_s + (middle - in_s), po_e - 1);
    
    return node;
}

int main() {
    int T, t;
    cin>>n;
    
    T = n;
    while (T--) {
        cin>>t;
        postorder.push_back(t);
    }
    T = n;
    while (T--) {
        cin>>t;
        inorder.push_back(t);
    }
    
    Node * root = get_node(0, n-1, 0, n-1);
    
    queue<Node *> it_q;
    it_q.push(root);
    while(it_q.size()){
        Node * tmp = it_q.front();
        if (tmp->left) {
            it_q.push(tmp->left);
        }
        if (tmp->right) {
            it_q.push(tmp->right);
        }
        it_q.pop();
        cout<<tmp->val<<(it_q.size() ? " " : "");
    }
    
    return 0;
}
