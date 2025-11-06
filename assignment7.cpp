#include<iostream>
using namespace std;

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
    else{
        x->right=inserthelper(n,x->right);
    }
    return x;

    }



    node *root;

    public:

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
int main(){
    binarysearchtree b1;
    b1.insert(70);
    b1.insert(90);
    b1.insert(85);
    b1.insert(100);
    b1.insert(30);
    b1.insert(60);
    b1.insert(10);
    b1.displaypre();
    cout << endl;
    // b1.searchitem(70);
    // b1.searchitemnr(100);
    // b1.maxelement();
    // b1.minelement();
    b1.successor(100);
    b1.predecessor(10);
}