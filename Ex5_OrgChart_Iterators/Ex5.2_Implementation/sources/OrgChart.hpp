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
        Node* root;
        Node* curr_node;
        Iterator* begin_ptr;
        vector<Node*> nodes;

        OrgChart();
        OrgChart( OrgChart&& o) = default;
        OrgChart( OrgChart &tree) = default;

        [[maybe_unused]] OrgChart(const OrgChart &tree);
        ~OrgChart();

        OrgChart& operator= ( const OrgChart & ) = default;
        OrgChart& operator= (  OrgChart && ) = default;

        OrgChart& add_root(const string &new_root);
        OrgChart& add_sub(const string& manager, const string& worker);

        friend ostream &operator<< (ostream& output, const OrgChart& tree);

        Iterator begin_level_order();
        Iterator end_level_order() const;
        Iterator begin_reverse_order();
        Iterator reverse_order() const;
        Iterator begin_preorder();
        Iterator end_preorder() const;
        Iterator begin();
        Iterator end() const;

        Node* find_node(const string& curr);
        void resetFlags();
        static void checkName(string const & name);
        void checkRootEmpty() const;

        void runBFS();
        void runBFSReversed();
        void runDFS();


    };
}

#endif //EX5_1_CPP_ORGCHART_HPP
