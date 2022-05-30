//
// Created by netanel on 5/17/22.
//

#ifndef EX5_1_CPP_NODE_HPP
#define EX5_1_CPP_NODE_HPP

#pragma once
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

namespace ariel {
    class Node {
    public:
        string data;
        Node* next;
        vector <Node*> children;

        Node(string  data, Node* father)
            : data(std::move(data)), next(father), children(vector<Node*>()){}

         explicit Node(string  data)
                : data(std::move(data)), next(nullptr), children(vector<Node*>()){}

        ~Node() {
            delete next;
//            while (!this->children.empty()) {
//                delete this->children.pop_back();
//            }
        }

        void addNode(const string& val){
            Node* new_node = new Node(val);
            this->next = new_node;
            this->children.push_back(new_node);
        }

    };
}





//namespace ariel {
//    template <typename T> struct Node {
//        T data;
//        vector <Node*> children;
//        Node* father;
//
//        Node(T& data, Node* father)
//                : data(data), father(father), children(vector<Node*>()){}
//
//        explicit Node(T& data)
//                : data(data), father(nullptr), children(vector<Node*>()){}
//    };
//}

#endif //EX5_1_CPP_NODE_HPP
