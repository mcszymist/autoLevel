#pragma once
#include "sqlite3.h"
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::to_string;
#include <vector>
using std::vector;

vector<string> columns;
vector<vector<string>> table;

static int callback(void* data, int argc, char** argv, char** azColName) {
    int i;
    vector<string> row;
    columns.clear();
    for (i = 0; i < argc; i++) {
        columns.push_back(azColName[i]);
        row.push_back(argv[i] ? argv[i] : "NULL");
    }
    table.push_back(row);

    return 0;
}

class sqlInterface {
private:
    sqlite3* db;
    int rc;
    char* zErrMsg = 0;
    const char* data = "Callback function called";

public:
    sqlInterface() {
        rc = sqlite3_open("house.DB", &db);
        if (rc) {
            cout << "Can't open database: " << sqlite3_errmsg(db);
            sqlite3_close(db);
            throw("Can't open database");
        }

    }
    sqlInterface(const string &name) {
        rc = sqlite3_open(name.c_str(), &db);
        if (rc) {
            cout << "Can't open database: " << sqlite3_errmsg(db);
            sqlite3_close(db);
            throw("Can't open database");
        }
    }
    ~sqlInterface() {
        sqlite3_close(db);
    }
    bool execSQL(const string& sql) {
        rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
            return false;
        }
        else {
            fprintf(stdout, "Operation done successfully\n");
        }
        return true;
    }
    const vector<vector<string>> getTable() {
        return table;
    }
    const vector<string> getCol() {
        return columns;
    }
private:


};

