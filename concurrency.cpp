#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <fstream>
#include <string>

const int NUM_PRODUCER_THREADS = 32;
const int NUM_CONSUMER_THREADS = 8;

std::queue<std::string> q;
std::mutex m;
std::condition_variable cv;
bool done = false;
std::mutex print_m;

void producer(int id)
{
    std::ifstream file("file" + std::to_string(id) + ".txt");
    std::string line;
    while (std::getline(file, line)) {
        std::unique_lock<std::mutex> lock(m);
        q.push(line);
        lock.unlock();
        cv.notify_one();
    }
    file.close();

    std::unique_lock<std::mutex> lock(m);
    done = true;
    lock.unlock();
    cv.notify_all();
}

void consumer()
{
    while (true) {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, []{return !q.empty() || done;});
        if (q.empty() && done) {
            break;
        }
        std::string line = q.front();
        q.pop();
        lock.unlock();

        // Process the data read from disk
        // ...

        std::unique_lock<std::mutex> print_lock(print_m);
        std::cout << "Processed line: " << line << std::endl;
    }
}

int main()
{
    std::thread producers[NUM_PRODUCER_THREADS];
    std::thread consumers[NUM_CONSUMER_THREADS];

    for (int i = 0; i < NUM_PRODUCER_THREADS; i++) {
        producers[i] = std::thread(producer, i);
    }
    for (int i = 0; i < NUM_CONSUMER_THREADS; i++) {
        consumers[i] = std::thread(consumer);
    }

    for (int i = 0; i < NUM_PRODUCER_THREADS; i++) {
        producers[i].join();
    }
    for (int i = 0; i < NUM_CONSUMER_THREADS; i++) {
        consumers[i].join();
    }

    return 0;
}
