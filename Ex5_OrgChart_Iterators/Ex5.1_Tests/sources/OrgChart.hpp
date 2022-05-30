//
// Created by Netanel Levine on 10/05/2022.
//

#ifndef EX5_1_CPP_ORGCHART_HPP
#define EX5_1_CPP_ORGCHART_HPP

#pragma once
#include <vector>
#include "iostream"
#include "Node.hpp"
#include "Iterator.hpp"
using namespace std;

namespace ariel {
    class OrgChart {
    public:
        Node* root{};
        Node* curr_node{};
        Iterator* begin_ptr{};
        Iterator* end_ptr{};
        vector<Node*> nodes;

        OrgChart();
        ~OrgChart()= default;
        OrgChart& add_root(const string &new_root);
        OrgChart& add_sub(const string& manager, const string& worker);
        friend ostream & operator<< (ostream& output, const OrgChart& orgChart);
        Iterator& begin_level_order();
        Iterator& end_level_order();
        Iterator& begin_reverse_order();
        Iterator& end_reverse_order();
        Iterator& begin_preorder();
        Iterator& end_preorder();
        Iterator& begin();
        Iterator& end();
        Node* find_node(const string& curr);
    };
}

#endif //EX5_1_CPP_ORGCHART_HPP
