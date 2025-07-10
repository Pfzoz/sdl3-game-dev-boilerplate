BUILD_DIR=build
BUILD_FLAGS="-DCMAKE_EXPORT_COMPILE_COMMANDS=ON"

run:
	cmake -S ./ -B build/ $(BUILD_FLAGS) && cmake --build build  && ./build/app

run_debug:
	cmake -S ./ -B $(BUILD_DIR) $(BUILD_FLAGS) -DCMAKE_BUILD_TYPE=Debug && cmake --build $(BUILD_DIR)
	SDL_DEBUG=1 ./$(BUILD_DIR)/app

build:
	cmake -S ./ -B build/ $(BUILD_FLAGS) && cmake --build build
	cp $(BUILD_DIR)/compile_commands.json .

clean:
	rm -rf build/
