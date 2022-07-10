#pragma once
#include <iostream>

enum log_type {
    error, info, success,
};

void log(log_type t, std::string message)
{
    switch (t)
    {
        case log_type::error:
            std::cout << "[!ERR!] ";
            break;
        case log_type::info:
            std::cout << "[.INFO.] ";
            break;
        case log_type::success:
            std::cout << "[+SUCCESS+] ";
            break;
        default:
            log(log_type::error, std::string("Invalid logger option: ") + std::to_string(t));
            break;
    }
    std::cout << message << std::endl;
}

template <class T>
void test_expect(T expected, T received, std::string test_name)
{
    if (expected != received)
        log(log_type::error, "-" + test_name + "-" + std::string(" Expected (") + std::to_string(expected) + ") does not match the output (" + std::to_string(received) + ").");
    else
        log(log_type::success, "-" + test_name + "- Passed test.");
}
