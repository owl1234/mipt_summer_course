/**
 * @file
 * @author Kolesnikova Xenia <heiduk.k.k.s@yandex.ru>
 * @version 1.0 *
 */

// #include "TXLib.h"
#include <stdio.h>
#include "Onegin.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main (int argc, char* argv[]) {
    // Begin to count the length of the string

    FILE* poem;
    poem = open_file(&poem, argv[1]);
    if(poem == nullptr) {
        return 3802;
    }

    int max_length = 0;
    int lines = number_of_lines(poem, &max_length);

    char** text = (char**)calloc(lines + 1, sizeof(char*));
    for(int i=0; i<lines; ++i) {
        text[i] = (char*)calloc(max_length + 1, sizeof(char));
    }

    close_file(&poem);

    // End to count the length of the string


    // Begin to read the string

    poem = open_file(&poem, argv[1]);
    if(poem == nullptr) {
        return 3802;
    }

    int line = 0;

    while (line < lines) {
        int i = 0;
        char symbol = '!';

        while(symbol != '\n') {
            fscanf(poem, "%c", &symbol);
            text[line][i] = symbol;
            ++i;
        }

        line++;
    }

    close_file(&poem);

    // End to read the string

    qsort(text, line, sizeof(text[0]), comparator);

    printf("%s %s\n", argv[1], argv[2]);
    FILE *fdout = fopen(argv[2], "w");

    for (int i = 0; i < line; ++i)
        fputs(text[i], fdout);

    fclose(fdout);

    return 0;
}

int comparator(const void* first_string, const void* second_string) {
    const char* first  =  *(const char**)first_string;
    const char* second = *(const char**)second_string;

    return strcmp(first, second);
}

int strcmp (const unsigned char* str1, const unsigned char* str2) {
    while(*str1 == *str2) {
        if(*str1 == '\0') {
            return 0;
        }
        str1++;
        str2++;
    }

    return *str1 - *str2;
}

int number_of_lines(FILE* file, int* max_length) {
    int lines = 0, now_length = 0;
    char symbol = '!';

    while(!feof(file)) {
        fscanf(file,"%c", &symbol);
        if(symbol == '\n') {
            ++lines;
            *max_length = ((*max_length) < now_length ? now_length : (*max_length));
            now_length = 0;
        } else {
            ++now_length;
        }
    }

    --lines;

    return lines;
}

FILE* open_file(FILE** file, char* file_name) {
    *file = fopen(file_name, "r");

    if(*file == nullptr) {
        printf("File Onegin.txt wasn't opened\n");
        return nullptr;
    }

    return *file;
}

void close_file(FILE** file) {
    fclose(*file);
}

