/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;
using std::sort;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
//    ifstream words(filename);
//    string cur;
//    if (words.is_open()){
//        while (getline(words, cur)){
//            string key = cur;
//            sort(key.begin(), key.end());
//            
//            auto lookup = dict.find(key);
//            if (lookup != dict.end()){
//                for (size_t i = 0; i < dict.at(key).size(); i++){
//                    if (dict[key][i] == cur)
//                        return;
//                }
//                dict[key].push_back(cur);
//            }
//            else dict[key].push_back(cur);
//        }
//    }
    ifstream words(filename);
    string word;
    if(words.is_open()){
        while(getline(words, word)){
            string key;
            key = word;
            sort(key.begin(), key.end());
            auto lookup = dict.find(key);
            if(lookup==dict.end()){
                dict[key].push_back(word);
            }
            else{
                for(size_t i = 0; i < dict.at(key).size(); i++){
                    if(dict[key][i] == word){
                        return;
                    }
                }
                dict[key].push_back(word);
            }
        }
    }
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
//    for (auto &cur : words){
//        string key = cur;
//        sort(key.begin(), key.end());
//        
//        auto lookup = dict.find(key);
//        if (lookup != dict.end()){
//            for (size_t i = 0; i < dict.at(key).size(); i++){
//                if (dict[key][i] == cur)
//                    return;
//            }
//        }
//        else dict[key].push_back(cur);
//    }
    for(auto &word: words){
        string key = word;
        sort(key.begin(), key.end());
        auto lookup = dict.find(key);
        if(lookup==dict.end()){
            dict[key].push_back(word);
        }
        else{
            for(size_t i = 0; i < dict.at(key).size(); i++){
                if(dict[key][i] == word){
                    return;
                }
            }
            dict[key].push_back(word);
        }
    }
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
    string key = word;
    sort(key.begin(), key.end());
    auto lookup = dict.find(key);
    if (lookup != dict.end())
        return dict.find(key)->second;
    return vector<string>();
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
    vector<vector<string>> ret;
    for (auto & cur : dict){
        if (cur.second.size() > 1)
            ret.push_back(cur.second);
    }
    return ret;
}
