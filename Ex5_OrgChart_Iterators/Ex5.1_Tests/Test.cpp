#include "doctest.h"
#include "sources/OrgChart.hpp"
using namespace ariel;
TEST_CASE("add root & sub"){
    OrgChart org;
            CHECK_THROWS(org.add_sub("Netanel", "Mor"));  // can't add sub if there is no root
            CHECK_NOTHROW(org.add_root("Netanel"));
            CHECK_NOTHROW(org.add_sub("Netanel", "Mor"));

            CHECK_THROWS(org.add_sub("Chen", "")); // string checks
            CHECK_THROWS(org.add_sub("Chen", " "));
            CHECK_THROWS(org.add_sub("Chen", "\r"));
            CHECK_THROWS(org.add_sub("Chen", "\t"));
            CHECK_THROWS(org.add_sub("Chen", "\n"));

            CHECK_EQ(org.root->data, "Netanel");
            CHECK_NOTHROW(org.add_root("Michael")); // replace the root from "Netanel" to "Michael"

            CHECK_NE(org.root->data, "Netanel");

            CHECK_NOTHROW(org.add_sub("Michael", "A"));
            CHECK_NOTHROW(org.add_sub("Michael", "B"));
            CHECK_NOTHROW(org.add_sub("A", "AA"));
            CHECK_NOTHROW(org.add_sub("B", "BB"));
            CHECK_THROWS(org.add_sub("C", "D"));
}
TEST_CASE("Operator Check"){
    OrgChart org;
            CHECK_THROWS_MESSAGE(org.add_sub("tal", "renana"), "can't add sub before root");
            CHECK_NOTHROW(org.add_root("dana"));
            CHECK_NOTHROW(org.add_root("shir"));
            CHECK_NOTHROW(org.add_sub("shir", "tal"));
            CHECK_THROWS_MESSAGE(org.add_sub("adi", "sapir"), "employer doesn't exist");
            CHECK_NOTHROW(org.add_sub("shir", "sapir"));
            CHECK_NOTHROW(org.add_sub("sapir", "dan"));
            CHECK_NOTHROW(org.add_sub("dan", "ziv"));
            CHECK_NOTHROW(org.add_sub("tal", "avi"));
            CHECK_NOTHROW(org.add_sub("tal", "yossi"));
            CHECK_NOTHROW(org.add_sub("shir", "ido"));
            CHECK_NOTHROW(org.add_sub("ziv", "shaked"));
            CHECK_NOTHROW(org.add_sub("ziv", "ofer"));
    std::vector<std::string> v = {"shir", "tal", "sapir", "ido", "avi", "yossi", "dan", "ziv", "shaked", "ofer"};
    size_t i = 0;
    for(auto it = org.begin_level_order(); it != org.end_level_order(); ++it){
                CHECK_EQ(*it, v.at(i++));
    }
    std::vector<std::string> v2 = {"shaked", "ofer", "ziv", "avi", "yossi", "dan", "tal", "sapir", "ido", "shir"};
    i = 0;
    for(auto it = org.begin_reverse_order(); it != org.reverse_order(); ++it){
                CHECK_EQ(*it, v2.at(i++));
    }
    std::vector<std::string> v3 = {"shir", "tal", "avi", "yossi", "sapir", "dan", "ziv", "shaked", "ofer", "ido"};
    i = 0;
    for(auto it = org.begin_preorder(); it != org.end_preorder(); ++it){
                CHECK_EQ(*it, v3.at(i++));
    }
}