#
# Kazan Makefile
# 
# Makefile for kazan
#

# Include config file
include conf.mk

# Dicate phony and all compile
.PHONY: all clean
all: $(NAME)

# Compile executable
kazan: ./src/*.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIB) $(OFLAGS) -o $@ $^
	
# Install executable
install: ./$(NAME)
	cp -f $^ $(BINPATH)

# Uninstall executable
uninstall:
	-rm $(BINPATH)/$(NAME)
	
# Clean File Mess
clean:
	-rm -f *.out *.o ./$(NAME)
