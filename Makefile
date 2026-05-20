CXX = g++

CXXFLAGS = -Wall -Wextra -O2 -Iinclude

LDFLAGS = 

DROPPER_TARGET = build/dropper
INIT_TARGET = build/init

DROPPER_SRCS = src/dropper.cpp
INIT_SRCS = src/init.cpp
DROPPER_OBJS = src/dropper.o
INIT_OBJS = src/init.o

all: $(DROPPER_TARGET) $(INIT_TARGET)

$(DROPPER_TARGET): $(DROPPER_OBJS)
	mkdir -pv build
	$(CXX) $(CXXFLAGS) -o $(DROPPER_TARGET) $(DROPPER_OBJS) $(LDFLAGS)

$(INIT_TARGET): $(INIT_OBJS)
	mkdir -pv build
	$(CXX) $(CXXFLAGS) -o $(INIT_TARGET) $(INIT_OBJS) $(LDFLAGS)

build/%.o: src/%.cpp
	mkdir -pv build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(DROPPER_TARGET) $(INIT_TARGET) $(OBJS)

run: all
	./$(TARGET)
