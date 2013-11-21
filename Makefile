TARGET := CPI
CC := g++
HDRS := CP.h
SRCS := main.cpp CP.cpp
OBJS := $(SRCS:.cpp=.o)
CXXFLAGS := -std=c++11
.SUFFIXES: .o .cpp
$(TARGET) : $(OBJS)
	$(CC) -Wall -o $@ $(OBJS)

$(OBJS) : $(HDRS)

.o : .cpp
	$(CC) -Wall $(CXXFLAGS) $@ -a $<
.PHONY: run clean

run:
	make
	./$(TARGET)

clean:
	-rm *.o
	-rm $(TARGET)

