#include "Message.h"
#include <sys/stat.h>
#include <unistd.h>

Message::Message(const std::string &text, const std::string &sender, const std::string &receiver)
    : _text(text), _sender(sender), _receiver(receiver) {}

void Message::serialize(std::ofstream &out) const {
    out << _text << "\n" << _sender << "\n" << _receiver << "\n";
}

void Message::deserialize(std::ifstream &in) {
    std::getline(in, _text);
    std::getline(in, _sender);
    std::getline(in, _receiver);
}

void Message::display() const {
    std::cout << "Text: " << _text << ", Sender: " << _sender << ", Receiver: " << _receiver << "\n";
}

void setFilePermissions(const std::string &filePath) {
    // Установить права доступа 0600: только владелец может читать и писать
    chmod(filePath.c_str(), S_IRUSR | S_IWUSR);
}

void saveMessages(const std::vector<Message> &messages, const std::string &filename) {
    std::ofstream outFile(filename, std::ios::out | std::ios::trunc);
    if (!outFile.is_open()) {
        std::cerr << "Could not open the file for writing: " << filename << std::endl;
        return;
    }
    for (const auto &message : messages) {
        message.serialize(outFile);
    }
    outFile.close();
    setFilePermissions(filename);
}

void loadMessages(std::vector<Message> &messages, const std::string &filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Could not open the file for reading: " << filename << std::endl;
        return;
    }
    while (inFile.peek() != EOF) {
        Message message;
        message.deserialize(inFile);
        messages.push_back(message);
    }
    inFile.close();
}
