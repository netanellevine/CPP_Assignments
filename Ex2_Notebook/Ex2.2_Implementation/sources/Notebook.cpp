#include "Notebook.hpp"
#include <algorithm>
#include <vector>

using namespace ariel;





void Notebook::check_before_write(int page_num, int row_num, int col_num, Direction dir, const string & str){
    string desired_row = this->read(page_num, row_num, col_num, dir,  str.length());
    for (unsigned int i = 0; i < desired_row.length(); ++i) {
        if(desired_row.at(i)  != '_'){
            throw invalid_argument ("Can't rewrite on existing ink!");
        }
    }
}

void Notebook::writeHorizontal(unsigned int page_num, unsigned int row_num, unsigned int col_num, const string & str) {
    if(str.length() > 'd' - col_num){
        throw invalid_argument("The Row's Max length is 100, typing failed!");
    }
    // Case 1: new page -> new row
    if(this->notebook.find(unsigned(page_num)) == this->notebook.end()){ // page number doesn't exist.
        Page p; // New page
        Row r; // New row
        for (unsigned int i = 0; i < str.length(); ++i) {
            r.row[unsigned(col_num) + i] = char(str.at(i));
        }
        p.page[unsigned(row_num)] = r;
        this->notebook[unsigned(page_num)] = p;
    }
    // Case 2: page exists but new row is needed
    else if(this->notebook.find(unsigned(page_num))->second.page.find(unsigned(row_num)) == this->notebook.find(unsigned(page_num))->second.page.end()){
        Row r; // New row
        for (unsigned int i = 0; i < str.length(); ++i) {
            r.row[unsigned(col_num) + i] = char(str.at(i));
        }
        this->notebook.find(unsigned(page_num))->second.page[unsigned(row_num)] = r;
    }
    // Case 3: page and row exists
    else{
        Row r = this->notebook.find(unsigned(page_num))->second.page.find(unsigned(row_num))->second;
        for (unsigned int i = 0; i < str.length(); ++i) {
            r.row[unsigned(col_num) + i] = char(str.at(i));
        }
        this->notebook.find(unsigned(page_num))->second.page[unsigned(row_num)] = r;
    }
}

void Notebook::writeVertical(unsigned int page_num, unsigned int row_num, unsigned int col_num, const string & str) {
    // Case 1: new page -> new rows
    if(this->notebook.find(unsigned(page_num)) == this->notebook.end()) { // page number doesn't exist.
        Page p; // New page
        for (unsigned int i = 0; i < str.length(); ++i) {
            Row r; // New row
            r.row[unsigned(col_num)] = char(str.at(i));
            p.page[unsigned(row_num) + i] = r; // New row for each char in the @col_num position.
        }
        this->notebook[unsigned(page_num)] = p;
    }
    // Case 2: page exists but new row is needed for every char of the string -> possible that later on the row is existed already.
    else {
        Page p = this->notebook.find(unsigned(page_num))->second;
        for (unsigned int i = 0; i < str.length(); ++i) {
            if(p.page.find(unsigned(row_num) + i)  == p.page.end()){ // Row doesn't exist
                Row r; // New row
                r.row[unsigned(col_num)] = char(str.at(i));
                p.page[unsigned(row_num) + i] = r;
            }
            else{ //Row does exist.
                Row r = p.page.find(unsigned(row_num) + i)->second;
                r.row[unsigned(col_num)] = char(str.at(i));
                p.page[unsigned(row_num) + i] = r;
            }
        }
        this->notebook[unsigned(page_num)] = p;
    }
}

