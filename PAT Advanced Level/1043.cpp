#include<iostream>
#include<vector>

using namespace std;

class Node {
    public:
        int val;
        Node * l;
        Node * r;
    Node() {
        this->val = 0;
        this->l = NULL;
        this->r = NULL;
    }
};

Node * insert(Node * node, int val) {
//    cout<<val<<endl;
    if(node == NULL) {
        node = new Node();
        node->val = val;
        return node;
    }
//    cout<<"!!"<<endl;
    if(val < node->val) {
        node->l = insert(node->l, val);
    } else {
        node->r = insert(node->r, val);
    }
    return node;
}

vector<int> pre;
void preOrder(Node * node, bool mirror) {
    if(node == NULL)
        return;
    pre.push_back(node->val);
    if(mirror) {
        preOrder(node->r, mirror);
        preOrder(node->l, mirror);
    } else {
        preOrder(node->l, mirror);
        preOrder(node->r, mirror);
    }
}

vector<int> post;
void postOrder(Node * node, bool mirror) {
    if(node == NULL)
        return;
    if(mirror) {
        postOrder(node->r, mirror);
        postOrder(node->l, mirror);
    } else {
        postOrder(node->l, mirror);
        postOrder(node->r, mirror);
    }
    post.push_back(node->val);
}

void display(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<<(i == vec.size() - 1 ? "" : " ");
    }
    cout<<endl;
}

int main() {
    int n;
    cin>>n;
    
    int t;
    vector<int> data;
    Node * root = NULL;
    for(int i = 0; i < n; i++) {
        cin>>t;
        data.push_back(t);
        root = insert(root, t);
    }
    
    pre.clear();
    preOrder(root, false);
//    display(data);
//    display(pre);
    if(pre == data) {
        cout<<"YES"<<endl;
        post.clear();
        postOrder(root, false);
        display(post);
        return 0;
    }
    pre.clear();
    preOrder(root, true);
    if(pre == data) {
        cout<<"YES"<<endl;
        post.clear();
        postOrder(root, true);
        display(post);
        return 0;
    }
    
    cout<<"NO"<<endl;
    
    return 0;
} 
