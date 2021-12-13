#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <map>
#include <algorithm>


std::vector <std::string> line_to_word(std::string line); 
std::string tokenize(std::string word); 
void print_top_ten(std::map <std::string, int> words_frequency, int frequency); 


// read a text file and calculate words frequency 

int main() {
    // create an empty map (dict)
    std::map <std::string, int> words_frequency; 
    // read the text file 
    std::ifstream myfile("shakespeare.txt");   
    std::string line;
    int line_num = 0; 
    if (myfile.is_open()) {
        // stream each line 
        while (std::getline(myfile, line)) {
            // convert a string into an vector of words 
            std::vector <std::string> words = line_to_word(line);
            // tokenize words and calculate  the frequency 
            for (auto & elem: words) {
                std::string temp = tokenize(elem); 
                if (!words_frequency.count(temp)) {
                    words_frequency.insert(std::pair<std::string, int>(temp, 1));
                } else {
                    words_frequency[temp] ++; 
                }
            }
                
        }
        myfile.close();
        
        // print the top 10 freqency words 
        print_top_ten(words_frequency, 10); 

    } else {
        std::cout << "Unable to open the file" << std::endl; 
    }

    return 0; 
}


// reference: https://emrecankuran.medium.com/ways-to-split-a-string-in-c-e5e0334a35d
// use string find method 
std::vector <std::string> line_to_word(std::string line) {
    /*
    extract words from a string
    */ 
   std::vector <std::string> words_list; 
   std::string delimiter = " ";  
   size_t found = line.find(delimiter); 
   while (found != std::string::npos) {
       // extract word
       std::string token = line.substr(0, found); 
       if (token.find_first_not_of(" ") != std::string::npos) {
           words_list.push_back(token);
       }
       line = line.substr(found+delimiter.length(), line.length()-1);
       found = line.find(delimiter);
    }

    words_list.push_back(line); 

    return words_list;
}


std::string tokenize(std::string word) {
    /*
    convert capital alphabet to lower case
    delete ',', '''
    */
   std::string token_word; 
   for (char &elem : word) {
       if (isalpha(elem)) {
           token_word.push_back(tolower(elem)); 
       }

   }

   return token_word; 
}


// sort map based on values
// https://www.educative.io/edpresso/how-to-sort-a-map-by-value-in-cpp

bool sort_by_value(std::pair<std::string, int> &a,
                   std::pair<std::string, int> &b){
                       
                       return (a.second > b.second); 
}


void print_top_ten(std::map <std::string, int> words_frequency, int frequency) {
    std::vector<std::pair<std::string, int>> words_vec;  // create an empty vector
    // copy key-value pairs from the map to the vector
    for (auto elem : words_frequency) {
        words_vec.push_back(std::make_pair(elem.first, elem.second)); 
    }

    // sort the vector
    std::sort(words_vec.begin(), words_vec.end(), sort_by_value);

    for (int i=0; i<frequency; i++) {
        std::cout << words_vec[i].first << " : " << words_vec[i].second << std::endl; 
    }
}