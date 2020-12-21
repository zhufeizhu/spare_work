#ifndef _DEMO_LIST_HPP_
#define _DEMO_LIST_HPP_

#include <iostream>

namespace demo{

template<typename T> 
class mList_node{
    typedef mList_node* mList_node_pointer;
    public:
        explicit mList_node(const T& data);
        mList_node(const mList_node &node);
        ~mList_node();
        // mList_node_pointer pre;  
        mList_node_pointer next;
        T data;
};

template<typename T> 
class mList{
    public:
        explicit mList();
        mList(const mList &list);
        void emplace_back(const T& data);
        void insert(const T& data, int pos);
        void remove(int pos);
        inline int length(){
            return this->length_;
        }
        T operator[](int pos);
        ~mList();
    private:
        mList_node<T> *head;
        mList_node<T> *tail;
        int length_;
};



}



// template<typename T>
// class mList_iterator{
//     typedef mList_iterator<T> self;
//     typedef mList_node<T>* link_type;

//     link_type ptr;

//     T& operator *(){
//         return ptr->data;
//     }

//     T* operator ->(){
//         return &(operator*());
//     }

//     self& operator++(){
//         ptr = ptr->next;
//         return *this;
//     }

//     self& operator--(){
//         ptr = ptr->pre;
//         return *this;
//     }

//     bool operator==(const mList_iterator& rhs){
//         return ptr == rhs.ptr;
//     }

//     bool operator!=(const mList_iterator& rhs){
//         return !(this==rhs.ptr);
//     }

// };



#endif
