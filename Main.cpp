#include "User.h"
#include "Message.h"

int main() {
    std::vector<User> users;
    std::vector<Message> messages;

    std::string userFile = "users.dat";
    std::string messageFile = "messages.dat";

    // Load data from files
    loadUsers(users, userFile);
    loadMessages(messages, messageFile);

    // Display loaded data
    std::cout << "Loaded Users:\n";
    for (const auto &user : users) {
        user.display();
    }

    std::cout << "Loaded Messages:\n";
    for (const auto &message : messages) {
        message.display();
    }

    // Modify data
    users.emplace_back("John Doe", "johndoe", "password123");
    messages.emplace_back("Hello, John!", "Alice", "John");

    // Save data back to files
    saveUsers(users, userFile);
    saveMessages(messages, messageFile);

    return 0;
}
