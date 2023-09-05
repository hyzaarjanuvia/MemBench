# Memory Load Testing Software

**Description:** This is a program made to simulate a high-intensity, highly saturated memory workload. This is achieved through a perpetual allocation loop that can be turned off through manual intervention by the user. 

**Functionality:**
  - Allocate a user-defined amount of memory to test in megabytes.
  - Fills the memory with randomized data to simulate memory writes and usage.
  - Data is then read and accessed to simulate memory reading.
  - Will go in a continuous loop until the user prompts the program to stop through manual termination. 

**Purposes:**
  - Stress testing of IMC, cache, memory
  - Hardware troubleshooting testing
  - Overclocking stability
  - Educational purposes 

**Dependencies:** This program only utilizes the C++ standard library. 

**Overview:**
1. The operating system is told to allocate a block of memory after user definition of the amount of memory they want tested (in MB).
2. After the memory size is defined, randomized data is then written to the memory and cache bus. By increasing the amount of traffic through the bus interconnect, the likelier the probability of stress and failure. This also ensures that memory is allocated dynamically and promotes proper coverage.
3. After the writing of the data in the memory block, the data is then read from and is then checked for corruption or data loss to determine stability. Errors and corrupted data may result, so use this program wisely.
4. Reading the memory helps to prevent optimization from the compiler and to ensure that the data continuously stresses the system. A user interrupt can be performed via manual intervention by pressing a key, entering 0, or through closing the window. Memory is then deallocated and released to prevent memory leaks. 

**Design Philosophies:** 
  - A single allocation block comprises most of the system memory while this program is running, and is then tested with stressful randomized data patterns.
  - These data patterns can stress the CPU IMC, cache, and memory.
  - Though not particularly stressful, this program relies on the principle that increased use of the bus interfaces increases the probability of inducing failure. 

**Limitations:** 
  - This program may not work on all systems, especially for those still working with x86 instruction sets.
  - May only work on Windows systems
  - Currently does not have the ability to stress the threads involved with memory allocation (in development).
  - Currently does not have the ability to detect complex errors or store events in a log file (in development).
  - Good at stressing the memory at full capacity, but may lack the intensity needed to force errors in some unstable systems. May not be as good as a tool as TM5, HCI Memtest, Karhu, GSAT, or other tests widely used today.
  - Is able to allocate large amounts of memory, but does not have the capability of inducing a particularly stressful load/pattern on the RAM and interfaces. 

**Potential Issues:** 
  - Systems may be made unresponsive in the case of instability.
  - System data and extraneous programs/applications may be corrupted in the case of instability, run this program at your own risk.
  - Some systems may not be capable of running this test due to performance limitations and may come across widespread slowdowns.
