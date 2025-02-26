#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>

enum class Priority { LOW, MID, HIGH, URGENT };
enum class Status { NOT_STARTED, IN_PROGRESS, COMPLETED };

class Task {
private:
    std::string m_task_id;
    std::string m_uid;
    std::string m_title;
    std::string m_description;
    std::string m_deadline;
    std::string m_category;
    int m_prio;
    int m_status;

public:
    Task(std::string task_id, std::string uid, std::string title, std::string description, std::string deadline,
         std::string category, int prio, int status);
    Task(const Task& other);
    Task(Task&& other) noexcept;
    ~Task();

    Task& operator=(const Task& other);
    Task& operator=(Task&& other) noexcept;

    void edit(const Task& updated_task);
    void set_status(Status status);
    void set_prio(Priority prio);
    void display_info() const;
    std::string get_task_id() const;

    Task& operator++();
    Task operator++(int);
    Task& operator--();
    Task operator--(int);

    bool operator==(const Task& other) const;
    bool operator!=(const Task& other) const;
    bool operator<(const Task& other) const;
    bool operator>(const Task& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Task& task);
    friend std::istream& operator>>(std::istream& is, Task& task);
};

#endif // TASK_H
