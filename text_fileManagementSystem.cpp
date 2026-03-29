#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to check if file exists in vector
bool fileExistsInVector(const vector<string> &files, const string &filename) {
    return find(files.begin(), files.end(), filename) != files.end();
}

// Function to check if file is empty
bool isFileEmpty(const string &filename) {
    ifstream inFile(filename);
    return inFile.peek() == ifstream::traits_type::eof();
}

// Create a new file
void createFile(vector<string> &files) {
    string filename;
    cout << "Enter file name to create: ";
    cin >> filename;

    if (fileExistsInVector(files, filename)) {
        cout << "File already exists in memory!\n";
        return;
    }

    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error creating file!\n";
        return;
    }

    files.push_back(filename);
    cout << "File created successfully.\n";
}

// Write data to a file
void writeFile(const vector<string> &files) {
    string filename;
    cout << "Enter file name to write into: ";
    cin >> filename;

    if (!fileExistsInVector(files, filename)) {
        cout << "File not found!\n";
        return;
    }

    ofstream outFile(filename, ios::app); // append mode
    string data;
    cout << "Enter data to write: ";
    cin.ignore();
    getline(cin, data);
    outFile << data << "\n";
    cout << "Data written successfully.\n";
}

// Read data from a file
void readFile(const vector<string> &files) {
    string filename;
    cout << "Enter file name to read from: ";
    cin >> filename;

    if (!fileExistsInVector(files, filename)) {
        cout << "File not found!\n";
        return;
    }

    if (isFileEmpty(filename)) {
        cout << "File is empty.\n";
        return;
    }

    ifstream inFile(filename);
    string line;
    cout << "File Contents:\n";
    while (getline(inFile, line)) {
        cout << line << "\n";
    }
}

// Copy file contents
void copyFile(const vector<string> &files) {
    string src, dest;
    cout << "Enter source file name: ";
    cin >> src;
    cout << "Enter destination file name: ";
    cin >> dest;

    if (!fileExistsInVector(files, src) || !fileExistsInVector(files, dest)) {
        cout << "Source or destination file not found!\n";
        return;
    }

    ifstream inFile(src);
    ofstream outFile(dest, ios::app);
    string line;
    while (getline(inFile, line)) {
        outFile << line << "\n";
    }
    cout << "File copied successfully.\n";
}

// Delete a file
void deleteFile(vector<string> &files) {
    string filename;
    cout << "Enter file name to delete: ";
    cin >> filename;

    auto it = find(files.begin(), files.end(), filename);
    if (it == files.end()) {
        cout << "File not found!\n";
        return;
    }

    if (remove(filename.c_str()) != 0) {
        cout << "Error deleting file!\n";
    } else {
        files.erase(it);
        cout << "File deleted successfully.\n";
    }
}

// List all files
void listFiles(const vector<string> &files) {
    if (files.empty()) {
        cout << "No files created yet.\n";
        return;
    }
    cout << "Files in memory:\n";
    for (const auto &file : files) {
        cout << "- " << file << "\n";
    }
}

// Delete all files before exit
void cleanupFiles(vector<string> &files) {
    for (const auto &file : files) {
        remove(file.c_str());
    }
    files.clear();
}

int main() {
    vector<string> files;
    int choice;

    while (true) {
        cout << "\n========= File Management System =========\n";
        cout << "1. Create File\n";
        cout << "2. Write to File\n";
        cout << "3. Read from File\n";
        cout << "4. Copy File\n";
        cout << "5. Delete File\n";
        cout << "6. List Files\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createFile(files); break;
            case 2: writeFile(files); break;
            case 3: readFile(files); break;
            case 4: copyFile(files); break;
            case 5: deleteFile(files); break;
            case 6: listFiles(files); break;
            case 7:
                cleanupFiles(files);
                cout << "Exiting... All files deleted from memory.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}