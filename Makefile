CC = cc
CFLAGS = -std=c99 -Wall -g -I include
LFLAGS = 
SRC_DIR = sources
FILES =  prompt doge_code doge_grammar parsing evaluation error_handling s_expressions q_expressions variables functions conditionals strings hand_rolled_parser
PLATFORM = $(shell uname)

ifeq ($(findstring Linux,$(PLATFORM)),Linux)
	LFLAGS += -ledit -lm
endif

ifeq ($(findstring Darwin,$(PLATFORM)),Darwin)
	LFLAGS += -ledit -lm
endif

ifeq ($(findstring MINGW,$(PLATFORM)),MINGW)
	LFLAGS += -lreadline
endif

all: $(FILES)

#$(FILES): % : $(SRC_DIR)/%.c $(SRC_DIR)/mpc.c
#	$(CC) $(CFLAGS) $^ $(LFLAGS) -o $@

$(FILES): % : $(SRC_DIR)/%.c $(SRC_DIR)/mpc.c
	$(CC) $(CFLAGS) $^ $(LFLAGS) -o $@


clean:
	rm -f $(FILES)
