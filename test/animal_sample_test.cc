#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "animal_sample.h"

using testing::Return;

class AnimalMock: public Animal {
    public:
     MOCK_METHOD1(walk, int(int steps));
};

TEST(Animal_test, trainer_test) {
    Trainer trainer;
    AnimalMock mock;

    EXPECT_CALL(mock, walk(4))
        .Times(1)
        .WillOnce(Return(8));

    int result = trainer.orderWalk(&mock);
    EXPECT_EQ(8, result);
}