//
// Created by netanel on 5/17/22.
//

//#ifndef EX5_1_CPP_NODE_HPP
//#define EX5_1_CPP_NODE_HPP

#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

namespace ariel {
    class Node {
    public:
        string data;
        Node* next = nullptr;
        vector <Node*> children;
        bool visited = false;

        explicit Node(string  data)
                : data(std::move(data)), next(nullptr){}

//        ~Node() = default;


        string& add_str(std::string &str) {
            std::queue<Node *>node_queue;
            node_queue.push(this);
            while (!node_queue.empty()){
                unsigned size = node_queue.size();
                while (size>0) {
                    Node *tmp=node_queue.front();
                    node_queue.pop();
                    for (Node *child: tmp->children) {
                        node_queue.push(child);
                    }
                    if(size>1) {
                        str += tmp->data + "---";
                    }
                    else{
                        str += tmp->data;
                    }
                    size--;
                }
                str+='\n';
            }
            return str;
        }

    };
}

//#endif //EX5_1_CPP_NODE_HPP
