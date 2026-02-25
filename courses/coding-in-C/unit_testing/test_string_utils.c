#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "string_utils.h"

void test_custom_len()
{
    assert(custom_len("hello") == 5);
    assert(custom_len("")==0);
    assert(custom_len("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789") == 90);
}

void test_read_line_dynamic()
{
    char string1[5] = "helo";
    assert(*(read_line_dynamic()) == *string1);
    assert(read_line_dynamic() != NULL);
}

int main()
{
    test_custom_len();
    test_read_line_dynamic();
    printf("Success\n");
    return 0;
}