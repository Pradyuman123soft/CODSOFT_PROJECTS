#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Task
{
    string Description;
    bool completed;

    Task(const string &desc) : Description(desc), completed(false) {}
};
void addTask(vector<Task> &task, const string &Description)
{
    task.emplace_back(Description);
}
void viewTask(const vector<Task> &task)
{
    if (task.empty())
    {
        cout << "No Task Available!" << endl;
        return;
    }
    for (size_t i = 0; i < task.size(); ++i)
    {
        cout << i + 1 << ". " << task[i].Description << " [" << (task[i].completed ? "Completed" : "Pending") << "]" << endl;
    }
}
void markAsCompleted(vector<Task> &task, size_t index)
{
    if (index < 1 || index > task.size())
    {
        cout << "Invalid Task Number!!!" << endl;
        return;
    }
    else if (task[index - 1].completed)
    {
        cout << "The Task is Already Done!!!" << endl;
        return;
    }
    else
    {
        task[index - 1].completed = true;
    }
}
void removeTask(vector<Task> &task, size_t index)
{
    if (index < 1 || index > task.size())
    {
        cout << "Invalid Input...!!!" << endl;
        return;
    }
    else
    {
        task.erase(task.begin() + index - 1);
    }
}
int main()
{
    vector<Task> tasks;
    int choice;
    string Description;
    size_t taskNumber;
    while (true)
    {
        cout << "TO-Do-List Manager " << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Task" << endl;
        cout << "3. Mark Task As Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit..!" << endl;

        cout << "Enter Your Choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Task Description: " << endl;
            cin.ignore();
            getline(cin, Description);
            addTask(tasks, Description);
            break;
        case 2:
            viewTask(tasks);
            break;
        case 3:
            cout << "Enter the Task Number to Mark Completed: " << endl;
            cin >> taskNumber;
            markAsCompleted(tasks, taskNumber);
            break;
        case 4:
            cout << "Enter Task Number to Remove: " << endl;
            cin >> taskNumber;
            removeTask(tasks, taskNumber);
            break;
        case 5:
            cout << "Exiting.....!!!!" << endl;
            return 0;
        default:
            cout << "You Choose a Invalid Input!!!!" << endl;
            break;
        }
    }
}