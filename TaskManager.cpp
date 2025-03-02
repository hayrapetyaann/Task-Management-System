#include "TaskManager.h"
#include <iostream>
#include <algorithm>

TaskManager::TaskManager() {}

TaskManager::~TaskManager() {
    for (auto user : m_users) {
        delete user;
    }
    for (auto task : m_all_tasks) {
        delete task;
    }
}

void TaskManager::register_user(User* user) {
    m_users.push_back(user);
}

User* TaskManager::login(const std::string& username, const std::string& password) {
    for (auto user : m_users) {
        if (user->get_name() == username && user->login(password)) {
            return user;
        }
    }
    return nullptr;
}

void TaskManager::logout(User* user) {
    user->logout();
}

void TaskManager::add_task(Task* task) {
    m_all_tasks.push_back(task);
}

void TaskManager::delete_task(const int task_id) {
    for (auto it = m_all_tasks.begin(); it != m_all_tasks.end();) {
        if ((*it)->get_task_id() == task_id) {
            delete *it;  
            it = m_all_tasks.erase(it); 
        } else {
            ++it;  
        }
    }
}

void TaskManager::edit_task(const int task_id, const Task& updated_task) {
    for (auto task : m_all_tasks) {
        if (task->get_task_id() == task_id) {
            *task = updated_task;
            break;
        }
    }
}

void TaskManager::display_task(const int task_id) const {
    for (auto task : m_all_tasks) {
        if (task->get_task_id() == task_id) {
            std::cout << *task << std::endl;
            break;
        }
    }
}

void TaskManager::list_tasks() const {
    for (auto task : m_all_tasks) {
        std::cout << *task << std::endl;
    }
}
