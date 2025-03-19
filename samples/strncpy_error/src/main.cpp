/*
 * Copyright (c) Fredrik Gihl
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This function test the strncpy function so it copy a string correct.
// We copy string from 5 bytes to 40bytes, and verify that the string is copied correct.
void test_strncpy(void)
{
    uint8_t*            str = (uint8_t*)malloc(100);
    

    char src[49];

    auto testStr = [str](uint8_t* dest, const char* src) 
    {
        char* tempStr = (char*)dest;

        strncpy(tempStr, src, 49);
        if(strcmp(tempStr, src) != 0)
        {
            printf("strncpy failed(len=%d). String: %s, expected: %s\n",
                      strlen(src),
                      tempStr,
                      src);
        }
        tempStr++;
    };

    auto fillStr = [&src](size_t len) -> char* 
    {
        for (size_t i = 0; i < len; i++)
        {
            src[i] = 'A' + (i % 26);
        }
        src[len] = '\0';
        return (char*)src;
    };

    for (size_t strLen = 5; strLen < 40; strLen++)
    {
        printf("Test %d\n", strLen);
        testStr(str, fillStr(strLen));
    }
    free(str);
}


int main(void)
{
    test_strncpy();

	return 0;
}
