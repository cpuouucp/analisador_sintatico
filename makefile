# Alvo principal: compila o analisador sintatico TONTO
all: analisador_sintatico_tonto

# 1. Gera o analisador sintático (parser.cpp) e o cabeçalho de tokens (tokens.h) usando o Bison
parser.cpp tokens.h: parser.y
	bison -d --defines=tokens.h parser.y -o parser.cpp

# 2. Gera o analisador léxico (lexer.cpp) usando o Flex (depende de tokens.h)
lexer.cpp: lexer.l tokens.h
	flex -o lexer.cpp lexer.l

# 3. Compila os arquivos gerados em C++ e cria o executável final
analisador_sintatico_tonto: parser.cpp lexer.cpp
	g++ -std=c++17 parser.cpp lexer.cpp -o analisador_sintatico_tonto

# Atalho para rodar o analisador passando um arquivo de exemplo
run: all
	./analisador_sintatico_tonto exemplo.tonto

# Limpa todos os arquivos gerados automaticamente pela compilação
clean:
	rm -f analisador_sintatico_tonto parser.cpp tokens.h lexer.cpp lex.yy.c