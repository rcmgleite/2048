.DEFAULT_GOAL := all

INCLUDE_PATH="./src/include"
CXX = g++

CPP_FILES := $(shell find src -name '*.cpp')
O_FILES := $(CPP_FILES:.cpp=.o)
CPP_DEPS := $(CPP_FILES:.cpp=.d)

COMPILE_FLAGS = -std=c++11
LD_FLAGS = -pthread

ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif

# Compile all files from src/source
src/source/%.o: src/source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++'
	$(CXX) $(COMPILE_FLAGS) -I$(INCLUDE_PATH) -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

# All Target
all: game

# game Target
game: $(O_FILES)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	$(CXX) $(COMPILE_FLAGS) $(LD_FLAGS) -o "game" $(O_FILES)
	@echo 'Finished building target: $@'
	@echo ' '

# Clean Target
clean:
	-$(RM) $(O_FILES) $(CPP_DEPS) game
	-@echo ' '

.PHONY: all clean
