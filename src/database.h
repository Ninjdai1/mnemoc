#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>

struct Database {
    sqlite3 *db;

    int init();
    void graceful_exit();
};

#endif // DATABASE_H
