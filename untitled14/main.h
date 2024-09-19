#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
#include <list>

class Task {
  public:
    Task(const std::string &description) : m_description(description), m_completed(false) {
    }

    void complete() {
        m_completed = true;
    }

    const std::string &getDescription() const {
        return m_description;
    }

    bool isCompleted() const {
        return m_completed;
    }

  private:
    std::string m_description;
    bool        m_completed;
};


class ToDoList {
public:
    void addTask(const std::string &description) {
        tasks.push_back(Task(description));
        std::cout << "Task added: " << description << std::endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
            return;
        }
        for (const auto &task : tasks) {
            std::cout << "-";
            if (task.isCompleted()) {
                printf("[x] ");
            } else {
                printf("[ ] ");
            }
            printf("%s\n", task.getDescription().c_str());
        }
    }

    void removeTask(const std::string &description) {
        for (auto it = tasks.begin(); it != tasks.end();) {
            if (it->getDescription() == description)
                it = tasks.erase(it);
            else
                it++;
        }
    }

    void completeTask(const std::string &description) {
        for (auto &task : tasks) {
            if (task.getDescription() == description) {
                task.complete();
                break;
            }
        }
    }

private:
    std::list<Task> tasks;
};

#endif  // TASK_H