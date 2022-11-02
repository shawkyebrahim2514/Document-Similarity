#ifndef PROJECT_1_STRINGSET_H
#define PROJECT_1_STRINGSET_H
#include <iostream>
#include <set>

class StringSet {
private:
    std::set<std::string> container;
public:
    StringSet()= default;
    StringSet(const std::string& stringWords, bool isFile);
    void split(const std::string& stringWords);
    void addString(const std::string& word);
    void removeString(const std::string& word);
    void clear();
    void consistentString(std::string& word);
    bool isExist(const std::string& word);
    int size();
    void print();
    StringSet operator+(const StringSet& anotherSet); // the union of these two sets
    StringSet operator*(const StringSet& anotherSet); // the intersection of these two sets
    StringSet& operator=(const StringSet& anotherSet); // the intersection of these two sets
    double computeSimilarity(StringSet& anotherSet);

};


#endif
