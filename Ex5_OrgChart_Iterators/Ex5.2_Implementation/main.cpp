//
// Created by netanel on 5/30/22.
//
#include <iostream>
#include "sources/OrgChart.cpp"
#include "sources/Node.hpp"


using namespace ariel;
int main() {
    OrgChart org;
    OrgChart org_empty;
    OrgChart org_double_names;
    /* create normal tree */
    org.add_root("adi") ;
    org.add_root("shir") ;
    org.add_sub("shir", "tal") ;
    //   org.add_sub("adi", "sapir"), "employer doesn't exist" ;
    org.add_sub("shir", "sapir") ;
    org.add_sub("sapir", "dan") ;
    org.add_sub("dan", "ziv") ;
    org.add_sub("tal", "avi") ;
    org.add_sub("tal", "yossi") ;
    org.add_sub("shir", "ido") ;
    org.add_sub("ziv", "shaked") ;
    org.add_sub("ziv", "ofer") ;

    /* create tree with 1 name*/
    org_double_names.add_root("adi") ;
    for (size_t i = 0; i < 20; i++)
    {
        org_double_names.add_sub("adi", "adi") ;
    }

    /**************************************************************/

    /*check level order with normal tree*/
    std::vector<std::string> v = {"shir", "tal", "sapir", "ido", "avi", "yossi", "dan", "ziv", "shaked", "ofer"};
    size_t i = 0;
    for(auto it = org.begin_level_order() ; it != org.end_level_order() ; ++it){
        *it;
    }

    /*check level order with empty tree*/
//    org_empty.begin_level_order(), "chart is empty!" ;
//    org_empty.end_level_order(), "chart is empty!" ;

    /*check level order with 1 name tree*/
    for(auto it = org_double_names.begin_level_order() ; it != org_double_names.end_level_order() ; ++it){
        *it ;
    }

    /* check iter size*/
    std::vector<size_t> nums = {4, 3, 5, 3, 3, 5, 3, 3, 6, 4};
    i = 0;
    for(auto it = org.begin_level_order() ; it != org.end_level_order() ; ++it){
        *it;
    }




    /*check reverse level order with normal tree*/
    std::vector<std::string> ve = {"shaked", "ofer", "ziv", "avi", "yossi", "dan", "tal", "sapir", "ido", "shir"};
    size_t ie = 0;
    for(auto it = org.begin_reverse_order() ; it != org.reverse_order() ; ++it){
        *it ;
    }

    /*check reverse level order with empty tree*/
//    org_empty.begin_reverse_order(), "chart is empty!" ;
//    org_empty.reverse_order(), "chart is empty!" ;

    /*check reverse level order with 1 name tree*/
    for(auto it = org_double_names.begin_reverse_order() ; it != org_double_names.reverse_order() ; ++it){
        *it;
    }

    /* check iter size*/
    std::vector<size_t> nums1 = {6, 4, 3, 3, 5, 3, 3, 5, 3, 4};
    i = 0;
    for(auto it = org.begin_reverse_order() ; it != org.reverse_order() ; ++it){
        *it;
    }



    /*check PreOrder with normal tree*/
    std::vector<std::string> ev = {"shir", "tal", "avi", "yossi", "sapir", "dan", "ziv", "shaked", "ofer", "ido"};
    size_t ei = 0;
    for(auto it = org.begin_preorder() ; it != org.end_preorder() ; ++it){
        *it;
    }

    /*check PreOrder with empty tree*/
//    org_empty.begin_preorder() ;
//    org_empty.end_preorder() ;

    /*check PreOrder with 1 name tree*/
    for(auto it = org_double_names.begin_preorder() ; it != org_double_names.end_preorder() ; ++it){
        *it ;
    }
    /* check iter size*/
    std::vector<size_t> gnums = {4, 3, 3, 5, 5, 3, 3, 6, 4, 3};
    i = 0;
    for(auto it = org.begin_preorder() ; it != org.end_preorder(); ++it){
        it->size();
    }



    OrgChart org_special;
    org_special.add_root("boss") ;
    org_special.add_root("boss1") ;
    org_special.add_root("boss2") ;
    org_special.add_root("boss3") ;
    org_special.add_root("boss4") ;
    org_special.add_root("boss5") ;
    org_special.add_root("boss6") ;

    /*check that org size is 1, and root is the last*/
    int iea =0;
    for(auto it = org_special.begin_preorder() ; it != org_special.end_preorder() ; ++it){
        *it;
        i++;
    }















    return 0;
}