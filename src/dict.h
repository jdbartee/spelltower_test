#pragma once

typedef struct Dictionary {
    int wordCount;
    int maxWords;
    char** words;
} Dictionary;

Dictionary NewDictionary();
int AddWord(Dictionary* dict, char* word);
int FreeDictionary(Dictionary* dict);
Dictionary LoadDictionary();