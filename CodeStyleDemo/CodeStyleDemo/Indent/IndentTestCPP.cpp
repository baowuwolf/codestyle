//
//  IndentTestCPP.cpp
//  CodeStyleDemo
//
//  Created by wangchao9 on 2017/5/15.
//  Copyright © 2017年 wangchao9. All rights reserved.
//

#include "IndentTestCPP.hpp"
#include <string>

using namespace std;

extern "C" {
    void foo();
}

struct sAddress {
    int a;
    void test(){

    }
};

class Address {
    Address(std::string p1,
        std::string p2,
        std::string p3,
        std::string p4,
        std::string p5,
        std::string p6,
        std::string p7){

    }
};

//comment
//comms

class Person {
private:
    // commen
    string name; //comment
    // comment
    int age;//comment
    // comment
    Address address("1", "2",
        "3", "4", "5", "6", "7");
public:
    Person(std::string name, int age, string address)
        : name(name), age(age){

    }

    int getAge()   const {
        return 100;
    }

    int getAge2()
    const {
        return 100;
    }
};
