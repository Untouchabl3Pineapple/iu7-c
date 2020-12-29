#include "my_strspn.h"

int main(void)
{
    int test_1, test_2;
    int result = 1;
    
    test_1 = strspn("", "as");
    test_2 = my_strspn("", "as");
    result &= test_1 == test_2;
    
    printf("STRSPN: %d\n", test_1);
    printf("MY_STRSPN: %d\n", test_2);
    
    test_1 = strspn("1234", "2");
    test_2 = my_strspn("1234", "2");
    result &= test_1 == test_2;
    
    printf("STRSPN: %d\n", test_1);
    printf("MY_STRSPN: %d\n", test_2);
    
    test_1 = strspn("1234", "1234");
    test_2 = my_strspn("1234", "1234");
    result &= test_1 == test_2;
    
    printf("STRSPN: %d\n", test_1);
    printf("MY_STRSPN: %d\n", test_2);
    
    test_1 = strspn("frfrerf", "g");
    test_2 = my_strspn("frfrerf", "g");
    result &= test_1 == test_2;
    
    printf("STRSPN: %d\n", test_1);
    printf("MY_STRSPN: %d\n", test_2);
    
    test_1 = strspn("ghghght", "gh");
    test_2 = my_strspn("ghghght", "gh");
    result &= test_1 == test_2;
    
    printf("STRSPN: %d\n", test_1);
    printf("MY_STRSPN: %d\n", test_2);
    
    test_1 = strspn("ghghght", "ght");
    test_2 = my_strspn("ghghght", "ght");
    result &= test_1 == test_2;
    
    printf("STRSPN: %d\n", test_1);
    printf("MY_STRSPN: %d\n", test_2);
    
    test_1 = strspn("0", "0");
    test_2 = my_strspn("0", "0");
    result &= test_1 == test_2;
    
    printf("STRSPN: %d\n", test_1);
    printf("MY_STRSPN: %d\n", test_2);
    
    test_1 = strspn(" ", "");
    test_2 = my_strspn(" ", "");
    result &= test_1 == test_2;
    
    printf("STRSPN: %d\n", test_1);
    printf("MY_STRSPN: %d\n", test_2);
    
    test_1 = strspn(" 3", " 3");
    test_2 = my_strspn(" 3", " 3");
    result &= test_1 == test_2;
    
    printf("STRSPN: %d\n", test_1);
    printf("MY_STRSPN: %d\n", test_2);
    
    if (result == 1)
        return SUCCESS;
    
    printf("An error occurred, please check that the program is working correctly");
        
    return FAIL;
}

