#include<bits/stdc++.h>
using namespace std;

class User {
public:
    int id;
    string name;

    User(int id, string name) {
        this->id = id;
        this->name = name;
    }
};

class UserService {
private:
    unordered_map<int, User*> users;

public:
    void addUser(User* user) {
        users[user->id] = user;
    }

    User* getUser(int id) {
        if(users.find(id) != users.end())
            return users[id];
        return nullptr;
    }
};
int main(){
    
}