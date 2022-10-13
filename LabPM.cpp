#include "GenTests.h"
#include "Test.h"
#include "TimeLogger.h"



int main(){
    srand(time(NULL));

    gtest::GenTest* gentest = new gtest::GenTest;
    gentest->gen_tests();

    experiments::Test* test = new experiments::Test;
    test->run(*gentest);

    delete test;
    test = nullptr;

    //gentest->remove_files();
    delete gentest;
    gentest = nullptr;

    return 0;
}