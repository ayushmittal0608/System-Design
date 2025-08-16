#include <bits/stdc++.h>
using namespace std;

class RadixNode {
    public:
        bool isEnd = false;
        bool isBlocked = false;
        RadixNode* child[2] = {nullptr, nullptr}; 
};

string ipToBinary(const string& ip){
    stringstream ss(ip);
    string token, binary = "";
    while(getline(ss, token, '.')){
        int num = stoi(token);
        for(int i=7; i>=0; i--){
            binary+=((num >> i) & i) ? '1' : '0';
        }
    }
    return binary;
}

void insert(RadixNode* root, const string& ip, bool blocked){
    string bits = ipToBinary(ip);
    RadixNode* node = root;
    for(char bit: bits){
        int idx = bit - '0';
        if(!node->child[idx]){
            node->child[idx] = new RadixNode();
        }
        node = node->child[idx];
    }
    node->isEnd = true;
    node->isBlocked = blocked;
}

bool isAllowed(RadixNode* root, const string& ip){
    string bits = ipToBinary(ip);
    RadixNode* node = root;
    for(char bit: bits){
        int idx = bit - '0';
        if(!node->child[idx]){
            return true;
        }
        node = node->child[idx];
    }
    return node->isEnd ? node->isBlocked : true;
}

int main(){
    RadixNode* firewall = new RadixNode();
    insert(firewall, "192.168.1.10", true);
    insert(firewall, "10.0.0.5", true);
    insert(firewall, "192.168.1.20", false);

    string testIPs;
    cout<<"Enter your testIP: "; 
    cin>>testIPs;
    cout<<testIPs << " => "<<(isAllowed(firewall, testIPs) ? "ALLOWED" : "BLOCKED")<<endl;
    return 0;
}