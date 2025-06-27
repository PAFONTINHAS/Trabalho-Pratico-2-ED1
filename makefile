# Define the C compiler to use
CC = gcc

# Define compiler flags
# -Wall: Enable all standard warnings
# -g: Include debugging information
CFLAGS = -Wall -g

# Define the include directories
# -I: Add directory to the list of directories to be searched for header files
INCLUDES = -I./atendimentos -I./clientes -I./controller -I./filas

# Define the source files
SRCS = main.c \
       atendimentos/atendimentos.c \
       clientes/clientes.c \
       controller/controller.c \
       filas/filas.c

# Define the object files (derived from source files)
OBJS = $(SRCS:.c=.o)

# Define the executable name
TARGET = programa

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
