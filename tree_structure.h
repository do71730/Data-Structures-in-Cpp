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
        node *root;
        void pre_order();
        void in_order();
        void post_order();
    public:
        tree();
        tree(int num);
        ~tree();
        void insert(int num);
        void delete_value(int num);
        void traversal(string type);
        int height();
        void search(int value);




};

inline tree::tree(){
    root = new node ();
    root->value = -1; 
    root->parent = nullptr; 
    root->left_child=nullptr; 
    root->right_child=nullptr;
}

inline tree::tree(){
    node* n = new node();
    n->value = -1; 
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

inline void tree::traversal(string type){
    if(type == "post_order"){
            post_order();
    }else if (type == "pre_order"){
        pre_order();
    }else{
        in_order();
    }
}

class Binary_Tree:private tree{};
class Binary_Search_Tree:private tree{};
class AVL_Tree:private tree{};
class Splay_Tree:private tree{};
#endif