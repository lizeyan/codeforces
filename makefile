T = hiho
CXX = g++
CXX_FLAGS = -Wall -O2
CXX_FLAGS_DEBUG = -Wall -g
OUTPUT_DIR = output

all: directory $(OUTPUT_DIR)/$(T)

$(OUTPUT_DIR)/$(T): $(T).cpp
	$(CXX) $^ -o $@ ${CXX_FLAGS}

$(OUTPUT_DIR)/$(T)_DEBUG: $(T).cpp
	$(CXX) $^ -o $@ ${CXX_FLAGS_DEBUG}

clean:
	rm -rf $(OUTPUT_DIR)

run: directory $(OUTPUT_DIR)/$(T)
	./$(OUTPUT_DIR)/$(T)

directory:
	mkdir -p $(OUTPUT_DIR)

debug: directory $(OUTPUT_DIR)/$(T)_DEBUG
	gdb $(OUTPUT_DIR)/$(T)_DEBUG

