#include<iostream>
using namespace std;
#include <climits>

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

static int f=1;
static bool x=true;
class binarysearchtree{
    private:

        node *successorhelper(int n,node *root){
            node* found=searchnorecur(n,root);
                if(found->right){
                    node *succ= minimumelement(found->right);
                    return succ;
                }
                else{
                    node *succ=nullptr;
                    while (true){
                        if (found->data<root->data){
                            succ=root;
                            root=root->left;
                        }
                        else if(found->data>root->data){
                            root=root->right;
                        }
                        else{
                            break;
                        }
                    }
                    return succ;
                }
        }
        node *predecessorhelper(int n,node *root){
            node* found=searchnorecur(n,root);
                if(found->left){
                    node *succ= maximumelement(found->left);
                    return succ;
                }
                else{
                    node *succ=nullptr;
                    while (true){
                        if (found->data<root->data){
                            root=root->left;
                        }
                        else if(found->data>root->data){
                            succ=root;
                            root=root->right;
                        }
                        else{
                            break;
                        }
                    }
                    return succ;
                }
        }

    node *searchnorecur(int n,node *x){
        while(x!=nullptr && x->data!=n){
            if(n<x->data){
                x=x->left;
            }
            else{
                x=x->right;
            }
        }
        if(x){
            return x;
        }
        return nullptr;
    
    }
    node *searchrecur(int n,node *x){
        if(x==nullptr || x->data==n){
            return x;
        }
        if(n<x->data){
            node *result=searchrecur(n,x->left);
            return result;
        }
        else{
            node *result=searchrecur(n,x->right);
            return result;
        }
    }

    void preorder(node *root){
    if(root==nullptr){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    }

    void inorder(node *root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    }

    node *maximumelement(node *root){
        while(root->right){
            root=root->right;
        }
        return root;
    }

    node *minimumelement(node *root){
        while(root->left){
            root=root->left;
        }
        return root;
    }

    void postorder(node *root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
    
    }

    node* inserthelper(int n,node* x){
    if(x==nullptr){
        node *newnode= new node(n);
        return newnode;
    }
    if(n<x->data){
        x->left=inserthelper(n,x->left);
    }
    else if(n>x->data){
        x->right=inserthelper(n,x->right);
    }
    return x;

    }

    node *deletenode(int n,node* root){
        if(root){
            if(n<root->data){
                root->left=deletenode(n,root->left);
                
            }
            else if(n>root->data){
                root->right=deletenode(n,root->right);
                
            }
            else{
                if (root->left == nullptr && root->right == nullptr) {
                    delete root;
                    return nullptr;
                } 
                else if (root->left == nullptr) {
                    node* temp = root->right;
                    delete root;
                    return temp;
                } 
                else if (root->right == nullptr) {
                    node* temp = root->left;
                    delete root;
                    return temp;
                } 
                else {
                    node* replace = minimumelement(root->right);
                    root->data = replace->data;
                    root->right = deletenode(replace->data, root->right);
                }
            
            }
            return root;
        }
        else{
            f=0;
            return nullptr;
        }
    }
    int maxdepth(node *root){
        if(root==nullptr){
            return 0;
        }
        int left=maxdepth(root->left);
        int right=maxdepth(root->right);
        return 1+ (left>right ? left :right);
    }
    int mindepth(node *root){
        if(root==nullptr){
            return 0;
        }
        int left=mindepth(root->left);
        int right=mindepth(root->right);
        return 1+ (left<right ? left :right);
    }

    bool isBSTUtil(node* root, int minVal, int maxVal) {
        if (root == nullptr)
            return true;
        
        if (root->data <= minVal || root->data >= maxVal)
            return false;

        return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal);
    }
    bool isBST(node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
    }
    node *root;

    public:

    void delnode(int n){
        node *x=deletenode(n,root);
        if(f){
            cout << "successfully deleted"<<endl;
            preorder(root);
        }
        else{
            cout << "not found" << endl;
        }
    }
    void successor(int n){
        node *ans=successorhelper(n,root);
        if(ans){
        cout << ans->data << " is the successor!"<<endl;}
        else{
            cout << "no successor"<<endl;
        }
    }

    void predecessor(int n){
        node *ans=predecessorhelper(n,root);
        if(ans){
        cout << ans->data << " is the predecessor!"<<endl;}
        else{
            cout << "no predecessor"<<endl;
        }
    }

    binarysearchtree(){
        root=nullptr;
    }
    void insert(int n){
        root=inserthelper(n,root);
    }
    void displaypre(){
        preorder(root);
    }
    void displayin(){
        inorder(root);
    }
    void displaypost(){
        postorder(root);
    }
    void searchitem(int val){
        node *item=searchrecur(val,root);
        if(item){
            cout << "item found" << endl;
        }
        else{
            cout << "not found" << endl;
        }
    }
    void searchitemnr(int val){
        node *item=searchnorecur(val,root);
        if(item){
            cout << "item found" << endl;
        }
        else{
            cout << "not found" << endl;
        }
    }
    void maxelement(){
        node *x=maximumelement(root);
        cout << x->data << " is maximum"<< endl;
    }
    void minelement(){
        node *x=minimumelement(root);
        cout << x->data << " is minimum"<< endl;
    }
    void findmaxdepth(){
        int x=maxdepth(root);
        cout << x << " is max depth"<< endl;
    }
    void findmindepth(){
        int x=mindepth(root);
        cout << x << " is min depth"<< endl;
    }
    bool isBinarysearchtree() {
    return isBSTUtil(root, INT_MIN, INT_MAX);
    }

};
//Q1
// int main(){
//     binarysearchtree b1;
//     b1.insert(70);
//     b1.insert(90);
//     b1.insert(85);
//     b1.insert(100);
//     b1.insert(30);
//     b1.insert(60);
//     b1.insert(10);
//     b1.displaypre();
//     cout << endl;
//     b1.displayin();
//     cout << endl;
//     b1.displaypost();
//     cout << endl;
// }
// Q2
// int main(){
//     binarysearchtree b1;
//     b1.insert(70);
//     b1.insert(90);
//     b1.insert(85);
//     b1.insert(100);
//     b1.insert(30);
//     b1.insert(60);
//     b1.insert(10);
//     b1.displaypre();
//     cout << endl;
//     // b1.searchitem(70);
//     // b1.searchitemnr(100);
//     // b1.maxelement();
//     // b1.minelement();
//     b1.successor(100);
//     b1.predecessor(10);
// }
//Q3
// int main(){
//     binarysearchtree b1;
//     b1.insert(100);
//     b1.insert(10);
//     b1.insert(110);
//     b1.insert(105);
//     b1.insert(140);
//     b1.insert(125);
//     b1.insert(135);
//     b1.insert(120);
//     b1.displaypre();
//     cout << endl;
//     b1.delnode(190);
//     b1.findmaxdepth();
//     b1.findmindepth();
// }
//Q4
int main(){
    binarysearchtree b1;
    b1.insert(100);
    b1.insert(200);
    b1.insert(150);
    b1.insert(50);
    b1.insert(250);
    b1.insert(170);
    b1.insert(10);
    b1.insert(90);
    if(b1.isBinarysearchtree()){
        cout << "yes"<<endl;
    }
    else{
        cout << "no"<<endl;
    }

}
