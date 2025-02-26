#include "User.h"
#include <iostream>
#include <algorithm>

User::User(std::string id, std::string name, std::string passwd)
    : m_id(id), m_name(name), m_passwd(passwd), is_logged(false) {}

User::User(const User& other) 
    : m_id(other.m_id), m_name(other.m_name), m_passwd(other.m_passwd), is_logged(other.is_logged) {
    for (auto task : other.m_tasks) {
        m_tasks.push_back(new Task(*task));
    }
}

User::User(User&& other) noexcept
    : m_id(std::move(other.m_id)), m_name(std::move(other.m_name)), m_passwd(std::move(other.m_passwd)),
      m_tasks(std::move(other.m_tasks)), is_logged(other.is_logged) {}

User::~User() {
    for (auto task : m_tasks) {
        delete task;
    }
}

User& User::operator=(const User& other) {
    if (this == &other) return *this;

    m_id = other.m_id;
    m_name = other.m_name;
    m_passwd = other.m_passwd;
    is_logged = other.is_logged;

    for (auto task : m_tasks) {
        delete task;
    }
    m_tasks.clear();
    
    for (auto task : other.m_tasks) {
        m_tasks.push_back(new Task(*task));
    }
    return *this;
}

User& User::operator=(User&& other) noexcept {
    if (this == &other) return *this;

    m_id = std::move(other.m_id);
    m_name = std::move(other.m_name);
    m_passwd = std::move(other.m_passwd);
    m_tasks = std::move(other.m_tasks);
    is_logged = other.is_logged;

    return *this;
}

void User::add_task(Task* task) {
    m_tasks.push_back(task);
}

void User::delete_task(const std::string& task_id) {
    auto it = std::remove_if(m_tasks.begin(), m_tasks.end(), [&](Task* task) {
        return task->get_task_id() == task_id;
    });
    m_tasks.erase(it, m_tasks.end());
}

void User::edit_task(const std::string& task_id, const Task& updated_task) {
    for (auto task : m_tasks) {
        if (task->get_task_id() == task_id) {
            *task = updated_task;
            break;
        }
    }
}

void User::list_tasks() const {
    for (auto task : m_tasks) {
        std::cout << *task << std::endl;
    }
}

Task* User::search_task(const std::string& task_id) {
    for (auto task : m_tasks) {
        if (task->get_task_id() == task_id) {
            return task;
        }
    }
    return nullptr;
}

bool User::login(const std::string& passwd) {
    if (passwd == m_passwd) {
        is_logged = true;
        return true;
    }
    return false;
}

void User::logout() {
    is_logged = false;
}

User::operator bool() const {
    return is_logged;
}

std::string User::get_id() const {
    return m_id;
}

std::string User::get_name() const {
    return m_name;
}
