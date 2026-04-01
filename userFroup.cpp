/*
The initial requirement was to design a data structure where: A user can belong to multiple groups We should be able to fetch: (i) all groups a user belongs to (ii) all users in a given group HashMap usage was initially not allowed.*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class UserGroupSystem {
private:
    // user -> groups
    unordered_map<string, unordered_set<string>> userToGroups;

    // group -> users
    unordered_map<string, unordered_set<string>> groupToUsers;

public:
    // Add user to group
    void addUserToGroup(const string& user, const string& group) {
        userToGroups[user].insert(group);
        groupToUsers[group].insert(user);
    }

    // Get all groups of a user
    unordered_set<string> getGroups(const string& user) {
        if (userToGroups.find(user) != userToGroups.end()) {
            return userToGroups[user];
        }
        return {};
    }

    // Get all users in a group
    unordered_set<string> getUsers(const string& group) {
        if (groupToUsers.find(group) != groupToUsers.end()) {
            return groupToUsers[group];
        }
        return {};
    }

    // Remove user from a group
    void removeUserFromGroup(const string& user, const string& group) {
        if (userToGroups.count(user)) {
            userToGroups[user].erase(group);
            if (userToGroups[user].empty()) {
                userToGroups.erase(user);
            }
        }

        if (groupToUsers.count(group)) {
            groupToUsers[group].erase(user);
            if (groupToUsers[group].empty()) {
                groupToUsers.erase(group);
            }
        }
    }

    // Debug print
    void printState() {
        cout << "\nUser -> Groups:\n";
        for (auto& [user, groups] : userToGroups) {
            cout << user << ": ";
            for (auto& g : groups) cout << g << " ";
            cout << "\n";
        }

        cout << "\nGroup -> Users:\n";
        for (auto& [group, users] : groupToUsers) {
            cout << group << ": ";
            for (auto& u : users) cout << u << " ";
            cout << "\n";
        }
    }
};

/*
#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class Graph {
private:
    vector<string> nodes;        // stores all users + groups
    vector<list<int>> adj;       // adjacency list using list

    // Find or create node index
    int getNodeIndex(const string& name) {
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == name) return i;
        }

        // create new node
        nodes.push_back(name);
        adj.push_back(list<int>());
        return nodes.size() - 1;
    }

public:
    // Add user-group relationship
    void addMembership(const string& user, const string& group) {
        int u = getNodeIndex(user);
        int g = getNodeIndex(group);

        adj[u].push_back(g);
        adj[g].push_back(u); // undirected graph
    }

    // Get all groups of a user
    list<string> getGroups(const string& user) {
        list<string> result;

        int u = -1;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == user) {
                u = i;
                break;
            }
        }

        if (u == -1) return result;

        for (int neighbor : adj[u]) {
            result.push_back(nodes[neighbor]);
        }

        return result;
    }

    // Get all users in a group
    list<string> getUsers(const string& group) {
        list<string> result;

        int g = -1;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == group) {
                g = i;
                break;
            }
        }

        if (g == -1) return result;

        for (int neighbor : adj[g]) {
            result.push_back(nodes[neighbor]);
        }

        return result;
    }

    // Debug print
    void printGraph() {
        for (int i = 0; i < nodes.size(); i++) {
            cout << nodes[i] << " -> ";
            for (int nei : adj[i]) {
                cout << nodes[nei] << " ";
            }
            cout << endl;
        }
    }
};
*/

/*
int main() {
    Graph g;

    g.addMembership("Alice", "Admin");
    g.addMembership("Alice", "Dev");
    g.addMembership("Bob", "Dev");

    g.printGraph();

    cout << "\nGroups of Alice: ";
    for (auto& grp : g.getGroups("Alice")) {
        cout << grp << " ";
    }

    cout << "\nUsers in Dev: ";
    for (auto& user : g.getUsers("Dev")) {
        cout << user << " ";
    }

    return 0;
}*/

/*
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Graph {
private:
    vector<string> nodes;              // stores all users + groups
    vector<vector<int>> adj;           // adjacency list

    // Helper to find node index
    int getNodeIndex(const string& name) {
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == name) return i;
        }

        // If not found, create new node
        nodes.push_back(name);
        adj.push_back({});
        return nodes.size() - 1;
    }

public:
    // Add edge: user <-> group
    void addMembership(const string& user, const string& group) {
        int u = getNodeIndex(user);
        int g = getNodeIndex(group);

        adj[u].push_back(g);
        adj[g].push_back(u);  // undirected graph
    }

    // Get all groups of a user
    vector<string> getGroups(const string& user) {
        vector<string> result;

        int u = -1;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == user) {
                u = i;
                break;
            }
        }

        if (u == -1) return result;

        for (int neighbor : adj[u]) {
            result.push_back(nodes[neighbor]);
        }

        return result;
    }

    // Get all users in a group
    vector<string> getUsers(const string& group) {
        vector<string> result;

        int g = -1;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == group) {
                g = i;
                break;
            }
        }

        if (g == -1) return result;

        for (int neighbor : adj[g]) {
            result.push_back(nodes[neighbor]);
        }

        return result;
    }

    // Debug print
    void printGraph() {
        for (int i = 0; i < nodes.size(); i++) {
            cout << nodes[i] << " -> ";
            for (int nei : adj[i]) {
                cout << nodes[nei] << " ";
            }
            cout << endl;
        }
    }
};*/

#include<bits/stdc++.h>
using namespace std;

class solution{
unordered_map<string, unordered_set<string>>uTg;
unordered_map<string, unordered_set<string>>gTu;
vector<string>names;

int findIndex(string name){
    for(int i=0;i<names.size();i++){
        if(names[i]==name) return i;
    }
    names.push_back(name);
    return names.size()-1;
}
void addUser(string name, string group){
    uTg[name].insert(group);
    gTu[group].insert(name);
}
unordered_set<string> getGroups(string username){

}
};