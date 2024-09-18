#ifndef TASK_H
#define TASK_H

#include <string>

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

#endif  // TASK_H