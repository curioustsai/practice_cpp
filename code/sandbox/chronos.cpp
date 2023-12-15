#include <chrono>
#include <iostream>
#include <thread>

int main (int argc, char *argv[]) {
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
    std::cout << "hello world" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds> (t2 - t1).count() << "us.";

    return 0;
}
