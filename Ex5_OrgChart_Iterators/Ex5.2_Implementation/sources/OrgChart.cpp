//
// Created by Netanel Levine on 10/05/2022.
//

#include "OrgChart.hpp"
#include <queue>
#include <stack>
#include <algorithm>

using namespace ariel;

// regular constructor
OrgChart::OrgChart()
{
    this->root = nullptr;
    this->curr_node = nullptr;
    this->begin_ptr = new Iterator(root);
    this->nodes = vector<Node*>();
}

// copy constructor
[[maybe_unused]] OrgChart::OrgChart(const OrgChart &tree)
{
    for (auto *node : tree.nodes)
    {
        this->nodes.push_back(new Node(node->data));
    }
    if(tree.root == nullptr)
    {
        this->root = nullptr;
    }
    else
    {
        this->root = this->nodes[0];
    }
    this->curr_node = nullptr;
    this->begin_ptr = new Iterator(root);
}

// destructor
OrgChart::~OrgChart()
{
    if(this->root != nullptr)
    {
        for (Node *n: this->nodes)
        {
            delete n;
        }
    }
}


OrgChart &OrgChart::add_root(const string &new_root)
{
    checkName(new_root); // check if name is valid
    // check if root is exists.
    if (this->root == nullptr)
    {
        this->root = new Node(new_root);
        this->nodes.push_back(this->root);
    }
    else
    {
        this->root->data = new_root;
    }
    return *this;
}

OrgChart &OrgChart::add_sub(const string& manager, const string& worker)
{
    if (this->root == nullptr)
    {
        throw invalid_argument("Can't add sub before creating a root");
    }
    // check names
    checkName(manager);
    checkName(worker);
    // find paren -> throw exception if you can't  find
    Node* parent = find_node(manager);
    Node* new_node = new Node(worker);
    parent->children.push_back(new_node);
    this->nodes.push_back(new_node);
    return *this;
}

ostream &ariel::operator<< (ostream& output, const OrgChart& tree)
{
    if(tree.root!= nullptr)
    {
        string str;
        // function that creates a string from root
        output << tree.root->add_str(str);
    }
    return output;
}

// this method will create a pointer which is an iterator for traversing the chart in level order.
Iterator OrgChart::begin_level_order()
{
    checkRootEmpty();
    this->runBFS(); // BFS is the way to get the chart organized by levels.
    return *this->begin_ptr;
}

Iterator OrgChart::end_level_order() const
{
    checkRootEmpty();
    return nullptr;
}

Iterator OrgChart::begin_reverse_order()
{
    checkRootEmpty();
    this->runBFSReversed(); // special method to iterate the chart on reversed level order.
    return *this->begin_ptr;
}

Iterator OrgChart::reverse_order() const
{
    checkRootEmpty();
    return nullptr;
}


Iterator OrgChart::begin_preorder()
{
    checkRootEmpty();
    this->runDFS();
    return *this->begin_ptr;
}


Iterator OrgChart::end_preorder() const
{
    checkRootEmpty();
    return nullptr;
}

// this is the same as level order.
Iterator OrgChart::begin()
{
    checkRootEmpty();
    this->runBFS();
    return *this->begin_ptr;
}


Iterator OrgChart::end() const
{
    checkRootEmpty();
    return nullptr;
}

// this method receives a string and checks if this string is in the chart
// if true it returns the Node else throw exception.
Node *OrgChart::find_node(const string &curr)
{
    if (this->root->data == curr)
    {
        return this->root;
    }
    for (Node* node : this->nodes)
    {
        if (node->data == curr)
        {
            return node;
        }
    }
    throw runtime_error("The node does not exist in this OrgChart");
}


