#include "ReactionSystem.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

using namespace reactor;

class ReactionSystemTest: public ::testing::Test {
protected:
	ReactionSystem myReactionSystem;
	

	ReactionSystemTest():
		myReactionSystem()
	{
	};
};

TEST_F(ReactionSystemTest, ReactionSystemCanExist) { 
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}