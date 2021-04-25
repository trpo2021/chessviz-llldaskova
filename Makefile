APP_NAME = chessviz
LIB_NAME = libchessviz

CFLAGS = -Wall -Werror
CPPFLAGS = -MMD -I src
CPPFLAGS_TEST = -I thirdparty -I src -MP -MMD
LDFLAGS =
LDLIBS = -lm
CC = g++

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src


APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a

SRC_EXT = cpp

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d)

.PHONY: all
all: $(APP_PATH)

-include $(DEPS)



$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.$(SRC_EXT)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) $(APP_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
test: $(APP_PATH_TEST)

-include $(DEPS_TEST)

$(APP_PATH_TEST): $(APP_OBJECTS_TEST) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS_TEST) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS_TEST) $< -o $@ $(LDLIBS)

