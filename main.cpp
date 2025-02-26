#include "TaskManager.h"
#include "User.h"
#include "Task.h"
#include <iostream>

int main() {
    TaskManager manager;

    User* user1 = new User("user1", "JohnDoe", "password123");
    manager.register_user(user1);

    Task* task1 = new Task("TASK_001", "user1", "Finish homework", "Complete the assignment", "2025-03-01", "Study", 2, 0);
    manager.add_task(task1);

    if (manager.login("user1", "password123")) {
        std::cout << "Logged in successfully." << std::endl;
        user1->list_tasks();
    }

    manager.logout(user1);

    return 0;
}
