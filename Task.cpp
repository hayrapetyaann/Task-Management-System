#include "Task.h"
#include <iostream>

Task::Task(int task_id, int uid, std::string title, std::string description, std::string deadline,
           std::string category, int prio, int status)
    : m_task_id(task_id), m_uid(uid), m_title(title), m_description(description), m_deadline(deadline),
      m_category(category), m_prio(prio), m_status(status) {}

Task::Task(const Task& other)
    : m_task_id(other.m_task_id), m_uid(other.m_uid), m_title(other.m_title), m_description(other.m_description),
      m_deadline(other.m_deadline), m_category(other.m_category), m_prio(other.m_prio), m_status(other.m_status) {}

Task::Task(Task&& other) noexcept
    : m_task_id(std::move(other.m_task_id)), m_uid(std::move(other.m_uid)), m_title(std::move(other.m_title)),
      m_description(std::move(other.m_description)), m_deadline(std::move(other.m_deadline)),
      m_category(std::move(other.m_category)), m_prio(other.m_prio), m_status(other.m_status) {}

Task::~Task() {}

Task& Task::operator=(const Task& other) {
    if (this != &other) {
        m_task_id = other.m_task_id;
        m_uid = other.m_uid;
        m_title = other.m_title;
        m_description = other.m_description;
        m_deadline = other.m_deadline;
        m_category = other.m_category;
        m_prio = other.m_prio;
        m_status = other.m_status;
    }

    return *this;
}

Task& Task::operator=(Task&& other) noexcept {
    if (this != &other) {
        m_task_id = std::move(other.m_task_id);
        m_uid = std::move(other.m_uid);
        m_title = std::move(other.m_title);
        m_description = std::move(other.m_description);
        m_deadline = std::move(other.m_deadline);
        m_category = std::move(other.m_category);
        m_prio = other.m_prio;
        m_status = other.m_status;
    }
    return *this;
}

void Task::edit(const Task& updated_task) {
    m_title = updated_task.m_title;
    m_description = updated_task.m_description;
    m_deadline = updated_task.m_deadline;
    m_category = updated_task.m_category;
    m_prio = updated_task.m_prio;
    m_status = updated_task.m_status;
}

void Task::set_status(Status status) {
    m_status = static_cast<int>(status);
}

void Task::set_prio(Priority prio) {
    m_prio = static_cast<int>(prio);
}

void Task::display_info() const {
    std::cout << "Task ID: " << m_task_id << ", Title: " << m_title << ", Deadline: " << m_deadline
              << ", Category: " << m_category << ", Priority: " << m_prio << ", Status: " << m_status << std::endl;
}

int Task::get_task_id() const {
    return m_task_id;
}

Task& Task::operator++() {
    if (m_status < 2) {
        m_status++;
    }
    return *this;
}

Task Task::operator++(int) {
    Task temp = *this;
    if (m_status < 2) {
        m_status++;
    }
    return temp;
}

Task& Task::operator--() {
    if (m_status > 0) {
        m_status--;
    }
    return *this;
}

Task Task::operator--(int) {
    Task temp = *this;
    if (m_status > 0) {
        m_status--;
    }
    return temp;
}

bool Task::operator==(const Task& other) const {
    return m_task_id == other.m_task_id;
}

bool Task::operator!=(const Task& other) const {
    return m_task_id != other.m_task_id;
}

bool Task::operator<(const Task& other) const {
    return m_deadline < other.m_deadline;
}

bool Task::operator>(const Task& other) const {
    return m_deadline > other.m_deadline;
}

std::ostream& operator<<(std::ostream& os, const Task& task) {
    os << "Task ID: " << task.m_task_id << ", Title: " << task.m_title << ", Deadline: " << task.m_deadline
       << ", Category: " << task.m_category << ", Priority: " << task.m_prio << ", Status: " << task.m_status;
  
    return os;
}

std::istream& operator>>(std::istream& is, Task& task) {
    is >> task.m_task_id;
    std::getline(is, task.m_title);
    std::getline(is, task.m_description);
    std::getline(is, task.m_deadline);
    std::getline(is, task.m_category);
    is >> task.m_prio;
    is >> task.m_status;
    return is;
}
