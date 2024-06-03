TEST_DIR="$PWD/tests"
TEST_MAIN="$TEST_DIR/tests.cpp"
TEST_HEADER="$TEST_DIR/tests.hpp"

function newTestFile() {
    local TEST_TITLE=$1
    local TEST_FILE=$2
    local TEST_PATH=$3
    echo "Generating test file: $TEST_FILE"
    echo "
#include <gtest/gtest.h>

TEST($TEST_TITLE"Test", TestDescription)
{
    EXPECT_TRUE(true);
}
" >>$TEST_PATH
    echo '#include "'$TEST_FILE'"' >>$TEST_HEADER
}
function newTestCase() {
    read -p "Enter name of new test case: " TMP
    local TEST_TITLE=${TMP:-"Sample"}
    local TEST_FILE=$TEST_TITLE"Tests.cpp"
    local TEST_PATH=$TEST_DIR"/"$TEST_FILE
    if test -f $TEST_PATH; then
        echo $TEST_PATH "already exists"
    else
        newTestFile $TEST_TITLE $TEST_FILE $TEST_PATH
    fi

}
newTestCase