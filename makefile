CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = analisador_sintatico_tonto

SRCS = parser.cpp lexer.cpp symbols_table.cpp compiler_context.cpp
HDRS = tokens.h symbols_table.h compiler_context.h

all: $(TARGET)

parser.cpp tokens.h: parser.y
	bison -d --defines=tokens.h parser.y -o parser.cpp

lexer.cpp: lexer.l tokens.h
	flex -o lexer.cpp lexer.l

$(TARGET): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: all
	./$(TARGET) exemplo.tonto

clean:
	rm -f $(TARGET) parser.cpp tokens.h lexer.cpp lex.yy.c