#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <C_Nchronise.hpp> 

const int end = 1000;
const int numThreads = 4;
std::vector<int> array(end, 0); 

std::mutex arl;

void CounterThread(){
    for(int i = 0; i < end; i++){
        for(int j = 0; j < i; j++){
            C_Nchronise::synchronize(arl, [&]() {
                array[i]++;
            });
        }
    }
}

void CheckArray(){
    int errors = 0;
    std::cout << "Checking..." << std::endl;

    for(int i = 0; i < end; i++){
        if(array[i] != numThreads * i){
            errors++;
            std::cout << i << " : " << array[i] << "  Should be  " << numThreads * i << std::endl;
        }
    }

    std::cout << "Errors: " << errors << std::endl;
}

int main(){
    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; i++) {
        threads.push_back(std::thread(CounterThread));
    }

    for (int i = 0; i < numThreads; i++) {
        if (threads[i].joinable()) {
            threads[i].join();
        }
    }

    CheckArray();
    return 0;
}