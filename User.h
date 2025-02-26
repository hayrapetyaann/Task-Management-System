#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Task.h"

class User {
private:
    std::string m_id;
    std::string m_name;
    std::string m_passwd;
    std::vector<Task*> m_tasks;
    bool is_logged;
public:
    User(std::string id, std::string name, std::string passwd);
    User(const User& other);
    User(User&& other) noexcept;
    ~User();

    User& operator=(const User& other);
    User& operator=(User&& other) noexcept;

    void add_task(Task* task);
    void delete_task(const std::string& task_id);
    void edit_task(const std::string& task_id, const Task& updated_task);
    void list_tasks() const;
    Task* search_task(const std::string& task_id);

    bool login(const std::string& passwd);
    void logout();

    operator bool() const;
    std::string get_id() const;
    std::string get_name() const;
};

#endif // USER_H 
