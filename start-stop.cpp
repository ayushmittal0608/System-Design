#include <bits/stdc++.h>
#include <thread>
using namespace std;

struct Server {
    string ip;
    string username;
    string service;
};

void startService(const Server& server){
    string cmd = "ssh " + server.username + "@" + server.ip + " sudo systemctl start "+server.service;
    cout<<"Starting "<<server.service<<" on "<<server.ip<<endl;
    system(cmd.c_str());
}

void stopService(const Server& server){
    string cmd = "ssh " + server.username + "@" + server.ip + " sudo systemctl stop "+server.service;
    cout<<"Stopping "<<server.service<<" on "<<server.ip<<endl;
    system(cmd.c_str());
}

int main(){
    vector<Server> servers = {
        {"192.168.1.101", "user1", "nginx"},
        {"192.168.1.102", "user2", "apache2"},
        {"192.168.1.103", "user3", "mysql"}
    };
    vector<thread> threads;
    for(auto& server: servers){
        threads.push_back(thread(startService, server));
    }
    for(auto& t: threads){
        t.join();
    }
    cout<<"All services started"<<endl;

    threads.clear();
    for(auto& server:servers){
        threads.push_back(thread(stopService, server));
    }
    for(auto& t:threads){
        t.join();
    }
    cout<<"All services stopped"<<endl;
    return 0;
}