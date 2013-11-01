#include "ReactionSystem.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework
#include <cmath>

#include <boost/numeric/odeint.hpp>

using namespace reactor;

class WrapReactionSystemForODEINT
{
public:
	ReactionSystem &system;
	WrapReactionSystemForODEINT(ReactionSystem & system):system(system){}
	void operator() ( const std::vector<double> &x , std::vector<double> &dxdt , const double)
    {
        system.GetRatesGivenConcentrations(x,dxdt);
    }
};

class SimpleDecaySystemTest: public ::testing::Test {
protected:
	ReactionSystem simple_decay_system;
	Reaction &decay;
	Species &original;
	Species &decay_product;

	SimpleDecaySystemTest():
		simple_decay_system(),
		decay(simple_decay_system.NewReaction(2.0)),
		original(simple_decay_system.NewSpecies("Original")), 
		decay_product(simple_decay_system.NewSpecies("Product"))
	{
		decay.AddReactant(original);
		decay.AddProduct(decay_product);

		original.SetConcentration(100.0);
		decay_product.SetConcentration(0.0);
	};
};

void observe_integration(const std::vector<double> &concentrations , const double time){
	std::cout << time << ": [" << std::flush;
	for (unsigned int i=0; i<concentrations.size();i++){
		std::cout << concentrations[i] <<  ", " << std::flush;
	}
	std::cout << "]" << std::endl;
}

TEST_F(SimpleDecaySystemTest, ODEINTCanIntegrate) { // First argument is test group, second is test name
	std::vector<double> concentrations=simple_decay_system.GetConcentrations();
	WrapReactionSystemForODEINT wrapper(simple_decay_system);
	int step_count=boost::numeric::odeint::integrate(wrapper, concentrations , 0.0, 1.5, 0.1, observe_integration);
	// the concentration of the reactant should be
	// initial* exp(-time*rate)
	// and of the product
	// initial* (1-exp(-time*rate))

	EXPECT_NE(step_count,0);
	EXPECT_NEAR(100*std::exp(-2.0*1.5),concentrations[0],0.001);
	EXPECT_NEAR(100-100*std::exp(-2.0*1.5),concentrations[1],0.001);
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}