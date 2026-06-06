#ifndef TREE_STRUCTURE_H
#define TREE_STRUCTURE_H

#include <iostream>
#include <string>

using namespace std;

class tree{
    protected:
        struct node {
            int value;
            node * parent;
            node * left_child;
            node * right_child;
        };
        void pre_order(node * root);
        void in_order(node* root);
        void post_order(node *root);
        
    public:
        node *root;
        tree();
        tree(int num);
        void delete_tree(node * root);
        virtual node* insert(node* root, int value); 
        void delete_value(int num);
        void traversal(string type,node * root);
        int height();
        void search(node* root,  int value);





};

inline void tree::delete_tree(node * root){
    if(root == nullptr){
        return;
    }
    delete_tree(root->left_child);
    delete_tree(root->right_child);
    delete root;
}


tree::node* tree::insert(node* root,int value) {

    if (root == nullptr){
        root = new node();
        root->value = value;
        root->right_child = nullptr;
        root->left_child = nullptr;
        root->parent =  nullptr;
        return root;
    }

    if (root->left_child == nullptr){
            node* n = new node();
            n->value = value;
            n->right_child=nullptr;
            n->left_child = nullptr;
            n->parent = root; //?? Dont think this is right
            root->left_child = n;
    }else if (root->right_child ==nullptr){
            node* n = new node();
            n->value = value;
            n->right_child=nullptr;
            n->left_child = nullptr;
            n->parent = root; //?? Dont think this is right
            root->right_child = n;
    }else{
            insert(root->left_child,value);
    }
    return root;

}

inline tree::tree(){
    root = nullptr;
}

inline tree::tree(int num){
    node* n = new node();
    n->value = num; 
    n->parent = nullptr; 
    n->left_child=nullptr; 
    n->right_child=nullptr;
}

inline tree::~tree(){
    if (root == nullptr || root->value == -1){
        delete root;
        root == nullptr;
    }

}

inline void tree::traversal(string type,node * root){
    if(type == "post_order"){
            post_order(root);
    }else if (type == "pre_order"){
        pre_order(root);
    }else{
        in_order(root);
    }
}


//left, parent, right
void inline tree::in_order(node * root){
    if (root == nullptr){
        return;
    }
    in_order(root->left_child);
    cout << root->value << "->";
    in_order(root->right_child);

}

//parent,left,right
void inline tree::pre_order(node * root){
    if(root == nullptr){
        return;
    }
    cout << root->value << "->";
    pre_order(root->left_child);
    pre_order(root->right_child);

}

//left,right, parent
void inline tree::post_order(node * root){
    if(root == nullptr){
        return;
    }
    post_order(root->left_child);
    post_order(root->right_child);
    cout << root->value << "->";
}

class Binary_Tree:public tree{
    public:
        Binary_Tree();
        Binary_Tree(int value);
};
class Binary_Search_Tree:public tree{
    public:

        node* insert(node* root, int value) override{}
        Binary_Search_Tree();
        Binary_Search_Tree(int value);

};
class AVL_Tree:public tree{
    public:
        node* insert(node* root, int value) override{}
        AVL_Tree();
        AVL_Tree(int value);

};
class Splay_Tree:public tree{
    public:
        node* insert(node* root, int value) override{}
        Splay_Tree();
        Splay_Tree(int value);
};


Binary_Search_Tree::node* Binary_Search_Tree::insert(node* root, int value) {

    if (root == nullptr){
        root = new node();
        root->value = value;
        root->right_child = nullptr;
        root->left_child = nullptr;
        root->parent =  nullptr;
        return root;
    }

    if(value < root->value){
        //go left
        if(root->left_child == nullptr){
            node* n = new node();
            n->value = value;
            n->right_child=nullptr;
            n->left_child = nullptr;
            n->parent = root; //?? Dont think this is right
            root->left_child = n;
        }else{
            insert(root->left_child, value);
        }

    //go right
    }else if(value > root->value){
        if(root->right_child ==nullptr){
            node* n = new node();
            n->value = value;
            n->right_child=nullptr;
            n->left_child = nullptr;
            n->parent = root; //?? Dont think this is right
            root->right_child = n;
        }else{
            insert(root->right_child, value);
        }
    }
    return root;
}
#endif