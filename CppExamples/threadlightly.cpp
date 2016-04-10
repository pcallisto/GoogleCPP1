//#include <string>
#include <iostream>
#include <thread>
using std::thread;
#include <vector>
using std::vector;
#include <stdio.h>

struct ThreadItem {
    char* result; // could've used stringstream too, but don't like their syntax
    thread worker;
};

void* ThreadFunction(char** result) {
    *result = new char[256];
    char buff[132];
    std::vector<std::string> s;
    for (int i = 0; i < 400; ++i)
    {
        sprintf_s(buff, "This is not a very long string: %d ", i);
        s.push_back(buff);
    }
    //    snprintf(*result,256,"Hello World from thread ID %ud", std::this_thread::get_id());
    return 0;
}

int threadlightly() {
    // Get the amount of "processing units"
    int n = std::thread::hardware_concurrency();

    // Create array of threads
    vector<ThreadItem> threadlist;
    threadlist.resize(n);

    // Spawn a thread for each core
    for (int i = 0; i < n; i++)
    {
        threadlist[i].worker = thread(ThreadFunction, &threadlist[i].result); // pass rand() as data argument
    }

    // Wait for them all to finish
    for (int i = 0; i < n; i++)
    {
        threadlist[i].worker.join();
    }

    // Present their calculation results
    printf("Results:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", threadlist[i].result);
    }

    return 1;
}