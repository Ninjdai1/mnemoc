#include "database.h"
#include "data.h"
#include "glib.h"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

const char* CARDS_TABLE_CREATE_STRING= "CREATE TABLE IF NOT EXISTS cards ( \
    id            INTEGER NOT NULL UNIQUE,\
    front         TEXT,\
    back          TEXT,\
    level         INTEGER,\
    box_id        INTEGER,\
    creation_date INTEGER,\
    last_try      INTEGER,\
    PRIMARY KEY(id AUTOINCREMENT),\
    FOREIGN KEY(box_id) REFERENCES boxes(id)\
);";

const char* BOXES_TABLE_CREATE_STRING = "CREATE TABLE IF NOT EXISTS boxes (\
    id   INTEGER NOT NULL UNIQUE,\
    name TEXT,\
    PRIMARY KEY(id AUTOINCREMENT)\
);";

static int boxes_callback(void *data, int argc, char **argv, char **colName){
    int i;
    std::vector<box_t> *boxes = (std::vector<box_t> *)data;
    
    for(i=0; i<argc; i+=2){
        box_t box = box_t{
            .id = atoi(argv[i]),
            .name = std::string(argv[i+1])
        };
        boxes->push_back(box);
    }
    return 0;
}

int Database::init(){
    int rc;
    char *zErrMsg = 0;

    rc = sqlite3_open("mnemoc.db", &db);

    if(rc!=SQLITE_OK) { std::cerr << "Can't open database: " << sqlite3_errmsg(db); return 0;}
    
    rc = sqlite3_exec(db, CARDS_TABLE_CREATE_STRING, NULL, NULL, &zErrMsg);
    if(rc!=SQLITE_OK) { std::cerr << "Error creating cards table: " << &zErrMsg; return 0;}

    rc = sqlite3_exec(db, BOXES_TABLE_CREATE_STRING, NULL, NULL, &zErrMsg);
    if(rc!=SQLITE_OK) { std::cerr << "Error creating boxes table: " << &zErrMsg; return 0;}

    std::vector<box_t> boxes;
    sqlite3_exec(db, "SELECT * FROM boxes", boxes_callback, &boxes, &zErrMsg);

    for (size_t i = 0; i < boxes.size(); i++) {
        std::cout<<boxes[i].id<<" - ";
        std::cout<<boxes[i].name<< "\n";
    }

    g_print("Database initialized\n");

    return 1;
}

void Database::graceful_exit(){
    std::cout << "Closing database...\n";
    sqlite3_close(db);
    std::cout << "Database closed.\n";
}
