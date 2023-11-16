#include "word.h"
#include "string.h"
#include "ctype.h"

Word::Word(const char *text)
{
    for (int a=0; a<26; a++) {
        this->counts[a] = 0;
    }

    int i = 0;
    while (text[i] != 0) {
        int index = this->IndexFor(text[i]);
        i++;
        if (index < 0 || index > 26) continue;
        this->counts[index] += 1;
    }
}

bool Word::operator<=(Word b)
{
    for (int i = 0; i<26; i++) {
        if (this->counts[i] > b.counts[i]) return false;
    }
    return true;
}

Word Word::operator+(Word b)
{
    Word w = Word("");
    for (int i = 0; i<26; i++) {
        w.counts[i] = this->counts[i] + b.counts[i];
    }
    return w;
}

int Word::IndexFor(char c)
{
    return (int)(toupper(c) - 'A');
}
