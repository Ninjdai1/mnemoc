#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include <format>

struct Card {
    int id;
    char* front;
    char* back;
    int level;
    int box_id;
    int creation_date;
    int last_try;
};

struct box_t {
    int id;
    std::string name;
};

struct Box {
    int id;
    char* name;
    std::vector<Card> cards;

    std::string display(){
        return std::format("Box {} - {}: {} cards", this->id, this->name, this->cards.size());
    };
};

#endif // DATA_H
