#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

using BytePtr = char*;

BytePtr allocateMem(size_t memSize)
{
    return new (nothrow) char[memSize];
}

void fillMem(BytePtr memBlock, size_t memSize)
{
    srand(static_cast<unsigned>(time(nullptr)));
    for (size_t i = 0; i < memSize; ++i) {
        memBlock[i] = static_cast<char>(rand() % 256);
    }
}

void readMem(const BytePtr memBlock, size_t memSize)
{
    for (size_t i = 0; i < memSize; ++i) {
        char value = memBlock[i];
    }
}

void stressCPU(int cpuCompute)
{
    while (cpuCompute > 0) {
        volatile int result = 0;
        for (int i = 0; i < 1000000; ++i) {
            result += rand();
        }
        --cpuCompute;
    }
}

int stressMem(int cpuCompute) {
    cout << "Memory Stress Test Program" << endl;
    cout << "\nThis program will stress your RAM and bus interfaces with an intense workload." << endl;

    while (true) {
        size_t memSizeMB;
        cout << "\nEnter the amount of memory to allocate (in megabytes, 0 to exit): ";
        cin >> memSizeMB;

        if (memSizeMB == 0) {
            break;
        }

        const size_t memSizeBytes = memSizeMB * 1048576;

        BytePtr memBlock = allocateMem(memSizeBytes);

        if (!memBlock) {
            cerr << "Memory allocation failed." << endl;
            continue;
        }

        cout << "Allocating and testing " << memSizeMB << " MB of memory..." << endl;

        thread memThread(fillMem, memBlock, memSizeBytes);
        thread cpuThread(stressCPU, cpuCompute);

        memThread.join();
        cpuThread.join();

        readMem(memBlock, memSizeBytes);

        delete[] memBlock;
    }

    return 0;
}

int main() {
    int cpuCompute = 10000000;
    return stressMem(cpuCompute);
}
