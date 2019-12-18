CFLAGS = -std=c++17 -Wall -Iext/SDL/include -Iext/stbimage -Iext/glad/include
LDFLAGS = `pkg-config --static --libs glfw3` -lGL -lassimp -lSDL2 -lSDL2_image -lpthread

SOURCES = $(wildcard pbrrenderer/*.cpp) $(wildcard pbrrenderer/*/*.cpp) $(wildcard pbrrenderer/*/*/*.cpp) $(wildcard pbrrenderer/*/*/*/*.cpp) ext/glad/src/glad.c

pbrrenderer-base: $(SOURCES)
	@$(CXX) $(CFLAGS) -o "bin/Linux/x64/pbr" $(SOURCES) $(LDFLAGS)

.PHONY: run debug clean

run: pbrrenderer-base
	./RUN.sh

debug: pbrrenderer-base
	./DEBUG.sh

clean:
	rm -f "pbr" "bin/Linux/x64/pbr"