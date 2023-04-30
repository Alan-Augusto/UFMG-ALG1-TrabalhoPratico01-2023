# Compilador a ser utilizado
CC=g++

# Flags de compilação
CFLAGS=-c -Wall

# Diretório onde os arquivos objeto serão gerados
OBJ_DIR=./obj

# Diretório onde os arquivos executáveis serão gerados
BIN_DIR=./bin

# Nome do arquivo executável a ser gerado
EXECUTABLE=$(BIN_DIR)/programa

# Lista de arquivos fonte a serem compilados
SOURCES=./src/main.cpp

# Lista de arquivos objeto gerados a partir dos arquivos fonte
OBJECTS=$(SOURCES:./src/%.cpp=$(OBJ_DIR)/%.o)

# Comando para compilar os arquivos objeto
$(OBJ_DIR)/%.o: ./src/%.cpp
	$(CC) $(CFLAGS) $< -o $@

# Comando para gerar o arquivo executável
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

# Comando para limpar os arquivos objeto e executável gerados
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Comando para compilar e executar o programa
run: $(EXECUTABLE)
	$(EXECUTABLE)

# Comando padrão, que compila o programa
all: $(EXECUTABLE)

.PHONY: clean run all
