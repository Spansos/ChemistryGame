CC     := g++
# CFLAGS := -g -Wall -Wpedantic -Wextra -Og -Iinclude
CFLAGS := -g -Wall -Wextra -Og -Iinclude

# cpp and header files from own project
# 2 (or 1?) levels of recursion
CPP_FILES := $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
CFLAGS += -Iinclude

# packages from package manager
PACKAGES := sfml-all
PKG_LIBS := $(shell pkg-config --libs $(PACKAGES))
CFLAGS   += $(shell pkg-config --cflags $(PACKAGES))

# box2d
PKG_LIBS += box2d/build/src/libbox2d.a
CFLAGS += -Ibox2d/include

# obj & .h(pp) files. decided by cpp files & include folders, so last
HEADERS   := $(shell find $(INCLUDES) -name "*.h" -o -name "*.hpp")
OBJ_FILES := $(patsubst %.cpp,obj/%.o,$(CPP_FILES))

.PHONY: clean run

all: bin/main.out

run: bin/main.out
	./bin/main.out

clean:
	rm obj/* -rf
	rm bin/* -rf

# build box2d
box2d/build/src/libbox2d.a:
	(cd box2d && ./build.sh)

obj/%.o: %.cpp $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bin/main.out: $(OBJ_FILES) $(PKG_LIBS)
	$(CC) $(CFLAGS) $^ -o $@