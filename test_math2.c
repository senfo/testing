#include <CUnit/Basic.h>
#include "math2.h"

int init_suite(void);
int clean_suite(void);
void test_is_prime(void);
void test_fibonacci(void);
void test_generate_prime(void);

int main(void) {
    CU_pSuite pSuite = NULL;

    // Initialize CUnit
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    // Add suite to the registry
    pSuite = CU_add_suite("Suite_1", init_suite, clean_suite);

    // Ensure we didn't have any problems adding suite to registry
    if (pSuite == NULL) {
        CU_cleanup_registry();

        return CU_get_error();
    }

    // Add the tests here...
    if (CU_add_test(pSuite, "test_is_prime()", test_is_prime) == NULL ||
        CU_add_test(pSuite, "test_fibonacci()", test_fibonacci) == NULL ||
        CU_add_test(pSuite, "test_generate_prime()", test_generate_prime) == NULL) {
        CU_cleanup_registry();

        return CU_get_error();
    }

    // Run the tests here...
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void test_is_prime(void) {
    CU_ASSERT(!is_prime(10));
    CU_ASSERT(!is_prime(15));
    CU_ASSERT(is_prime(13));
    CU_ASSERT(is_prime(197));
}

void test_fibonacci(void) {
    CU_ASSERT(fibonacci(8) == 21);
    CU_ASSERT(fibonacci(9) == 34);
    CU_ASSERT(fibonacci(10) == 55);
}

void test_generate_prime(void) {
    int prime;

    for (int x = 0; x < 10; x++) {
        prime = generate_prime(10, 1000);

        CU_ASSERT(is_prime(prime));
    }
}
