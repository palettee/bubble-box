GTEST_DIR=./googletest/googletest
GMOCK_DIR=./googletest/googlemock

SRC_ALL_FILES := $(wildcard ./src/*.cc)
SRC_FILES := $(filter-out ./src/main.cc, $(SRC_ALL_FILES))
OBJ_FILES := $(notdir $(patsubst %.cc,%.o,$(SRC_FILES)))

TEST_FILES := $(wildcard ./test/*.cc)
INCLUDE_DIR := ./inc
SOURCE_DIR := ./src
BUILD_DIR := ./build

clean:
	rm -rf $(BUILD_DIR)/*

all:
	g++ -g -o $(BUILD_DIR)/main $(SRC_ALL_FILES) -I ${INCLUDE_DIR}

unit_test: $(OBJ_FILES)
	g++ -g -o $(BUILD_DIR)/unit_test $(BUILD_DIR)/*.o $(TEST_FILES) -I $(INCLUDE_DIR) -isystem ${GTEST_DIR}/include -isystem ${GMOCK_DIR}/include -L${GTEST_DIR}/build -pthread -lgtest -L${GMOCK_DIR}/build -lgmock

$(OBJ_FILES): %.o : $(SOURCE_DIR)/%.cc
	g++ -g -c $< -o $(BUILD_DIR)/$@ -I $(INCLUDE_DIR)