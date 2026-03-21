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
    UserService us;
    User* u1 = new User(1,"abc");
    User* u2 = new User(2, "cde");

    us.addUser(u1);
    us.addUser(u2);

    User* user = us.getUser(1);

    if(user != nullptr) {
        cout << "User found: " << user->name << endl;
    } else {
        cout << "User not found" << endl;
    }

    return 0;
}