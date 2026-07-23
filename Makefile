CXX = g++

CXXFLAGS = -Wall -Wextra -Os -Iinclude -lSDL3 -lSDL3_image -lSDL3_mixer

LDFLAGS = 

DROPPER_TARGET = build/dropper/dropper
INIT_TARGET = build/init/init
PAYLOAD_TARGET = build/payload/payload
BUNDLED_TARGET = build/mikumiku.miku
TARGET_DIRECTORY = build/

DROPPER_SRCS = $(wildcard src/dropper/*.cpp)
INIT_SRCS = $(wildcard src/init/*.cpp)
PAYLOAD_SRCS = $(wildcard src/payload/*.cpp)
DROPPER_OBJS = $(patsubst src/dropper/%.cpp,build/dropper/%.o,$(DROPPER_SRCS))
INIT_OBJS = $(patsubst src/init/%.cpp,build/init/%.o,$(INIT_SRCS))
PAYLOAD_OBJS = $(patsubst src/payload/%.cpp,build/payload/%.o,$(PAYLOAD_SRCS))

all: $(DROPPER_TARGET) $(INIT_TARGET) $(PAYLOAD_TARGET) $(BUNDLED_TARGET)

build:
	mkdir -p build

$(DROPPER_TARGET): $(DROPPER_OBJS) | build
	mkdir -pv build/dropper
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(INIT_TARGET): $(INIT_OBJS) | build
	mkdir -pv build/init
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(PAYLOAD_TARGET): $(PAYLOAD_OBJS) | build
	mkdir -pv build/payload
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(BUNDLED_TARGET): $(DROPPER_TARGET) $(INIT_TARGET) $(PAYLOAD_TARGET) 
	mkdir -pv build/
	cp $(DROPPER_TARGET) $@
	tar cf build/assets.tar -C build/init init -C ../payload payload -C ../../assets song.ogx -C . miku.png
	cat build/assets.tar >> $@

build/dropper/%.o: src/dropper/%.cpp | build
	mkdir -pv build/dropper
	$(CXX) $(CXXFLAGS) -c $< -o $@
build/init/%.o: src/init/%.cpp | build
	mkdir -pv build/init
	$(CXX) $(CXXFLAGS) -c $< -o $@
build/payload/%.o: src/payload/%.cpp | build
	mkdir -pv build/payload
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(DROPPER_TARGET) $(INIT_TARGET) $(PAYLOAD_TARGET) $(DROPPER_OBJS) $(PAYLOAD_OBJS) $(INIT_OBJS) $(BUNDLED_TARGET) build/assets.tar
