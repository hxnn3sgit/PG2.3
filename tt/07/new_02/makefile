CXX = g++

CXXFLAGS = -Wall -Wextra -lpng -std=c++17

TARGET = numbers_complex

SRCS = rot_neu.cpp color.cpp 

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

info:
	@echo SRC: $(SRC)
	@echo OBJ: $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $:(TARGET) $(OBJS)
