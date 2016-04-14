//
//  main.cpp
//  Simple_Database
//
//  Created by xiaolingtc on 3/16/16.
//  Copyright © 2016 xiaolingtc. All rights reserved.
//

//#include <iostream>
#include "Database.hpp"
#include  <stack>
#include <fstream>


using namespace std;

int main(int argc, const char * argv[]) {
    
    Database db;
    stack<Block> st; // store transactions
    string command;
    string name;
    int value;
    ifstream file;
    
    //char str[100];
//    while (file.getline(str, 100)) {
//        cout << str <<endl;
//    }
//    if (!file.is_open()) {
//        cout << "fail";
//    }
    
    if (argc > 1) {
        file.open(argv[1],ifstream::in); //g++ works well, but need to add absolute path when be called in Xcode
        //cout << argv[1];
    }
    
    while (1) {
//        if (!st.empty()) {
//            cout << st.top().history.size();
//        }
        if (file >> command) {
            //cout << command;
        }
        else {
            cin >> command;
        }
    
    if (command == "BEGIN") {
        st.push(Block());
    }
    else if (command == "SET") {
        if (file >> name >> value) {
        }
        else{
            cin >> name >> value ;
        }
        if (!st.empty()) {
            st.top().his_set(name, db.db_get(name));
        }
        db.db_set(name, value);
    }
    else if (command == "GET") {
        if (file >> name) {
        }
        else{
            cin >> name;
        }
        if (db.db_get(name) ==  INT_MIN) {
            cout << "NULL"<<endl;
        }
        else {
            cout << db.db_get(name) << endl;
        }
    }
    else if (command == "UNSET") {
        if (file >> name) {
        }
        else{
            cin >> name;
        }
        if (db.db_get(name) == INT_MIN) {
            cerr << "NOT EXIST";
        }
        else {
            if (!st.empty()) {
                Block recent = st.top(); // It doesn't work if I manipulate recent even it's a reference.
                
                st.top().his_set(name, db.db_get(name));
                //cout << st.top().history.size();
            }
            
            //cout << st.top().history.size();
                
            db.db_unset(name);
                //cout << recent.history.begin()->first<<"  " << recent.history.begin()->second<<endl;
            
        }
    }
    else if (command == "NUMEQUALTO") {
        if (file >> value) {
        }
        else{
            cin >> value;
        }
        cout << db.db_num_equal_to(value) << endl;
    }
    else if (command == "ROLLBACK") {
        if (!st.empty()) {
            Block recent = st.top();
            //cout << recent.history.size();
            recent.rollback(db);
            st.pop();
        }
        else {
            cout << "NO TRANSACTION" << endl;
        }
    }
    else if (command == "COMMIT") {
        if (st.empty()) {
            cout << "NO TRANSACTION"<<endl;
        }
        while (!st.empty()) {
            st.pop();
        }
    }
    else if (command == "END") {
        exit(0);
    }
    else{
        cout << "ENTER VALID COMMAND"<<endl;
    }
    }
}
