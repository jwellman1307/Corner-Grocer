//July Wellman
//CS-210 Programming Languages
// April 16, 2023

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class Grocer {
private:
    map<string, int> itemFrequency; // to store the frequency of each item
    string inputFileName = "CS210_Project_Three_Input_File.txt";
    string outputFileName = "frequency.dat";

public:
    Grocer() {
        readInputFile();
        writeOutputFile();
    }

    void readInputFile() {
        ifstream inputFile(inputFileName);
        string item;
        int frequency;
        while (inputFile >> item >> frequency) {
            itemFrequency[item] = frequency;
        }
        inputFile.close();
    }

    void writeOutputFile() {
        ofstream outputFile(outputFileName);
        for (auto item : itemFrequency) {
            outputFile << item.first << " " << item.second << endl;
        }
        outputFile.close();
    }

    void searchItem() {
        string item;
        cout << "Enter the item you wish to look for: ";
        cin >> item;
        if (itemFrequency.count(item)) {
            cout << "Frequency of " << item << " is " << itemFrequency[item] << endl;
        }
        else {
            cout << "Item not found" << endl;
        }
    }

    void printList() {
        cout << "Item Frequency List:" << endl;
        for (auto item : itemFrequency) {
            cout << item.first << " " << item.second << endl;
        }
    }

    void printHistogram() {
        cout << "Item Frequency Histogram:" << endl;
        for (auto item : itemFrequency) {
            cout << item.first << " ";
            for (int i = 0; i < item.second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main() {
    Grocer grocer;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Search for an item\n";
        cout << "2. Print item frequency list\n";
        cout << "3. Print item frequency histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            grocer.searchItem();
            break;
        case 2:
            grocer.printList();
            break;
        case 3:
            grocer.printHistogram();
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}