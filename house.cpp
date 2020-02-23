#include "house.h"
#include "sqlInterface.h"
#include <cmath>
#include <string>
using std::string;
using std::to_string;
using std::fabs;
//false is down, true is up
bool House::loadData() {
    sqlInterface db;
    try {
        db = sqlInterface();
    }
    catch (...) {
        return false;
    }
    jacks.clear();
    if (!db.execSQL("SELECT * FROM jacks ORDER BY id")) {
        return false;
    }
    else {
        auto table = db.getTable();
        for (auto i : table) {
            addJack(stoi(i[0]),stoi(i[1]));
        }
    }
    if (!db.execSQL("SELECT * FROM adjacent ORDER BY jack_id")) {
        return false;
    }
    else {
        //need to clean up
        auto table = db.getTable();
        for (auto i : table) {
            for (auto j : jacks) {
                if (j->getID() == stoi(i[0])) {
                    for (auto a : jacks) {
                        if (a->getID() == stoi(i[1])) {
                            j->addAdjJack(a,stoi(i[2]));
                            continue;
                        }
                    }
                    continue;
                }
            }
        }
    }
    return true;
};
bool House::saveData() {
    sqlInterface db;
    try {
        db = sqlInterface();
    }
    catch (...) {
        return false;
    }
    db.execSQL("DROP TABLE jacks");
    db.execSQL("DROP TABLE adjacent");
    //create tables if needed
    if (!db.execSQL("CREATE TABLE \"jacks\" (\"id\"	INTEGER NOT NULL UNIQUE, PRIMARY KEY(\"id\"))")) {
        return false;
    }
    if (!db.execSQL("CREATE TABLE \"adjacent\" (\"jack_id\"	bigint NOT NULL, \"adjacent_id\" bigint NOT NULL, PRIMARY KEY(\"jack_id\", \"adjacent_id\"), CONSTRAINT \"fk_adjacent_key1\" FOREIGN KEY(\"jack_id\") REFERENCES \"jacks\"(\"id\") on delete cascade deferrable initially deferred, CONSTRAINT \"fk_adjacent_key2\" FOREIGN KEY(\"adjacent_id\") REFERENCES \"jacks\"(\"id\") deferrable initially deferred )")) {
        return false;
    }
    //add jacks
    for (auto i : jacks) {
        if (!db.execSQL("INSERT INTO jacks(id) VALUES(" + to_string(i->getID()) + ")")) {
            return false;
        }
    }
    //add adjacents
    for (auto i : jacks) {
        for (auto ii : i->getList()) {
            if (!db.execSQL("INSERT INTO adjacent (jack_id,adjacent_id) VALUES (" + to_string(i->getID()) + "," + to_string(ii.first->getID()) + ")")) {
                return false;
            }
        }
    }
    return true;
};

//false is down, true is up
void House::findRelations(){
    for(auto jack : jacks) {
        auto list = jack->getList();
        jack->resetRelation();
        for (auto i : list) {
            if (i.first->getSensor()->getXAngle() < i.first->getSensor()->getPrecision() && i.second == 1 ||
                i.first->getSensor()->getXAngle() > i.first->getSensor()->getPrecision() && i.second == 0) {
                jack->increaseRelation();
            } else if (i.first->getSensor()->getXAngle() < i.first->getSensor()->getPrecision() && i.second == 0 ||
                       i.first->getSensor()->getXAngle() > i.first->getSensor()->getPrecision() && i.second == 1) {
                jack->decreaseRelation();
            } else if (i.first->getSensor()->getYAngle() < i.first->getSensor()->getPrecision() && i.second == 11 ||
                       i.first->getSensor()->getYAngle() > i.first->getSensor()->getPrecision() && i.second == 10) {
                jack->increaseRelation();
            } else if (i.first->getSensor()->getYAngle() < i.first->getSensor()->getPrecision() && i.second == 10 ||
                       i.first->getSensor()->getYAngle() > i.first->getSensor()->getPrecision() && i.second == 11) {
                jack->decreaseRelation();
            }
        }
    }
};
vector<shared_ptr<Jack>> House::greatestIncline(){
    int highest = 0;
    vector<shared_ptr<Jack>> work{};
    for(auto i : jacks){
        if(abs(i->getRelation())> highest){
            highest = abs(i->getRelation());
        }
    }
    if (highest == 0) {
        return work;
    }
    for(auto i : jacks){
        if(abs(i->getRelation()) == highest){
            work.push_back(i);
        }
    }
    return work;
}
void House::workJacks(vector<shared_ptr<Jack>> work) {
    for(auto i : work){
        if(i->getRelation() < 0 && !workingOnPos){
            i->raise();
        }
        else if(i->getRelation() > 0 && workingOnPos){
            i->lower();
        }
    }
    workingOnPos = !workingOnPos;
}
bool House::addJack(const double &h,const int &pin){
    shared_ptr<Jack> jack(new Jack(serial,counterID++,pin,h));
    jacks.push_back(jack);
    return true;
}

bool House::removeJack(const int &id){
    for(size_t i = 0; i < jacks.size();i++){
        if(jacks[i]->getID()==id){
            jacks.erase(jacks.begin() + i);
            return true;
        }
    }
    return false;
};

bool House::bIsGood(){
    for(auto i : jacks){
        if(!i->bIsGood()){
            return false;
        };
    }
    return true;
}
//false = unlevel, true = level
bool House::checkLevel(){

#if TESTING
    emuAngles();
#endif
    for (auto i : jacks) {

#if TESTING

#else
        i->getSensor()->getAngles();
#endif
        const double hold = fabs(i->getSensor()->getXAngle()) + fabs(i->getSensor()->getYAngle());
        if (hold > (i->getSensor()->getPrecision()*2.5)) {
            return false;
        }
    }
    return true;
}
void House::levelOnce(){
    if(checkLevel()){
        return;
    }
    findRelations();
    workJacks(greatestIncline());

    //emuAngles();
    return;
}
void House::autoLevel() {
    while (!checkLevel()) {
        levelOnce();
    }
}