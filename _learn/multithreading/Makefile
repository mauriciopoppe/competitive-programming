CXX ?= g++

# path #
SRC_PATH = src
BUILD_PATH = build
BIN_PATH = bin

# executable #
BIN_NAME =

# Find all source files in the source directory, sorted by most recently modified
SOURCES = $(shell find $(SRC_PATH) -name '*.cpp' | sort -k 1nr | cut -f2-)
SOURCES_LIB = $(wildcard $(SRC_PATH)/lib/*.cpp)
# Set the object file names, with the source directory stripped
# from the path, and the build path prepended in its place
OBJECTS = $(SOURCES:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)
OBJECTS_LIB = $(SOURCES_LIB:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)
# Set the dependency files that will be used to add header dependencies
DEPS = $(OBJECTS:.o=.d)

# flags #
COMPILE_FLAGS = -std=c++11 -Wall -Wextra -g
CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS)
INCLUDES = -I include/ -I /usr/local/include
# Space-separated pkg-config libraries used by this project
LIBS =

.PHONY: default_target
default_target: configure

.PHONY: configure
configure: dirs

.PHONY: dirs
dirs:
	@echo "Creating directories"
	@mkdir -p $(dir $(OBJECTS))
	@mkdir -p $(BIN_PATH)

.PHONY: clean
clean:
	@echo "Deleting directories"
	@$(RM) -r $(BUILD_PATH)
	@$(RM) -r $(BIN_PATH)

# Source file rules
# After the first compilation they will be joined with the rules from the
# dependency files to provide header dependencies
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.cpp
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@

# Creation of the executable
$(BIN_PATH)/threadpool: $(OBJECTS)
	@echo "Linking: $@"
	$(CXX) $(OBJECTS_LIB) $(BUILD_PATH)/cmd/threadpool.o -o $@ ${LIBS}
.PHONY: threadpool
threadpool: configure $(BIN_PATH)/threadpool

.PHONY: threadpool-test
threadpool-test: threadpool
	for i in {1..100}; do \
		printf "$$i "; \
		$(BIN_PATH)/threadpool > /dev/null; \
		done

# Creation of the executable
$(BIN_PATH)/semaphore: $(OBJECTS)
	@echo "Linking: $@"
	$(CXX) $(OBJECTS_LIB) $(BUILD_PATH)/cmd/semaphore.o -o $@ ${LIBS}
.PHONY: semaphore
semaphore: configure $(BIN_PATH)/semaphore

