#include "ReactionSystem.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

using namespace reactor;

class ReactionSystemTest: public ::testing::Test {
protected:
	ReactionSystem emptyReactionSystem;
	Reaction forward;
	Reaction reverse;
	Species calcium;
	Species carbon;
	Species oxygen;
	Species calcium_carbonate;

	ReactionSystemTest():
		emptyReactionSystem(),
		forward(9.0),
		reverse(11.0), 
		calcium("Ca"),
		oxygen("O"),
		carbon("C"),
		calcium_carbonate("CaCO3")
	{
		forward.AddReactant(calcium);
		forward.AddReactant(carbon);
		forward.AddReactant(oxygen);
		forward.AddProduct(calcium_carbonate);

		reverse.AddProduct(calcium);
		reverse.AddProduct(carbon);
		reverse.AddProduct(oxygen);
		reverse.AddReactant(calcium_carbonate);

		calcium.SetConcentration(2.0);
		carbon.SetConcentration(3.0);
		oxygen.SetConcentration(5.0);
		calcium_carbonate.SetConcentration(7.0);
	};
};

TEST_F(ReactionSystemTest, ReactionSystemCanHaveReaction) { // First argument is test group, second is test name
  emptyReactionSystem.AddReaction(forward);
  EXPECT_EQ(1, emptyReactionSystem.GetReactions().size());
  EXPECT_EQ(&forward, emptyReactionSystem.GetReactions()[0]);
}

TEST_F(ReactionSystemTest, ReactionSystemCanHaveMultipleReactions) { 
  emptyReactionSystem.AddReaction(forward);
  emptyReactionSystem.AddReaction(reverse);
  EXPECT_EQ(2, emptyReactionSystem.GetReactions().size());
  EXPECT_EQ(&forward, emptyReactionSystem.GetReactions()[0]);
  EXPECT_EQ(&reverse, emptyReactionSystem.GetReactions()[1]);
}

TEST_F(ReactionSystemTest, ReactionSystemCanAddSpecies){
	emptyReactionSystem.AddSpecies(calcium);
	emptyReactionSystem.AddSpecies(oxygen);
	ASSERT_EQ(2,emptyReactionSystem.GetSpecies().size());
	EXPECT_EQ(&calcium,emptyReactionSystem.GetSpecies()[0]);
	EXPECT_EQ(&oxygen,emptyReactionSystem.GetSpecies()[1]);

}

TEST_F(ReactionSystemTest, ReactionSystemSpeciesCanBeModifiedByReference){
	emptyReactionSystem.AddSpecies(calcium);
	EXPECT_EQ(2.0,emptyReactionSystem.GetSpecies()[0]->GetConcentration());
	calcium.SetConcentration(11.0);
	EXPECT_EQ(11.0,emptyReactionSystem.GetSpecies()[0]->GetConcentration());
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}