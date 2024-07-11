CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = array

SRCS = dyn_arr.cpp main.cpp

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
	rm -f $(TARGET) $(OBJS)