void Notebook::write(int page, int row, int column, Direction dir, const string & str){
    if (page < 0 || row < 0 || column < 0){
        throw invalid_argument {"Page/Row/Column must be a non-negative Integer number!"};
    }
    if (str.length() > 'd' && dir == Direction::Horizontal){
        throw invalid_argument {"Writing Horizontally is possible only when the String length is less then 100 characters!"};
    }
    if (column > 'c'){
        throw invalid_argument {"Invalid argument, max column is 99!"};
    }
    for (unsigned int i = 0; i < str.length(); ++i) {
        if(str.at(i) >= '~' || str.at(i) < '!'){
            if (str.at(i) != ' ') {
                throw invalid_argument{"This string contains illegal characters!"};
            }
        }
    }
    this->check_before_write(page, row, column, dir, str);
    if(dir == Direction::Horizontal){
        this->writeHorizontal(unsigned(page), unsigned(row), unsigned(column), str);
    }
    else{ // direction is Vertical
        this->writeVertical(unsigned(page), unsigned(row), unsigned(column), str);
    }
}

string Notebook::readHorizontal(unsigned int page_num, unsigned int row_num, unsigned int col_num, int length) {
    if(length > 'd' - col_num){
        throw invalid_argument("The Row's Max length is 100, reading failed!");
    }
    string output;
    // Case 1: page does not exist
    if(this->notebook.find(page_num) == this->notebook.end()){
        for (unsigned int i = 0; i < length; ++i) {
            output += '_';
        }
    }
    // Case 2: row does not exist.
    else if(this->notebook.find(page_num)->second.page.find(row_num) == this->notebook.find(page_num)->second.page.end()){
        for (unsigned int i = 0; i < length; ++i) {
            output += '_';
        }
    }
    // Case 3: row and page do exists.
    else{
        Row r = this->notebook.find(page_num)->second.page.find(row_num)->second;
        for (unsigned int i = unsigned(col_num); i < col_num + unsigned(length); ++i) {
            if(r.row.find(i) == r.row.end()){ // This row doesn't contain a char at the @col_num index.
                output += '_';
            }
            else{ // This row does contain a char at the @col_num index.
                output += r.row.find(i)->second;
            }
        }
    }
    return output;
}

string Notebook::readVertical(unsigned int page_num, unsigned int row_num, unsigned int col_num, int length) {
    string output;
    // Case 1: page does not exist
    if (this->notebook.find(page_num) == this->notebook.end()) {
        for (unsigned int i = 0; i < length; ++i) {
            output += '_';
        }
    }
    // Case 2: row and page do exists -> at least the first row
    else {
        for (unsigned int i = row_num; i < row_num + unsigned(length); ++i) {
            if (this->notebook.find(page_num)->second.page.find(i) == this->notebook.find(page_num)->second.page.end()) {
                // Row doesn't exist.
                output += '_';
            }
            else { // Row does exist.
                Row r = this->notebook.find(page_num)->second.page.find(i)->second;
                if (r.row.find(col_num) == r.row.end()) { // Check if this row contains a char in the @col_num index.
                    output += '_';
                }
                else{
                    output += char(r.row.find(col_num)->second);
                }
            }
        }
    }
    return output;
}

string Notebook::read(int page, int row, int column, Direction dir, int length){
    if (page < 0 || row < 0 || column < 0 || length < 0){
        throw invalid_argument {"Page/Row/Column/Length must be a non-negative Integer number!"};
    }
    if (column > 'c'){
        throw invalid_argument {"The range of the columns is between 0-99"};
    }
    if (length > 'd' && dir == Direction::Horizontal){
        throw invalid_argument {"You can read each time only one ROW!"};
    }
    if (length == 0){
        return "";
    }
    string output;
    if(dir == Direction::Horizontal){
        output = this->readHorizontal(unsigned(page), unsigned(row), unsigned(column), length);
    }
    else{
        output = this->readVertical(unsigned(page), unsigned(row), unsigned(column), length);
    }
    return output;
}

