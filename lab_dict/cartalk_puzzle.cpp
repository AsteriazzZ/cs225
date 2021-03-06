/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of "StringTriples" (a typedef'd std::tuple, see top of
 * cartalk_puzzle.h). Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<StringTriple> cartalk_puzzle(PronounceDict d,
                                    const string& word_list_fname)
{
    /* Your code goes here! */
    
//     ifstream words(word_list_fname);
//     string word;
//     vector<StringTriple> result;
//     if(words.is_open()){
//    	while(getline(words, word)){
//     if(word.length() == 5){
//     string temp1 = word.substr(1, word.length()-1);
//     string temp2 = word.substr(0, 1);
//     string temp3 = word.substr(2, word.length()-2);
//     temp2.append(temp3);
//     if(d.homophones(temp1, temp2)){
//     result.push_back(make_tuple(word, temp1, temp2));
//     }
//     }
//     }
//     }
//     return result;
    vector<StringTriple> ret;
    ifstream words(word_list_fname);
    string word;
    if(words.is_open()){
        while(getline(words, word)){
            if (word.length() > 1){
                string tp1 = word.substr(1);
                string tp2 = word[0] + word.substr(2);
                if (d.homophones(word, tp1) && d.homophones(word, tp2)){
                    StringTriple word_trip = make_tuple(word, tp1, tp2);
                    ret.push_back(word_trip);
                }
            }
        }
    }
    return ret;
}
