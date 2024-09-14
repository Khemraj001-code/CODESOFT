#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> tasks;  
    vector<bool> status;       
    int choice;                      
    string task;                
    int taskNumber;                  

    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add a task\n";
        cout << "2. View tasks\n";
        cout << "3. Mark task as completed\n";
        cout << "4. Remove a task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); 
                cout << "Enter the task: ";
                getline(cin, task);  
                tasks.push_back(task);          
                status.push_back(false);     
                cout << "Task added!\n";
                break;

            case 2:
                if (tasks.empty()) {
                    std::cout << "No tasks available.\n";
                } else {
                    cout << "\nYour To-Do List:\n";
                    for (size_t i = 0; i < tasks.size(); ++i) {
                        cout << i + 1 << ". " << tasks[i] 
                                  << " [" << (status[i] ? "Completed" : "Pending") << "]\n";
                    }
                }
                break;

            case 3:
                cout << "Enter the task number to mark as completed: ";
                cin >> taskNumber;
                if (taskNumber > 0 && taskNumber <= tasks.size()) {
                    status[taskNumber - 1] = true; 
                    cout << "Task marked as completed!\n";
                } else {
                    cout << "Invalid task number!\n";
                }
                break;

            case 4:
                cout << "Enter the task number to remove: ";
                cin >> taskNumber;
                if (taskNumber > 0 && taskNumber <= tasks.size()) {
                    tasks.erase(tasks.begin() + taskNumber - 1);  
                    status.erase(status.begin() + taskNumber - 1);  
                    cout << "Task removed!\n";
                } else {
                    cout << "Invalid task number!\n";
                }
                break;

            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 5.\n";
                break;
        }

    } while (choice != 5);  // Repeat until user exits

    return 0;
}

