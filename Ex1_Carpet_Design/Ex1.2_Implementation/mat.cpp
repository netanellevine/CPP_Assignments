#include "mat.hpp"

using namespace std;


namespace ariel{
    /**
 * This function purpose is to return a designed carpet according to a constant pattern.
 * It receives number of column, number of row, and two chars.
 * The function returns a string that will represent the carpet.
 * The size of the carpet will be [@row X @col] and it will contains mixture of the 2 chars @c1 and @c2 that received.
 */
    std::string mat(int row, int col, char c1, char c2){
        if (row % 2 == 0 || col % 2 == 0){ // The size parameters can be only Odd numbers.
            throw std::invalid_argument{"The Matrix should hold only odd parameters."};
        }
        if (row <= 0 || col <= 0){ // The size parameters can be only Positive numbers.
            throw std::invalid_argument{"The Matrix should hold only positive parameters."};
        }

        std::string up; // Top part of the carpet
        std::string down; // Bottom part of the carpet + the middle row
        int half = col / 2 + 1;
        for (int i = 0; i < half; i++){ // Because it's palindrome we'll iterate till the half
            string mid;
            int j = row;
            while (j > i * 2){ // This part will fill the middle char through all the line
                if (i % 2 == 0) {mid += c1;} // If @i is even then the middle char is @c1
                else {mid += c2;} // If he is not then the middle char is @c2
                j--;
            }
            while (j >= 2){ // Now we will fill the remaining for that line -> the char will switch every iteration.
                std::string c3;
                if (j % 4 == 0) {c3 = c2 + mid + c2;}
                else {c3 =  c1 + mid + c1;}
                mid = c3;
                j -= 2;
            }
            if (j == 1) {mid += c1;} // The middle row single char (if exists).
            if (i == row / 2){  // Only if @col is bigger then @row
                for (int j = i; j < half - 1; j++){ // Same with the other half
                    up += mid + '\n';
                    std::string c3 = mid + '\n';
                    c3 += down;
                    down = c3;
                }
                up += mid + '\n';
                break;
            }
            if (i == half - 1) {up += mid + '\n';}
            else{ // @up and @down are the same, and @down gets the middle row
                up += mid + '\n';
                std::string c3 = mid + '\n';
                c3 += down;
                down = c3;
            }
        }
        std::string ans = up + down; // @ans is both up and down.
        return ans;
    }
}
