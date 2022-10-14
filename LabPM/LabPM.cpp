#include "GenTests.h"
#include "Test.h"
#include "TimeLogger.h"


int main(){
    srand(time(NULL));
    tlog::TimeLogger::db_mode = 1;

    gtest::GenTest* gentest = new gtest::GenTest;
    gentest->async_gen_tests();
    //gentest->gen_tests();

    experiments::Test* test = new experiments::Test;
    test->async_run();
    //test->run();

    delete test;
    test = nullptr;

    delete gentest;
    gentest = nullptr;

    return 0;
}