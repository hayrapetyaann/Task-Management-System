#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>

enum class Priority { LOW, MID, HIGH, URGENT };
enum class Status { NOT_STARTED, IN_PROGRESS, COMPLETED };

class Task {
private:
    int m_task_id;
    int m_uid;
    std::string m_title;
    std::string m_description;
    std::string m_deadline;
    std::string m_category;
    Priority m_prio;
    Status m_status;

public:
    Task(int task_id, int uid, std::string title, std::string description, std::string deadline,
         std::string category, Priority prio, Status status);
    Task(const Task& other);
    Task(Task&& other) noexcept;
    ~Task();

    Task& operator=(const Task& other);
    Task& operator=(Task&& other) noexcept;

    void edit(const Task& updated_task);
    void set_status(Status status);
    void set_prio(Priority prio);
    void display_info() const;
    int get_task_id() const;

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
