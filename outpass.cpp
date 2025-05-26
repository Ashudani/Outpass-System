#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Function to save a new entry
void saveToFile(string name, string room, string reason, string timeOut) {
    ofstream file("outpass_records.txt", ios::app); 
    file << name << "," << room << "," << reason << "," << timeOut << ",Outside\n";
    file.close();
}

// Function to mark a student as "Returned"
void markAsReturned(string name) {
    ifstream file("outpass_records.txt", ios::in);
    vector<string> lines;
    string line;
    
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> tokens;
        string word;
        
        while (getline(ss, word, ',')) {
            tokens.push_back(word);
        }

        // If the student's name matches and status is "Outside", change it to "Returned"
        if (!tokens.empty() && tokens[0] == name && tokens[4] == "Outside") {
            tokens[4] = "Returned";  
        }

        string updatedLine = tokens[0] + "," + tokens[1] + "," + tokens[2] + "," + tokens[3] + "," + tokens[4];
        lines.push_back(updatedLine);
    }
    file.close();

    // Write the updated data back to the file
    ofstream outFile("outpass_records.txt");
    for (const string &updatedLine : lines) {
        outFile << updatedLine << "\n";
    }
    outFile.close();
}

// Function to show students currently outside
void showOutsideStudents() {
    ifstream file("outpass_records.txt");
    string line;
    bool found = false;

    cout << "\n📌 Students Currently Outside:\n";
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> tokens;
        string word;

        while (getline(ss, word, ',')) {
            tokens.push_back(word);
        }

        if (!tokens.empty() && tokens[4] == "Outside") {
            cout << "🔹 " << tokens[0] << " (Room: " << tokens[1] << ", Time Out: " << tokens[3] << ")\n";
            found = true;
        }
    }
    file.close();

    if (!found) {
        cout << "✅ No students are outside.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n🏨 Hostel Outpass System";
        cout << "\n1️⃣ Register Outpass";
        cout << "\n2️⃣ Mark as Returned";
        cout << "\n3️⃣ View Students Outside";
        cout << "\n0️⃣ Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name, room, reason, timeOut;
            cout << "Enter Your Name: ";
            getline(cin, name);
            cout << "Enter Your Room Number: ";
            cin >> room;
            cin.ignore();
            cout << "Enter Reason for Leaving: ";
            getline(cin, reason);
            cout << "Enter Time Out (HH:MM format): ";
            cin >> timeOut;

            saveToFile(name, room, reason, timeOut);
            cout << "✅ Data Saved Successfully!\n";
        }
        else if (choice == 2) {
            string name;
            cout << "Enter Your Name to Mark as Returned: ";
            getline(cin, name);

            markAsReturned(name);
            cout << "✅ Status Updated Successfully!\n";
        }
        else if (choice == 3) {
            showOutsideStudents();
        }
    } while (choice != 0);

    cout << "👋 Exiting... Have a nice day!\n";
    return 0;
}
