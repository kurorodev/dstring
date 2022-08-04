#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct dstring
{
    uint8_t* data;
    uint8_t lenght;
    uint8_t how_much;
}str_t;

str_t* string_create(uint8_t length) 
{
    str_t* string = (str_t*)malloc(sizeof(str_t));
    string->data = malloc(length);
    string->lenght = length;
    string->how_much = 0;

    return string;
}

void string_free(str_t* string)
{
    free(string->data);
    free(string);
}

uint8_t string_lenght(str_t* string)
{
   return string->lenght;
}

void print_string(str_t* string, FILE* file)
{
    fwrite(string->data, sizeof(uint8_t), string->lenght, file);
}

str_t* string_dup(const char* str)
{   
    str_t* string = string_create(strlen(str));
    memcpy(string->data, str, string->lenght);
    string->how_much = string->lenght;
    return string;
}

str_t* string_concatenate(str_t* lstring, str_t* rstring)
{
    str_t* string = string_create(lstring->lenght + rstring->lenght);
    memcpy(string->data, lstring->data, lstring-> lenght);
    memcpy(string->data, rstring->data, rstring->lenght);
    string->how_much = string->lenght;
    return string;
}