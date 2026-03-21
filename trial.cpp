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
    unordered_map<int, User> users;

public:
    void addUser(const User& user) {
        users.emplace(user.id, user);
    }

    User& getUser(int id) {
        if(users.find(id) != users.end())
            return users.at(id);
        throw runtime_error("User not found");
    }
};
int main(){
    UserService us;
    User u1(1,"abc");
    User u2(2, "cde");

    us.addUser(u1);
    us.addUser(u2);


   try {
        User& user = us.getUser(1);
        cout << "User found: " << user.name << endl;
    } catch(exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}