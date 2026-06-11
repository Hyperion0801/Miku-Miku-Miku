CXX = g++

CXXFLAGS = -Wall -Wextra -Oz -Iinclude

LDFLAGS = 

DROPPER_TARGET = build/dropper
INIT_TARGET = build/init
PAYLOAD_TARGET = build/payload
BUNDLED_TARGET = build/mikumiku.miku
TARGET_DIRECTORY = build/

DROPPER_SRCS = src/dropper.cpp
INIT_SRCS = src/init.cpp
PAYLOAD_SRCS = src/payload.cpp
DROPPER_OBJS = src/dropper.o
INIT_OBJS = src/init.o
PAYLOAD_OBJS = src/payload.o

all: $(DROPPER_TARGET) $(INIT_TARGET) $(PAYLOAD_TARGET) $(BUNDLED_TARGET)

$(DROPPER_TARGET): $(DROPPER_OBJS)
	mkdir -pv build
	$(CXX) $(CXXFLAGS) -o $(DROPPER_TARGET) $(DROPPER_OBJS) $(LDFLAGS)

$(INIT_TARGET): $(INIT_OBJS)
	mkdir -pv build
	$(CXX) $(CXXFLAGS) -o $(INIT_TARGET) $(INIT_OBJS) $(LDFLAGS)

$(PAYLOAD_TARGET): $(PAYLOAD_OBJS)
	mkdir -pv build
	$(CXX) $(CXXFLAGS) -o $(PAYLOAD_TARGET) $(PAYLOAD_OBJS) $(LDFLAGS)

$(BUNDLED_TARGET): $(DROPPER_TARGET) $(INIT_TARGET) $(PAYLOAD_TARGET) 
	mkdir -pv build
	cp $(DROPPER_TARGET) $@
	tar cf build/assets.tar $(INIT_TARGET) $(PAYLOAD_TARGET) src/downloader.sh
	cat build/assets.tar >> $@

build/%.o: src/%.cpp
	mkdir -pv build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(DROPPER_TARGET) $(INIT_TARGET) $(PAYLOAD_TARGET) $(DROPPER_OBJS) $(PAYLOAD_OBJS) $(INIT_OBJS) $(BUNDLED_TARGET) build/assets.tar
