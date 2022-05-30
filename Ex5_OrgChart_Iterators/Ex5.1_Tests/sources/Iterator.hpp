//
// Created by netanel on 5/17/22.
//

#ifndef EX5_1_CPP_ITERATOR_HPP
#define EX5_1_CPP_ITERATOR_HPP
#pragma once
#include "Node.hpp"

namespace ariel{

    class Iterator {
    public:
        Node* node;
        int index = 0;

        explicit Iterator(Node* root)
            : node(root){}

        ~Iterator()= default;

        string& operator*() const {return node->data;}

        string* operator->() const {return &node->data;}

        Iterator& operator++(){
            this->node = this->node->next;
            return *this;
        }

        const Iterator operator++(int dummy) {
            Iterator temp= *this;
            this->node = this->node->next;
            return temp;
        }

        bool operator==(const Iterator& rhs) const {
            return this->node == rhs.node;
        }

        bool operator!=(const Iterator& rhs) const {
            return this->node != rhs.node;
        }
    };


    class LevelOrder_it{

    };

    class PreOrder_it{

    };

    class ReverseOrder_it{

    };
}


#endif //EX5_1_CPP_ITERATOR_HPP