void OrgChart::runBFS()
{
    // pointer to begin the iterator.
    this->begin_ptr->node = root;
    // initiate all the visited values to false.
    resetFlags();
    // creating a queue that will hold each level.
    queue<Node *> queueLevel;
    queueLevel.push(this->root);
    this->root->visited = true;
    while (!queueLevel.empty())
    {
        // like in BFS we pop the first element and push all of its children.
        Node *curr_n = queueLevel.front();
        queueLevel.pop();
        if (queueLevel.empty() && curr_n->children.empty())
        {
            // we reached the end so @curr_n next should point to nullptr.
            curr_n->next = nullptr;
        }
        else if (queueLevel.empty())
        {
            // the queue is empty, so we need to move to a new level.
            curr_n->next = curr_n->children[0];
        }
        else
        {
            // queue isn't empty and curr_n has children, so we keep adding.
            curr_n->next = queueLevel.front();
        }
        // now we will go over all @curr_n children (if he has) and update the next accordingly.
        for (auto & i : curr_n->children)
        {
            if (!i->visited)
            {
                i->visited = true;
                queueLevel.push(i);
            }
        }
    }
}


void OrgChart::runBFSReversed()
{
    vector<Node*> reversed;
    // initiate all the visited values to false.
    resetFlags();
    // creating a queue that will hold each level.
    queue<Node *> queueLevel;
    queueLevel.push(this->root);
    this->root->visited = true;
    while(!queueLevel.empty())
    {
        Node* curr_n = queueLevel.front();
        reversed.push_back(curr_n);
        queueLevel.pop();
        // now we will push all the unvisited children.
        for (int i = (int) curr_n->children.size() - 1; i >= 0 ; --i)
        {
            auto ind = unsigned (i);
            if (!curr_n->children[ind]->visited)
            {
                curr_n->children[ind]->visited = true;
                queueLevel.push(curr_n->children[ind]);
            }
        }
    }
    // now we will fix the @reversed vector, so it will be what we desire.
    for (int i = (int) reversed.size() - 1; i >= 0; --i)
    {
        if(i != 0)
        {
            auto ind = unsigned (i);
            reversed[ind]->next = reversed[ind - 1];
        }
        else
        {
            reversed[0]->next = nullptr;
        }
    }
    this->begin_ptr->node = reversed[reversed.size()-1];
}


void OrgChart::runDFS()
{
    // pointer to begin the iterator.
    this->begin_ptr->node = root;
    // initiate all the visited values to false.
    resetFlags();
    // creating a queue that will hold each level.
    stack<Node *> stackLevel;
    stackLevel.push(this->root);
    this->root->visited = true;
    while (!stackLevel.empty())
    {
        // like in DFS we pop the head element and keep heading deeper in the tree
        Node *curr_n = stackLevel.top();
        stackLevel.pop();
        if (stackLevel.empty() && curr_n->children.empty())
        {
            // we reached the end so @curr_n next should point to nullptr.
            curr_n->next = nullptr;
        }
        else if (curr_n->children.empty())
        {
            // @curr_n children is empty so @curr_n will point to the next node in the stack.
            curr_n->next = stackLevel.top();
        }
        else
        {
            // the stack is empty, so we need to move deeper.
            curr_n->next = curr_n->children[0];
        }
        // now we will go over all @curr_n children (if he has) and update the next accordingly.
        for (int i = (int) curr_n->children.size() - 1; i >= 0; --i)
        {
            auto ind = unsigned (i);
            if (!curr_n->children[ind]->visited)
            {
                curr_n->children[ind]->visited = true;
                stackLevel.push(curr_n->children[ind]);
            }
        }
    }
}

// this function will go over all the nodes and reset their visited value to false.
void OrgChart::resetFlags()
{
    for (unsigned int i = 0; i < this->nodes.size() ; ++(i))
    {
        this->nodes[i]->visited = false;
    }
}


void OrgChart::checkName(string const & new_name)
{
    // this function will check if a string is valid for a name if not it will throw exception.
    if (new_name.empty())
    {
        throw invalid_argument("Name can't be empty!");
    }
    bool check_space = true;
    for (char ch : new_name)
    {
        if (ch < '!' || ch > '~')
        {
            if (ch != ' ')
            {
                throw invalid_argument("Name must be an alphabetic name only!");
            }
        }
        else
        {
            check_space = false;
        }
    }
    if (check_space)
    {
        throw invalid_argument("Name must be an alphabetic name only!");
    }
}


void OrgChart::checkRootEmpty() const
{
    if (this->root == nullptr)
    {
        throw runtime_error("The tree is empty, there is nothing to iterate.");
    }
}

