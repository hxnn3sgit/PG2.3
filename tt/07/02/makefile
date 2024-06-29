CXX = g++

CXXFLAGS = -Wall -Wextra -lpng -std=c++17

TARGET = numbers_complex

MANDELBROT_TARGET = mandelbrot

SRCS = complex-number.cpp color.cpp main.cpp

MANDELBROT_SRCS = complex-number.cpp mandelbrot.cpp

OBJS = $(SRCS:.cpp=.o)

MANDELBROT_OBJS = $(MANDELBROT_SRCS:.cpp=.o)

all: $(TARGET) $(MANDELBROT_TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(MANDELBROT_TARGET): $(MANDELBROT_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^



info:
	@echo SRC: $(SRC)
	@echo OBJ: $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $:(TARGET) $(OBJS)
