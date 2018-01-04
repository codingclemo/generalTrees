ifeq ($(OS),Windows_NT)
  EXEEXT = .exe
else
  EXEEXT =
endif

TARGET = generalTrees$(EXEEXT)

# compiler settings
CC      = g++ -std=c++14
CCFLAGS = -g -pedantic -Wall -Wextra -ggdb

# linker/loader settings
LD      = g++
LDFLAGS =  # link all libraries statically

# names of all .c and .o files
CFILES  = $(wildcard *.cpp)  # $(..) works for gmake only
OFILES  = $(CFILES:.cpp=.o)  # $(..) works for gmake only

# name of file containing all generated dependencies
DEPENDFILE = .depend

# rule how to compile .o files from .c files
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

.PHONY: all depend clean

all: $(TARGET)

# main target: prg is the name of the executable to build
$(TARGET): $(OFILES)
	$(LD) -o $@ $(OFILES) $(LDFLAGS)

# clean up directory
clean:
	$(RM) $(TARGET) *.o core *.bak *~

# create dependencies using gcc -MM
depend:
	$(CC) $(CCFLAGS) -MM $(CFILES) > $(DEPENDFILE)

-include $(DEPENDFILE)

