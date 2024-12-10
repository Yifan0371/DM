// Timer.h
#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>
#include <iostream>

class Timer {
public:
    Timer(const std::string& name = "Timer") : m_name(name) {}

    void start() {
        m_start = std::chrono::high_resolution_clock::now();
    }

    void stop() {
        m_end = std::chrono::high_resolution_clock::now();
    }

    void print() const {
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start).count();
        std::cout << m_name << " elapsed: " << duration << " ms" << std::endl;
    }

private:
    std::string m_name;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start, m_end;
};

#endif // TIMER_H
