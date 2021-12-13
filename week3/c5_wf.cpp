#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <map>

// convert a word to lower case
std::vector <std::string> line_to_word(std::string line); 
std::string tokenize(std::string word); 


// read a text file and calculate words frequency 

int main() {
    std::map <std::string, int> words_frequency; 
    std::ifstream myfile("shakespeare.txt");   
    std::string line;
    int line_num = 0; 
    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            if (line_num <= 20) {
                std::vector <std::string> words = line_to_word(line);

                for (auto & elem: words) {
                    std::string temp = tokenize(elem); 
                    if (!words_frequency.count(temp)) {
                        words_frequency.insert(std::pair<std::string, int>(temp, 1));
                    } else {
                        words_frequency[temp] ++; 
                    }

                }
                
            }
            line_num += 1;
        }
        myfile.close();
        for (auto i: words_frequency) {
                    std::cout << '{' << i.first << ": " << i.second << '}' <<std::endl; 
                } 
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