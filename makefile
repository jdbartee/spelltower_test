all: spell

CFLAGS = -g -MMD -Wall -I/opt/homebrew/include -std=c++11
LINKERFLAGS = 
LDLIBS = 

spell: bin/spell
bin/spell: build/spell.o build/word.o build/dict.o

build/%.o: src/%.cpp
	@mkdir -p build
	$(CXX) $(CFLAGS) -c $< -o $@

bin/%:
	$(CXX) $(LINKERFLAGS) $^ $(LDLIBS) -o $@

.PHONY: clean
clean:
	rm -f bin/*
	rm -f build/*

.PHONY: run
run: spell
	./bin/spell

-include build/*.