void Notebook::eraseHorizontal(unsigned int page_num, unsigned int row_num, unsigned int col_num, int length) {
    if(length > 'd' - col_num){
        throw invalid_argument("The Row's Max length is 100, erasing failed!");
    }
    // Case 1: new page -> new row
    if(this->notebook.find(page_num) == this->notebook.end()){ // page number doesn't exist.
        Page p; // New page
        Row r; // New row
        for (unsigned int i = 0; i < length; ++i) {
            r.row[unsigned(col_num) + i] = '~';
        }
        p.page[unsigned(row_num)] = r;
        this->notebook[unsigned(page_num)] = p;
    }
    // Case 2: page exists but new row is needed
    else if(this->notebook.find(page_num)->second.page.find(row_num) == this->notebook.find(page_num)->second.page.end()){
        Row r; // New row
        for (unsigned int i = 0; i < length; ++i) {
            r.row[unsigned(col_num) + i] = '~';
        }
        this->notebook.find(page_num)->second.page[unsigned(row_num)] = r;
    }
    // Case 3: page and row exists
    else{

        Row r = this->notebook.find(page_num)->second.page.find(row_num)->second;
        for (unsigned int i = 0; i < length; ++i) {
            r.row[unsigned(col_num) + i] = '~';
        }
        this->notebook.find(page_num)->second.page[unsigned(row_num)] = r;
    }
}

void Notebook::eraseVertical(unsigned int page_num, unsigned int row_num, unsigned int col_num, int length) {
    // Case 1: new page -> new rows
    if(this->notebook.find(page_num) == this->notebook.end()) { // page number doesn't exist.
        Page p; // New page
        for (unsigned int i = 0; i < length; ++i) {
            Row r; // New row
            r.row[unsigned(col_num)] = '~';
            p.page[unsigned(row_num) + i] = r; // New row for each char in the @col_num position.
        }
        this->notebook[unsigned(page_num)] = p;
    }
    // Case 2: page exist but new row is needed for every char of the string
    else {
        Page p = this->notebook.find(page_num)->second;
        for (unsigned int i = 0; i < length; ++i) {
            if(p.page.find(unsigned(row_num) + i)  == p.page.end()){ // Row doesn't exist
                Row r; // New row
                r.row[unsigned(col_num)] = '~';
                p.page[unsigned(row_num) + i] = r;
            }
            else{ //Row does exist.
                Row r = p.page.find(unsigned(row_num) + i)->second;
                r.row[unsigned(col_num)] = '~';
                p.page[unsigned(row_num)+ i] = r;
            }
        }
        this->notebook[unsigned(page_num)] = p;
    }
}

void Notebook::erase(int page, int row, int column, Direction dir, int length){
    if (page < 0 || row < 0 || column < 0 || length < 0){
        throw invalid_argument {"Page/Row/Column/Length must be a non-negative Integer number!"};
    }
    if (column > 'c'){
        throw invalid_argument {"The range of the columns is between 0-99"};
    }
    if (length > 'd' && dir == Direction::Horizontal){
        throw invalid_argument {"You can erase each time only one ROW!"};
    }
    if(dir == Direction::Horizontal){
        this->eraseHorizontal(unsigned(page), unsigned(row), unsigned(column), length);
    }
    else{
        this->eraseVertical(unsigned(page), unsigned(row), unsigned(column), length);
    }
}

void Notebook::show(int page){
    if (page < 0){
        throw invalid_argument {"Page must be a non-negative Integer number!"};
    }
    string empty_row = "____________________________________________________________________________________________________";
    if(this->notebook.find(unsigned (page)) == this->notebook.end()){
        for (int i = 0; i < ('z' - 'a'); ++i) {
            cout << empty_row << endl;
        }
    }
    else{
        Page p = this->notebook.find(unsigned (page))->second;
        vector <unsigned int> curr_page;
        curr_page.reserve(p.page.size());
        for (const auto & pair : p.page) {
            curr_page.push_back(pair.first);
        }
        sort(curr_page.begin(), curr_page.end());
        for (unsigned int i = 0; i < curr_page.size(); i++) {
            cout << this->read(page, int(curr_page[i]), 0,Direction::Horizontal, 'd') << endl;
        }
    }
}


