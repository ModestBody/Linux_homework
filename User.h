#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class User {
private:
    std::string _name;
    std::string _login;
    std::string _pass;
public:
    User() = default;
    User(const std::string &name, const std::string &login, const std::string &pass);

    void serialize(std::ofstream &out) const;
    void deserialize(std::ifstream &in);
    void display() const;
};

void saveUsers(const std::vector<User> &users, const std::string &filename);
void loadUsers(std::vector<User> &users, const std::string &filename);

#endif // USER_H
