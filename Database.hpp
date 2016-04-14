//
//  Database.hpp
//  Simple_Database
//
//  Created by xiaolingtc on 3/16/16.
//  Copyright © 2016 xiaolingtc. All rights reserved.
//

#ifndef Database_hpp
#define Database_hpp

#include <stdio.h>
#include <unordered_map>
#include <iostream>

#define OK 1;
#define NODATA INT_MIN;
#define ERROR 0;

using namespace std;

class Database {
private:
    unordered_map<string, int> db; // record data
    unordered_map<int, int> counter; // record counter for NUMEQUALTO
    
public:
    Database(){}
    
    void db_set(const string &name, const int &value){
        
        if (db.find(name) == db.end()) {
            if (counter.find(value) == counter.end()) {
                counter[value] = 1;
            }
            else {
                counter[value] ++;
            }
        }
        else {
            counter[db[name]] --;
            counter[value] ++;
        }
        
        db[name] = value;
        
    }
    
    int db_get(const string &name){
        
        if(db.find(name) != db.end()){
            return db[name];
        }
        return NODATA;
        
    }
    
    void db_unset(const string &name){
        
        if(db.find(name) != db.end()){
            
            counter[db[name]] --;
            db.erase(name);
        }
        else{
            cerr << "NOT EXIST" <<endl;
        }
    }
    
    int db_num_equal_to(const int value){
        
        if(counter.find(value) == counter.end()) return 0;
        return counter[value];
    }
    
};

class Block {
public:
    unordered_map<string, int> history; // record history data
    
public:
    Block() {}
    
    void his_set(const string name, const int value) {
        history[name] = value;
    }
    
    void rollback(Database& db) {
        
        for(auto it : history) {
            db.db_set(it.first, it.second);
        }
        
    }
    
};

























#endif /* Database_hpp */
