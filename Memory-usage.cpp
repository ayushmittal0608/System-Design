#include <bits/stdc++.h>
using namespace std;

class MemoryUsage {
    public:
        long MemTotal, MemFree, MemAvailable, Buffers, Cached, SwapTotal, SwapFree, SwapCached;
        long Active, Inactive, Dirty, Writeback, Shmem, Slab; 
        double MemUsagePercent, SwapUsagePercent;
};

int main(){
    ifstream file("/proc/meminfo");
    string line;
    MemoryUsage mem = {0};
    while(getline(file, line)){
        istringstream ss(line);
        string key, unit;
        long value;
        ss>>key>>value>>unit;
        if (key == "MemTotal:") mem.MemTotal = value;
        else if (key == "MemFree:") mem.MemFree = value;
        else if (key == "MemAvailable:") mem.MemAvailable = value;
        else if (key == "Buffers:") mem.Buffers = value;
        else if (key == "Cached:") mem.Cached = value;
        else if (key == "SwapTotal:") mem.SwapTotal = value;
        else if (key == "SwapFree:") mem.SwapFree = value;
        else if (key == "SwapCached:") mem.SwapCached = value;
        else if (key == "Active:") mem.Active = value;
        else if (key == "Inactive:") mem.Inactive = value;
        else if (key == "Dirty:") mem.Dirty = value;
        else if (key == "Writeback:") mem.Writeback = value;
        else if (key == "Shmem:") mem.Shmem = value;
        else if (key == "Slab:") mem.Slab = value;
    }
    mem.MemUsagePercent = (double)(mem.MemTotal - mem.MemAvailable) / mem.MemTotal * 100.0;
    if(mem.SwapTotal != 0){
        mem.SwapUsagePercent = (double)(mem.SwapTotal - mem.SwapFree) / mem.SwapTotal * 100.0;
    }
    else{
        mem.SwapUsagePercent = 0.0;
    }
    cout << "MemTotal: " << mem.MemTotal << " kB" << endl;
    cout << "MemFree: " << mem.MemFree << " kB" << endl;
    cout << "MemAvailable: " << mem.MemAvailable << " kB" << endl;
    cout << "Buffers: " << mem.Buffers << " kB" << endl;
    cout << "Cached: " << mem.Cached << " kB" << endl;
    cout << "Active: " << mem.Active << " kB" << endl;
    cout << "Inactive: " << mem.Inactive << " kB" << endl;
    cout << "Dirty: " << mem.Dirty << " kB" << endl;
    cout << "Writeback: " << mem.Writeback << " kB" << endl;
    cout << "Shmem: " << mem.Shmem << " kB" << endl;
    cout << "Slab: " << mem.Slab << " kB" << endl;
    cout << "SwapTotal: " << mem.SwapTotal << " kB" << endl;
    cout << "SwapFree: " << mem.SwapFree << " kB" << endl;
    cout << "SwapCached: " << mem.SwapCached << " kB" << endl;

    cout << fixed << setprecision(2);
    cout << "Memory Usage %: " << mem.MemUsagePercent << "%" << endl;
    cout << "Swap Usage %: " << mem.SwapUsagePercent << "%" << endl;
    cout<<endl;
}