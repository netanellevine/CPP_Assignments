//
// Created by netanel on 5/17/22.
//

//#ifndef EX5_1_CPP_ITERATOR_HPP
//#define EX5_1_CPP_ITERATOR_HPP
#pragma once
#include "Node.hpp"

namespace ariel{

    class Iterator {
    public:
        Node* node;

//        Iterator() = default;
        Iterator(Node* root)
        {
            this->node = root;
        }

//        ~Iterator()= default;

        string& operator*() const {
            return node->data;}

        string* operator->() const {
            return &(node->data);}

        Iterator& operator++(){
            this->node = this->node->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator copy= *this;
            this->node = this->node->next;
            return copy;
        }

        bool operator==(const Iterator& rhs) const {
            return this->node == rhs.node;
        }

        bool operator!=(const Iterator& rhs) const {
            return !(*this == rhs);
        }
    };
}


//#endif //EX5_1_CPP_ITERATOR_HPP
