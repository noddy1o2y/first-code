#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// ==========================================
// 1. THE TASK CLASS (Phase 1)
// ==========================================
class Task {
public:
    int taskID;
    string title;
    string status; // "To-Do", "In-Progress", "Done"

    // Constructor to easily create a new task
    Task(int id, string t) {
        taskID = id;
        title = t;
        status = "To-Do"; // New tasks start at "To-Do" by default
    }

    // Function to display task details
    void displayTask() {
        cout << "[" << taskID << "] " << title << " | Status: " << status << endl;
    }
};

// ==========================================
// 2. THE BOARD CLASS (Phase 1)
// ==========================================
class Board {
private:
    vector<Task> tasks; // Holds all the tasks
    int nextID = 1;     // Automatically assigns IDs to tasks

public:
    // Function to add a task to the board
    void addTask(string title) {
        Task newTask(nextID, title);
        tasks.push_back(newTask);
        nextID++;
        cout << "✔️ Task added successfully!\n";
    }

    // Function to view all tasks on the board
    void viewBoard() {
        if (tasks.empty()) {
            cout << "--- The board is currently empty. ---\n";
            return;
        }
        cout << "\n--- CURRENT BOARD STATUS ---\n";
        for (int i = 0; i < tasks.size(); i++) {
            tasks[i].displayTask();
        }
        cout << "----------------------------\n";
    }

    // Function to update a task's status
    void updateTask(int id, string newStatus) {
        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i].taskID == id) {
                tasks[i].status = newStatus;
                cout << "✔️ Task " << id << " updated to " << newStatus << "!\n";
                return;
            }
        }
        cout << "❌ Task ID not found.\n";
    }
};

// ==========================================
// MAIN FUNCTION (The Menu-Driven Program)
// ==========================================
int main() {
    Board sharedBoard; // Our shared project workspace
    
    // Simulating a mini User Map for Login (Phase 2)
    map<string, string> userDatabase;
    userDatabase["admin"] = "1234"; // Username: admin, Password: 1234
    userDatabase["student"] = "pass";

    string username, password;
    cout << "=== WELCOME TO THE COLLABORATIVE WORKSPACE ===\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    // Login Validation
    if (userDatabase.find(username) != userDatabase.end() && userDatabase[username] == password) {
        cout << "\n🔓 Login Successful! Welcome, " << username << ".\n";
        
        int choice;
        do {
            cout << "\n--- WORKSPACE MENU ---\n";
            cout << "1. Add a New Task\n";
            cout << "2. View All Tasks\n";
            cout << "3. Update a Task Status\n";
            cout << "4. Logout & Exit\n";
            cout << "Enter your choice (1-4): ";
            cin >> choice;

            if (choice == 1) {
                string taskTitle;
                cout << "Enter task description: ";
                cin.ignore(); // Clears the input buffer
                getline(cin, taskTitle); // Allows spaces in sentences
                sharedBoard.addTask(taskTitle);
            } 
            else if (choice == 2) {
                sharedBoard.viewBoard();
            } 
            else if (choice == 3) {
                int id;
                string newStatus;
                cout << "Enter Task ID to update: ";
                cin >> id;
                cout << "Enter new status (To-Do / In-Progress / Done): ";
                cin >> newStatus;
                sharedBoard.updateTask(id, newStatus);
            }
            else if (choice == 4) {
                cout << "Logging out. Goodbye!\n";
            }
            else {
                cout << "❌ Invalid choice. Try again.\n";
            }

        } while (choice != 4);

    } else {
        cout << "❌ Invalid Username or Password. Access Denied.\n";
    }

    return 0;
}
