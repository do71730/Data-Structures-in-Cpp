#ifndef TREE_STRUCTURE_H
#define TREE_STRUCTURE_H

#include <iostream>
#include <string>

using namespace std;

class tree{
    private:
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
        node* insert(node* root, int value); 
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


tree::node* tree::insert(node* root, int value) {

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

class Binary_Tree:private tree{};
class Binary_Search_Tree:private tree{};
class AVL_Tree:private tree{};
class Splay_Tree:private tree{};
#endif