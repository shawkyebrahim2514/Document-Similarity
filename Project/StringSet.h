#ifndef PROJECT_1_STRINGSET_H
#define PROJECT_1_STRINGSET_H
#include <iostream>
#include <set>

class StringSet {
private:
    std::set<std::string> container;
    void split(const std::string& stringWords);
    void consistentString(std::string& word);
    bool isExist(const std::string& word);
    void addString(const std::string& word);
public:
    StringSet()= default;
    StringSet(const std::string& stringWords, bool isFile);
    void clear();
    int size();
    void print();
    double computeSimilarity(StringSet& anotherSet);
    StringSet operator+(const StringSet& anotherSet); // the union of these two sets
    StringSet operator*(const StringSet& anotherSet); // the intersection of these two sets
    StringSet& operator=(const StringSet& anotherSet); // the intersection of these two sets
};

#endif
