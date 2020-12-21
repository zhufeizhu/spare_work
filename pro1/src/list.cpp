#include "list.hpp"

namespace demo{

template<typename T>
mList<T>::mList(){
    this->head = NULL;
    this->tail = NULL;
    this->length_ = 0; 
}

template<typename T>
mList<T>::mList(const mList &list){
    int len = list->length_;
    this->head = NULL;
    this->tail = NULL;
    
    if (len == 0) return;

    mList_node<T> *node = new mList_node<T>(list[0]);

    for(int i = 0; i < len; i++){
        mList_node<T> *tmp = new mList_node<T>(list[i]);
        node->next = tmp;
        node = tmp;
    }
}

template<typename T>
void mList<T>::emplace_back(const T &data){
    mList_node<T> *node = new mList_node<T>(data);
    if (this->length_ == 0 && this->cur == nullptr && this->head == nullptr){
        this->head = node;
        this->tail = node;
    } else {
        this->tail->next = node;
        this->tail = node;
    }
    this->length_++;
}

template<typename T>
void mList<T>::insert(const T &data, int pos){
    if (this->length_ < pos || pos < 0) {
        return;
    } else if(this->length_ == pos){
        emplace_back(data);
        return;
    } else {
        mList_node<T> *node = new mList_node<T>(data);
        if (pos == 0) {
            node->next = head->next;
            head = node;
        } else {
            mList_node<T> *cur = this->head;
            for (int i = 0; i < pos; i++){
                cur = cur->next;
            }
            //此时cur指向的是待插入位置的前一个位置
            node->next = cur->next;
            cur->next = node;
        }
        this->length_++;
    }
}

template<typename T>
void mList<T>::remove(int pos){
    if (pos < 0 || pos >= this->length_){
        return;
    } 

    mList_node<T> *tmp = this->head;
    if (pos == 0){  
        this->head = this->head->next;
        delete tmp;
    } else {
        for (int i = 0; i < pos-1; i++){
            tmp = tmp->next;
        }
        mList_node<T> *node = tmp->next;
        tmp->next = node->next;
        delete node;

        if (pos == this->length_ - 1){
            this->tail = tmp;
        }
    }

}

template<typename T>
T mList<T>::operator[](int pos){
    if( pos > length_){
        return NULL;
    } else {
        mList_node<T> *node = head;
        for(int i = 0; i < pos; i++){
            node = node->next;
        }
        return node->data;
    }
}

template<typename T>
mList_node<T>::mList_node(const T &data){
    this->data = data;
    this->next = nullptr;
}

}
