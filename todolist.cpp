#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// --- Function Prototypes ---
void displayMenu();
void addTask(vector<string>& tasks);
void viewTasks(const vector<string>& tasks);
void removeTask(vector<string>& tasks);

// --- Main Function ---
int main() {
    vector<string> tasks;
    int choice = 0;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "\nInvalid input. Please enter a number.\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                removeTask(tasks);
                break;
            case 4:
                cout << "\nThank you for using the To-Do List Manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "\nInvalid choice. Please select a valid option (1-4).\n" << endl;
                break;
        }
    }

    return 0;
}

// --- Function Definitions ---

/**
 * @brief Displays the menu options.
 */
void displayMenu() {
    cout << "\n--- To-Do List Manager ---\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Remove Task\n";
    cout << "4. Quit\n";
    cout << "--------------------------\n";
}

/**
 * @brief Adds a task to the list.
 * @param tasks Reference to the task vector.
 */
void addTask(vector<string>& tasks) {
    string newTask;
    cout << "\nEnter the task to add: ";
    getline(cin, newTask);
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

/**
 * @brief Displays all tasks.
 * @param tasks Constant reference to the task vector.
 */
void viewTasks(const vector<string>& tasks) {
    cout << "\n--- Your Tasks ---\n";
    if (tasks.empty()) {
        cout << "Your to-do list is empty.\n";
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
    cout << "------------------\n";
}

/**
 * @brief Removes a task by its number.
 * @param tasks Reference to the task vector.
 */
void removeTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "\nYour to-do list is already empty. Nothing to remove.\n";
        return;
    }

    viewTasks(tasks);

    int taskNumber = 0;
    cout << "\nEnter the number of the task to remove: ";
    cin >> taskNumber;

    if (cin.fail()) {
        cout << "\nInvalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + (taskNumber - 1));
        cout << "Task " << taskNumber << " removed successfully!\n";
    } else {
        cout << "Invalid task number. No task was removed.\n";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
