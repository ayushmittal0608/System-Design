#include <bits/stdc++.h>
using namespace std;

struct RadixNode {
    bool isEnd = false;
    vector<string> files;
    RadixNode* child[2] = {nullptr, nullptr};
};

string ipToBinary(const string& ip){
    stringstream ss(ip);
    string token, binary="";
    while(getline(ss, token, '.')){
        int num = stoi(token);
        for(int i=7; i>=0; i--){
            binary += ((num >> i) & i) ? '1' : '0';
        }
    }
    return binary;
}

void insert(RadixNode* root, const string& ip, const string& filename){
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
    node->files.push_back(filename);
}

vector<string>search(RadixNode* root, const string& ip){
    string bits = ipToBinary(ip);
    RadixNode* node = root;
    for(char bit:bits){
        int idx = bit - '0';
        if(!node->child[idx]){
            return {};
        }
        node = node->child[idx];
    }
    return node->isEnd ? node->files : vector<string>{};
}

int main(){
    RadixNode* node = new RadixNode();
    insert(node, "192.168.1.1", "files.txt");
    insert(node, "192.168.1.1", "files2.txt");
    insert(node, "192.168.1.2", "images.png");
    string ip;
    cout<<"Enter your IP: ";
    cin>>ip;
    auto files = search(node, "192.168.1.1");
    if(!files.empty()){
        cout<<"Files found are:"<<endl;
        for(auto &f:files){
            cout<<'-'<<f<<endl;;
        }
    }
    else{
        cout<<"No file found"<<endl;
    }

}