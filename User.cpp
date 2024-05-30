#include "User.h"
#include <sys/stat.h>
#include <unistd.h>

User::User(const std::string &name, const std::string &login, const std::string &pass)
    : _name(name), _login(login), _pass(pass) {}

void User::serialize(std::ofstream &out) const {
    out << _name << "\n" << _login << "\n" << _pass << "\n";
}

void User::deserialize(std::ifstream &in) {
    std::getline(in, _name);
    std::getline(in, _login);
    std::getline(in, _pass);
}

void User::display() const {
    std::cout << "Name: " << _name << ", Login: " << _login << ", Pass: " << _pass << "\n";
}

void setFilePermissions(const std::string &filePath) {
    // Установить права доступа 0600: только владелец может читать и писать
    chmod(filePath.c_str(), S_IRUSR | S_IWUSR);
}

void saveUsers(const std::vector<User> &users, const std::string &filename) {
    std::ofstream outFile(filename, std::ios::out | std::ios::trunc);
    if (!outFile.is_open()) {
        std::cerr << "Could not open the file for writing: " << filename << std::endl;
        return;
    }
    for (const auto &user : users) {
        user.serialize(outFile);
    }
    outFile.close();
    setFilePermissions(filename);
}

void loadUsers(std::vector<User> &users, const std::string &filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Could not open the file for reading: " << filename << std::endl;
        return;
    }
    while (inFile.peek() != EOF) {
        User user;
        user.deserialize(inFile);
        users.push_back(user);
    }
    inFile.close();
}
