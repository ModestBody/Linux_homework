#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Message {
private:
    std::string _text;
    std::string _sender;
    std::string _receiver;
public:
    Message() = default;
    Message(const std::string &text, const std::string &sender, const std::string &receiver);

    void serialize(std::ofstream &out) const;
    void deserialize(std::ifstream &in);
    void display() const;
};

void saveMessages(const std::vector<Message> &messages, const std::string &filename);
void loadMessages(std::vector<Message> &messages, const std::string &filename);

#endif // MESSAGE_H
