#include <fstream>
#include "Application.h"

void Application::run() {
    showWindow();
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    while (choice < 1 || choice > 6){
        std::cout << "Enter a correct choice: ";
        std::cin >> choice;
    }
    switch (choice) {
        case 1:
            loadFromFile();
            break;
        case 2:
            loadFromString();
            break;
        case 3:
            printDocument();
            break;
        case 4:
            printUnionDocuments();
            break;
        case 5:
            printIntersectDocuments();
            break;
        case 6:
            calculateSimilarity();
            break;
    }
    std::string state;
    print("Do you want to do more operations?");
    std::cout << "Enter your choice:";
    std::cin >> state;
    if(state == "y" || state == "yes") run();
}

void Application::showWindow() {
    print("What do you want to do?");
    std::cout << "1- Load a document from file\n";
    std::cout << "2- Load a paragraph to the document\n";
    std::cout << "3- Print a document words\n";
    std::cout << "4- Print the words of union of two documents\n";
    std::cout << "5- Print the words of intersection of documents\n";
    std::cout << "6- Calculate the similarity of two documents\n";
}

void Application::loadFromFile() {
    std::string fileName;
    std::fstream file;
    std::cout << "Enter the file name: ";
    std::cin >> fileName;
    file.open(fileName + ".txt");
    while (!file){
        print("This file doesn't exist!");
        std::cout << "Enter an existing file name: ";
        std::cin >> fileName;
        file.open(fileName + ".txt");
    }
    file.close();
    StringSet newDocument(fileName, true);
    this->documents.push_back(newDocument);
    print("Successfully uploaded document number (" + std::to_string(this->documents.size()) + ")");
}

void Application::loadFromString() {
    std::string paragraph;
    std::cout << "Enter the your paragraph: ";
    std::cin.sync();
    std::getline(std::cin, paragraph);
    StringSet newDocument(paragraph, false);
    this->documents.push_back(newDocument);
    print("Successfully uploaded document number (" + std::to_string(this->documents.size()) + ")");
}

void Application::printDocument() {
    if(documents.empty()){
        print(" There aren't any documents until now! ");
        return;
    }
    print("You have (" + std::to_string(this->documents.size()) + ") documents");

    int choice;
    std::cout << "Enter the number of document to print from: ";
    std::cin >> choice;
    while (choice < 1 || choice > this->documents.size()){
        std::cout << "Enter the correct document number: ";
        std::cin >> choice;
    }

    print("The document's words");
    this->documents[choice-1].print();
}

void Application::printUnionDocuments() {
    if(documents.empty()){
        print("There aren't any documents until now!");
        return;
    }

    print("You have (" + std::to_string(this->documents.size()) + ") documents ");
    int document1, document2;

    std::cout << "Enter the first number of document: ";
    std::cin.sync();
    std::cin >> document1;
    while (document1 < 1 || document1 > this->documents.size()){
        std::cout << "Enter a correct document number: ";
        std::cin >> document1;
    }

    std::cout << "Enter the second number of document: ";
    std::cin >> document2;
    while (document2 < 1 || document2 > this->documents.size()){
        std::cout << "Enter a correct document number: ";
        std::cin >> document2;
    }

    StringSet newDocument = this->documents[document1-1] + this->documents[document2-1];
    print("The union of the two documents' words");
    newDocument.print();

    print("Do you want to store this document?");
    std::cout << "Enter your choice: ";
    std::string choice;
    std::cin >> choice;
    if(choice == "y" || choice == "yes"){
        this->documents.push_back(newDocument);
    }else return;
    print("Successfully stored the union documents number (" + std::to_string(this->documents.size()) + ")");
}

void Application::printIntersectDocuments() {
    if(documents.empty()){
        print(" There aren't any documents until now! ");
        return;
    }

    print(" You have " + std::to_string(this->documents.size()) + " documents ");
    int document1, document2;

    std::cout << "Enter the first number of document: ";
    std::cin >> document1;
    while (document1 < 1 || document1 > this->documents.size()){
        std::cout << "Enter the correct document number: ";
        std::cin >> document1;
    }

    std::cout << "Enter the second number of document: ";
    std::cin >> document2;
    while (document2 < 1 || document2 > this->documents.size()){
        std::cout << "Enter the correct document number: ";
        std::cin >> document2;
    }

    StringSet newDocument = this->documents[document1-1] * this->documents[document2-1];
    print(" The intersection of the two documents' words ");
    newDocument.print();

    print("Do you want to store this document?");
    std::cout << "Enter your choice: ";
    std::string choice;
    std::cin >> choice;
    if(choice == "y" || choice == "yes"){
        this->documents.push_back(newDocument);
    }else return;
    print("Successfully stored the intersection documents number (" + std::to_string(this->documents.size()) + ")");
}

void Application::calculateSimilarity() {
    if(documents.empty()){
        print("There aren't any documents until now!");
        return;
    }

    print("You have (" + std::to_string(this->documents.size()) + ") documents");
    int document1, document2;

    std::cout << "Enter the first number of document: ";
    std::cin >> document1;
    while (document1 < 1 || document1 > this->documents.size()){
        std::cout << "Enter a correct document number: ";
        std::cin >> document1;
    }

    std::cout << "Enter the second number of document: ";
    std::cin >> document2;
    while (document2 < 1 || document2 > this->documents.size()){
        std::cout << "Enter a correct document number: ";
        std::cin >> document2;
    }

    double similarity = this->documents[document1-1].computeSimilarity(this->documents[document2-1]);
    print("The similarity of the two documents is (" + std::to_string(similarity) + ")");
}

void Application::print(const std::string& paragraph) {
    int width = 200;
    int part = width/2 - paragraph.size()/2;
    std::cout << std::string(part,'-') << ' ' << paragraph << ' ' << std::string(part,'-') << '\n';
}
