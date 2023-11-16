#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"
#include "dict.h"

Dictionary NewDictionary() {
    Dictionary dict;
    dict.wordCount = 0;
    dict.maxWords = 2;
    dict.words = (char**)malloc(sizeof(char*)*dict.maxWords);
    return dict;
}

int AddWord(Dictionary* dict, char* word) {
    if (dict->wordCount >= dict->maxWords) {
        dict->maxWords = dict->maxWords * 2;
        dict->words = (char**)realloc(dict->words, sizeof(char*)*dict->maxWords);
    }
    int l = strlen(word) + 1; // Include null terminator
    char* w = (char*)malloc(sizeof(char)*l);
    strcpy(w, word);
    dict->words[dict->wordCount] = w;
    dict->wordCount += 1;
    return 0;
}

int FreeDictionary(Dictionary* dict) {
    for(int i=0; i<dict->wordCount; i++) {
        free(dict->words[i]);
    }
    free(dict->words);
    return 0;
}


char* normalize(char* input) {
    int i = 0;
    int o = 0;
    while(input[i] != 0) {
        if (isalpha(input[i]) == 1) {
            input[o] = toupper(input[i]);
            o++;
        }
        i++;
    }
    input[o] = 0;

    return input;
}

Dictionary LoadDictionary() {
    const char* WORDS_PATH = "/usr/share/dict/words";
    Dictionary dict = NewDictionary();
    FILE *fptr;
    fptr = fopen(WORDS_PATH, "r");
    char* file_buffer = (char*) malloc(sizeof(char)*100);

    while(fscanf(fptr, "%s", file_buffer) != EOF) {
        file_buffer = normalize(file_buffer);
        AddWord(&dict, file_buffer);
    }
    fclose(fptr);
    free(file_buffer);
    return dict;
}