#include <bits/stdc++.h>
using namespace std;

class CPUStats {
    public: 
        string label;
        long user, nice, system, idle;
        long iowait, irq, softirq, steal, guest, guest_nice;
        long total, total_idle;
        double percentage;
};

CPUStats parseCPUStatsLine(const string& line){
    istringstream ss(line);
    CPUStats stats;
    ss >> stats.label >> stats.user >> stats.nice >> stats.system >> stats.idle >> stats.iowait >> stats.irq >> stats.softirq >> stats.steal >> stats.guest >> stats.guest_nice;
    stats.total = stats.user+stats.nice+stats.system+stats.idle+stats.iowait+stats.irq+stats.softirq+stats.steal;
    stats.total_idle = stats.idle+stats.iowait;
    stats.percentage = ((double)(stats.total-stats.total_idle)/stats.total)*100.0;
    return stats;
}

int main(){
    ifstream file("/proc/stat");
    string line;
    vector<CPUStats> cpus;
    while(getline(file, line)){
        if(line.substr(0, 3) == "cpu"){
            cpus.push_back(parseCPUStatsLine(line));
        }
        else{
            break;
        }
    }
    for(auto& cpu: cpus){
        cout<<"Normal Processes: "<<cpu.label<<endl;
        cout<<"Low Priority Tasks: "<<cpu.nice<<endl;
        cout<<"OS Kernel Mode: "<<cpu.system<<endl;
        cout<<"Idle CPU: "<<cpu.idle<<endl;
        cout<<"I/O Operations wait: "<<cpu.iowait<<endl;
        cout<<"Hardware Interrupts: "<<cpu.irq<<endl;
        cout<<"Software Interrupts: "<<cpu.softirq<<endl;
        cout<<"Hypervisor Usage Time: "<<cpu.steal<<endl;
        cout<<"Virtual CPU for guest OS: "<<cpu.guest<<endl;
        cout<<"Low Priority Virtual Processes: "<<cpu.guest_nice<<endl;
        cout<<"Total time: "<<cpu.total<<endl;
        cout<<"Total Idle Time: "<<cpu.total_idle<<endl;
        cout<<"Percentage: "<<cpu.percentage<<endl;
        cout<<endl;
        cout<<endl;
    }
}