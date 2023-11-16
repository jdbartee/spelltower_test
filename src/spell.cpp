#include <stdio.h>
#include "word.h"
#include "dict.h"
#include <string.h>

const char* baseString = "aaaaaaaabbcccccddddeeeeeeeeeeeeffggghhhiiiiiiiiiijkllllllmmmnnnnnnnoooooooppppqrrrrrrrsssssssssstttttttuuuuvwxyyz";

int main() {
    Word base = Word(baseString);

    Dictionary dict = LoadDictionary();
    Dictionary dict15 = NewDictionary();
    Dictionary dict12 = NewDictionary();
    Dictionary dict7 = NewDictionary();

    for (int i=0; i<dict.wordCount; i++) {
        auto word = dict.words[i];
        switch (strlen(word)) {
            case 15: AddWord(&dict15, word); break;
            case 12: AddWord(&dict12, word); break;
            case 7: AddWord(&dict7, word); break;
        }
    }

    for (int i15 = 100; i15<dict15.wordCount; i15++) {
        printf("%d/%d\n", i15, dict15.wordCount);
        char* word15 = dict15.words[i15];
        if (! (Word(word15)<=base) ) continue;

        for (int i12_1 = 0; i12_1 < dict12.wordCount; i12_1++) {
            char * word12_1 = dict12.words[i12_1];
            if (! ((Word(word15) + Word(word12_1)) <= base)) continue;
            for (int i12_2 = i12_1 + 1; i12_2 <dict12.wordCount; i12_2++) {
                char * word12_2 = dict12.words[i12_2];
                if (! ((Word(word15) + Word(word12_1) + Word(word12_2)) <= base)) continue;
                for (int i12_3 = i12_2 + 1; i12_3 <dict12.wordCount; i12_3++) {   
                    char * word12_3 = dict12.words[i12_3];
                    if (! ((Word(word15) + Word(word12_1) + Word(word12_2) + Word(word12_3)) <= base)) continue; 
                    for (int i12_4 = i12_3 + 1; i12_4 <dict12.wordCount; i12_4++) {
                        char * word12_4 = dict12.words[i12_4];
                        if (! ((Word(word15) + Word(word12_1) + Word(word12_2) + Word(word12_3) + Word(word12_4)) <= base)) continue;
                        for (int i12_5 = i12_4 + 1; i12_5 <dict12.wordCount; i12_5++) {
                            char * word12_5 = dict12.words[i12_5];
                            if (! ((Word(word15) + Word(word12_1) + Word(word12_2) + Word(word12_3) + Word(word12_4) + Word(word12_5)) <= base)) continue;
                            for (int i7 = 0; i7 < dict7.wordCount; i7++) {
                                char * word7 = dict7.words[i7];
                                if (! ((Word(word15) + Word(word12_1) + Word(word12_2) + Word(word12_3) + Word(word12_4) + Word(word12_5) + Word(word7)) <= base)) continue;

                                printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n", word15, word12_1, word12_2, word12_3, word12_4, word12_5, word7);
                            }
                        } 
                    }
                }
            }
        }
    }
}