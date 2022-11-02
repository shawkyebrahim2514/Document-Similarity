#ifndef PROJECT_1_APPLICATION_H
#define PROJECT_1_APPLICATION_H
#include "StringSet.h"
#include <vector>

class Application {
private:
    std::vector<StringSet> documents;
    void showWindow();
public:
    void run();
    void print(const std::string& paragraph);
    void loadFromFile();
    void loadFromString();
    void printDocument();
    void clearDocument();
    void printUnionDocuments();
    void printIntersectDocuments();
    void calculateSimilarity();
};

#endif
