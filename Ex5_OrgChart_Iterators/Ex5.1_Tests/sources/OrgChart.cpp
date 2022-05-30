//
// Created by Netanel Levine on 10/05/2022.
//

#include "OrgChart.hpp"
using namespace ariel;

OrgChart::OrgChart(){
    this->root = nullptr;
    this->curr_node = nullptr;
    this->begin_ptr = new Iterator(root);
    this->end_ptr = new Iterator(root);
}

OrgChart &OrgChart::add_root(const string &new_root) {
    if (this->root == nullptr){
        this->root = new Node(new_root);
        this->nodes.push_back(root);
    }
    else{
        this->root->data = new_root;
    }
    return *this;
}

OrgChart &OrgChart::add_sub(const string& manager, const string& worker){
    if (this->root == nullptr){
        throw invalid_argument("Can't add sub before creating a root");
    }
    Node* parent = find_node(manager);
    parent->addNode(worker);
    this->nodes.push_back(parent->next);
    return *this;

}

ostream & ariel::operator<< (ostream& output, const OrgChart& orgChart){return output;}


Iterator &OrgChart::begin_level_order(){
    vector<string>::iterator check;
    return reinterpret_cast<Iterator &>(this->begin_ptr);
}

Iterator &OrgChart::end_level_order(){
    vector<string>::iterator check;
    return reinterpret_cast<Iterator &>(this->begin_ptr);
}

Iterator &OrgChart::begin_reverse_order(){
    vector<string>::iterator check;
    return reinterpret_cast<Iterator &>(this->begin_ptr);
}

Iterator &OrgChart::end_reverse_order(){
    vector<string>::iterator check;
    return reinterpret_cast<Iterator &>(this->begin_ptr);
}

Iterator &OrgChart::begin_preorder(){
    vector<string>::iterator check;
    return reinterpret_cast<Iterator &>(this->begin_ptr);
}

Iterator &OrgChart::end_preorder(){
    vector<string>::iterator check;
    return reinterpret_cast<Iterator &>(this->begin_ptr);
}

Iterator &OrgChart::begin() {
    return reinterpret_cast<Iterator &>(this->begin_ptr);
}

Iterator &OrgChart::end() {
    return reinterpret_cast<Iterator &>(this->begin_ptr);
}

Node *OrgChart::find_node(const string &curr) {
    if (this->root->data == curr){
        return this->root;
    }
    for (Node* node : this->nodes){
        if (node->data == curr){
            return node;
        }
    }
    throw runtime_error("The node does not exist in this OrgChart");
}
