#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>

using namespace std;

int main()
{
    // Create output stream object to write to CSV file;
    ofstream outfile("cpu_usage.csv");

    // Write header line to CSV file;
    outfile << "CPU Usage (%)\n";

    // Monitor CPU usage in a loop;
    for (int i=0;i<1;i++)
    {
        // Get system CPU usage;
        ifstream stat_file("/proc/stat");
        string line;
        getline(stat_file, line);
        stat_file.close();
        istringstream iss(line);
        string cpu_label;
        iss >> cpu_label;
        long user, nice, system, idle, iowait, irq, softirq;
        iss >> user >> nice >> system >> idle >> iowait >> irq >> softirq;

        long cpu_usage_prev = user+nice+system;
        long cpu_total_prev = cpu_usage_prev+idle+iowait+irq+softirq;
        sleep(1);
        stat_file.open("/proc/stat");
        getline(stat_file, line);
        stat_file.close();
        istringstream iss2(line);
        iss2 >> cpu_label;
        iss2 >> user >> nice >> system >> idle >> iowait >> irq >> softirq;
        long cpu_usage_curr = user+nice+system;
        long cpu_total_curr = cpu_usage_curr+idle+iowait+irq+softirq;

        cout<<cpu_usage_prev<<"  "<<cpu_usage_curr<<"  "<<cpu_total_prev<<"  "<<cpu_total_curr<<endl;
        double cpu_usage = 100*((double)(cpu_usage_curr-cpu_usage_prev)/(double)(cpu_total_curr-cpu_total_prev));

        outfile << cpu_usage<<"\n";






        // Get system RAM usage
        ifstream meminfo_file("/proc/meminfo");
        string mem_line;
        getline(meminfo_file, mem_line);
        string mem_label;
        long mem_total, mem_free, mem_available, buffers, cached;
        istringstream iss3(mem_line);
        iss3 >> mem_label >> mem_total >> mem_label;
        cout<<"mem_label: "<<mem_label<<" mem_free: "<<mem_free<<" mem available: "<<mem_available<<endl;
        getline(meminfo_file, mem_line);
        istringstream iss4(mem_line);
        iss4 >> mem_label >> mem_free >> mem_label;
        getline(meminfo_file, mem_line);
        istringstream iss5(mem_line);
        iss5 >> mem_label >> mem_available >> mem_label;
        getline(meminfo_file, mem_line);
        istringstream iss6(mem_line);
        iss6 >> mem_label >> buffers >> mem_label;
        getline(meminfo_file, mem_line);
        istringstream iss7(mem_line);
        iss7 >> mem_label >> cached >> mem_label;
        meminfo_file.close();
        double ram_usage = (double)(mem_total - mem_available) / (1024.0 * 1024.0);


        // Sleep for a short time to avoid excessive CPU usage;
        sleep(1);

    }
    // Close output stream object;
    outfile.close();

    return 0;
}