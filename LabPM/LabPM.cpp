﻿#include "GenTests.h"
#include "Test.h"


int main(){
    srand(time(NULL));

    gtest::GenTest* gentest = new gtest::GenTest;
    gentest->gen_tests();

    experiments::Test* test = new experiments::Test;
    test->run();

    delete test;
    test = nullptr;

    delete gentest;
    gentest = nullptr;

    return 0;
}