#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// Global variables for synchronization
mutex countMutex;

// Function for the first thread to count up to 20
void countUp() {
    lock_guard<mutex> countLock(countMutex);
    for (int i = 1; i <= 20; ++i) {
        cout << "Thread 1: " << i << endl;
    }
}

// Function for the second thread to count down from 20 to 0
void countDown() {
    lock_guard<mutex> countLock(countMutex);
    for (int i = 20; i >= 0; --i) {
        cout << "Thread 2: " << i << endl;
    }
}

int main() {
    // Create the two threads
    thread t1(countUp);
    thread t2(countDown);

    // Join the threads with the main thread
    t1.join();
    t2.join();

    return 0;
}
