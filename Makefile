CFLAGS = -std=c++17 -Iext/SDL/include -Iext/stbimage -Iext/glad/include
LDFLAGS = `pkg-config --static --libs glfw3` -lGL -lassimp -lSDL2 -lSDL2_image -lpthread

pbrrenderer-base: pbrrenderer/*.cpp
	$(CXX) $(CFLAGS) -o "bin/Linux/x64/pbr" pbrrenderer/*.cpp ext/glad/src/glad.c $(LDFLAGS)

.PHONY: run debug clean

run: pbrrenderer-base
	./RUN.sh

debug: pbrrenderer-base
	./DEBUG.sh

clean:
	rm -f "pbr" "bin/Linux/x64/pbr"