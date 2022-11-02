#include <valarray>
#include <sstream>
#include <fstream>
#include "StringSet.h"

StringSet::StringSet(const std::string &stringWords, bool isFile) {
    if(isFile){
        std::fstream file(stringWords + ".txt", std::ios::in);
        std::string line;
        while (!file.eof()){
            std::getline(file, line);
            split(line);
        }
        file.close();
    }else{
        split(stringWords);
    }
}

void StringSet::addString(const std::string &word) {
    this->container.insert(word);
}

void StringSet::clear() {
    this->container.clear();
}

int StringSet::size() {
    return this->container.size();
}

void StringSet::print() {
    for(auto& word : this->container){
        std::cout << word << '\n';
    }
}

StringSet StringSet::operator+(const StringSet &anotherSet) {
    StringSet result = *this;
    for(auto& word : anotherSet.container){
        result.addString(word);
    }
    return result;
}

StringSet& StringSet::operator=(const StringSet &anotherSet) {
    for(auto& word : anotherSet.container){
        this->addString(word);
    }
    return *this;
}

StringSet StringSet::operator*(const StringSet &anotherSet) {
    StringSet result;
    for(auto& word : anotherSet.container){
        if(this->isExist(word)) result.addString(word);
    }
    return result;
}

bool StringSet::isExist(const std::string &word) {
    return this->container.count(word);
}

double StringSet::computeSimilarity(StringSet &anotherSet) {
    return ((*this) * anotherSet).size() / (std::sqrt(this->size() * anotherSet.size()));
}

void StringSet::split(const std::string &stringWords) {
    std::istringstream allStringWords(stringWords);
    std::string word;
    while (allStringWords >> word){
        consistentString(word);
        this->addString(word);
    }
}

void StringSet::consistentString(std::string &word) {
    int start = 0, len = word.size(), end = len - 1;
    while (!isalpha(word[start]) && start < end){
        len --;
        start ++;
    }
    while (!isalpha(word[end]) && start < end){
        len --;
        end --;
    }
    word = word.substr(start, len);
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
}
