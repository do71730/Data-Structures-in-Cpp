#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <iostream>
using namespace std;
const int INT_MIN =-2147483648;

class structure{
    private:
        struct node{
            int num;
            node* next;
            node* prev;
        };
        node* head;
        node* tail;
        int count;
        
    public:
        structure();
        structure(int num);
        bool empty(){return (count == 0)? true:false;}
        void push_back(int num);
        void push_front(int num);
        void pop_back();
        void pop_front();
        void display();
        int size() {return count;}
        void sort();
        void erase(int index);
        void deleted();
        int front(){return (head == nullptr)? INT_MIN : head->num;}
        int back(){return (tail == nullptr)? INT_MIN : tail->num;}
        int& operator[](int index);
        int& at(int index);

};

inline structure::structure(){
    head = nullptr;
    tail = nullptr;
    count = 0;
}

inline structure::structure(int num){
    node* n = new node;
    n->num = num;
    n->next = nullptr;
    n->prev = nullptr;
    head = n;
    tail = n;
    count = 1;
}

inline int& structure::at(int index){
    int n = INT_MIN;
    try{
        if (index < 0 || index >= count){
            throw 404;
        }else{
            node *curr = head;
            for(int i =0; i<index; i++){
                curr = curr->next;
            }
            return curr->num;
        }

    }catch(...){
        cout << "Index out of bound!\n \n";
    }
    return n;
}

inline int& structure::operator[](int index){
    int n = INT_MIN;
    try{
        if (index < 0 || index >= count){
            throw 404;
        }else{
            node *curr = head;
            for(int i =0; i<index; i++){
                curr = curr->next;
            }
            return curr->num;
        }

    }catch(...){
        cout << "Index out of bound!\n \n";
    }
    return n;
}

inline void structure::sort(){
    if(head == nullptr){
        return;
    }
    node* curr = head;
    while(curr != nullptr){ 
        node* minNode = curr;
        node* nextNode = curr->next;
        while(nextNode != nullptr){
            if (nextNode->num < minNode->num){
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }
        swap(curr->num, minNode->num);
        curr = curr->next;
    }
}

inline void structure::push_back(int num){
    node * n = new node;
    n->num = num;
    n->next = nullptr;
    n->prev = tail;
    if (head == nullptr){
        head = n;
    }
    if ( tail ==nullptr){
        tail = n;
    }else{
        tail ->next = n;
        tail = n;
    }
    count++;

}

inline void structure::push_front(int num){
    node * n = new node;
    n->num = num;
    n->next = head;
    n->prev = nullptr;
    if (head == nullptr){
        head = n;
        tail = n;  
    }else{
        head->prev = n;
        head = n;
    }
    count++;

}

inline void structure::pop_front(){
    if (head ==  nullptr){
        return;
    }
    node * oldHead = head;
    head = head->next;
    if (head != nullptr){
        head->prev = nullptr;
    }else{
        head = nullptr;
    }
    delete oldHead;
    count --;

}

inline void structure::pop_back(){
    if (head ==  nullptr || tail == nullptr){
        return;
    }
    node * oldTail = tail;
    tail = tail->prev;
    if (tail != nullptr){
        tail->next = nullptr;
    }else{
        tail = nullptr;
    }
    delete oldTail;
    count --;

}


inline void structure::display(){
    if(head == nullptr){
        return;
    }
    node*curr = head;
    do{
        cout << curr->num <<"->";
        curr = curr->next;
    }while (curr != nullptr);
    cout<<"end\n";
}

inline void structure::erase(int index){
    try {
        if(head == nullptr || index > count || index < 0){
            throw 404;
        }
        node * curr = head;
        for(int i = 0; i<index;i++){
            curr = curr->next;
        }
        if (curr == head){
            pop_front();
            return;
        }else if (curr == tail){
            pop_back();
            return;
        }else{
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            count--;
        }
    }catch(...){
        cout << "Index out of bound!\n \n";
    }
}

inline void structure::deleted(){
   try {
        if(head == nullptr){
            throw 404;
        }
        node * curr = head;
        for(int i = count; i>0;i--){
            if (curr != nullptr){
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete head;
                count --;
                head = curr->next;
                curr = curr->next;
            }
        delete head;
        tail = nullptr;
        head = nullptr;
        count = 0;

        }
    }catch(...){
        cout << "Index out of bound!\n \n";
    }
} 

class stack:public structure{};

class queue:public structure{};

class dequeue:public structure{};


#endif