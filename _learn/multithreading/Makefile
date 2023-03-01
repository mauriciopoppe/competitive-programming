CXX ?= g++

# path #
SRC_PATH = src
BUILD_PATH = build
BIN_PATH = bin

PROGRAMS =

PROGRAMS += threadpool
threadpool_OBJS = $(BUILD_PATH)/lib/ThreadPool.o

PROGRAMS += semaphore
semaphore_OBJS = $(BUILD_PATH)/lib/Semaphore.o

PROGRAMS += two_thread_sync_with_semaphore
two_thread_sync_with_semaphore_OBJS = $(BUILD_PATH)/lib/Semaphore.o

# Find all source files in the source directory, sorted by most recently modified
SOURCES = $(shell find $(SRC_PATH) -name '*.cpp' | sort -k 1nr | cut -f2-)
# Set the object file names, with the source directory stripped
# from the path, and the build path prepended in its place
OBJECTS = $(SOURCES:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)
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

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.cpp
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@

-include $(DEPS)

define PROGRAM_template =
$$(BIN_PATH)/$(1): $$($(1)_OBJS) $$(BUILD_PATH)/cmd/$(1).o
	@echo "Linking: $$@"
	$$(CXX) $$^ -o $$@ $${LIBS}

.PHONY: $(1)
$(1): configure $$(BIN_PATH)/$(1)

.PHONY: $(1)-test
$(1)-test: $(1)
	for i in {1..100}; do \
		printf "$$$$i "; \
		$$(BIN_PATH)/$(1) > /dev/null; \
		done
endef

$(foreach prog,$(PROGRAMS),$(eval $(call PROGRAM_template,$(prog))))
