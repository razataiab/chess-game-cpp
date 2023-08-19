#define BOOST_TEST_MODULE MyProjectTests

#include <boost/test/included/unit_test.hpp>


#include "main.cpp"

// Define a test case
BOOST_AUTO_TEST_CASE(test_main_function) {
    int result = main();  // Call the main function
    BOOST_CHECK_EQUAL(result, 0);  // Check if it returns 0
}
