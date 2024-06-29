SRC = list.cpp todo.cpp
OBJ = $(SRC:%.cpp=%.o)

CXXFLAGS = -ggdb3 -O0

todo: $(OBJ)
	g++ $(OBJ) -o $@

%.o: %.cpp list.h
	g++ $(CXXFLAGS) -c $< -o $@

info:
	@echo SRC: $(SRC)
	@echo OBJ: $(OBJ)
