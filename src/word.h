#pragma once



class Word {
    int counts[26];

    public:
    Word(const char* text);
    bool operator <= (Word b);
    Word operator + (Word b);

    private:
    int IndexFor(char c);
};