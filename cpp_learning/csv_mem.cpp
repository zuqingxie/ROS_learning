#include <unistd.h>
#include <ios>
#include <iostream>
#include <fstream>
#include <string>
#include <sys/syscall.h>
#include <sys/types.h>
//////////////////////////////////////////////////////////////////////////////
//
// process_mem_usage(double &, double &) - takes two doubles by reference,
// attempts to read the system-dependent data for a process' virtual memory
// size and resident set size, and return the results in KB.
//
// On failure, returns 0.0, 0.0

void process_mem_usage(double& vm_usage, double& resident_set)
{
   using std::ios_base;
   using std::ifstream;
   using std::string;

    //VSZ is the Virtual Memory Size. It includes all memory that the process can access, including memory that is swapped out, memory that is allocated, but not used, and memory that is from shared libraries.
    //虚拟内存空间大只能表示程序运行过程中可访问的空间比较大，不代表物理内存空间占用也大

    //RSS is the Resident Set Size and is used to show how much memory is allocated to that process and is in RAM. It does not include memory that is swapped out. It does include memory from shared libraries as long as the pages from those libraries are actually in memory. It does include all stack and heap memory.
    //驻留内存，顾名思义是指那些被映射到进程虚拟内存空间的物理内存
    pid_t pid_;

    pid_ = syscall(SYS_getpid);
    std::cout<<"pid: "<<pid_<<std::endl;
   vm_usage     = 0.0;
   resident_set = 0.0;

   // 'file' stat seems to give the most reliable results
   //
   ifstream stat_stream("/proc/self/stat",ios_base::in);

   // dummy vars for leading entries in stat that we don't care about
   //
   string pid, comm, state, ppid, pgrp, session, tty_nr;
   string tpgid, flags, minflt, cminflt, majflt, cmajflt;
   string utime, stime, cutime, cstime, priority, nice;
   string O, itrealvalue, starttime;

   // the two fields we want
   //
   unsigned long vsize;
   long rss;
    sleep(5);
   stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
               >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
               >> utime >> stime >> cutime >> cstime >> priority >> nice
               >> O >> itrealvalue >> starttime >> vsize >> rss; // don't care about the rest

   stat_stream.close();

   long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages, in this case = 4
   std::cout<<"page_size_kb: "<<page_size_kb;
   vm_usage     = vsize / 1024.0;
   resident_set = rss * page_size_kb;
}

int main()
{
   using std::cout;
   using std::endl;

   double vm, rss;
   process_mem_usage(vm, rss);
   cout << "VM: " << vm <<" kb"<< "; RSS: " << rss <<" kb"<<endl;
}