#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include "User.h"
#include "Task.h"

class TaskManager {
private:
    std::vector<User*> m_users;
    std::vector<Task*> m_all_tasks;

public:
    TaskManager();
    ~TaskManager();

    void register_user(User* user);
    User* login(const std::string& username, const std::string& password);
    void logout(User* user);

    void add_task(Task* task);
    void delete_task(const std::string& task_id);
    void edit_task(const std::string& task_id, const Task& updated_task);
    void display_task(const std::string& task_id) const;
    void list_tasks() const;
};

#endif // TASK_MANAGER_H
