#include <iostream>
#include <string>

enum Error
{
	NO_ERROR,
	COUNT_EXCEDED,
	TOO_FEW_ARGS
};

Error print_help()
{
	// TODO: create a pretty little help screen
	return NO_ERROR;
}

bool loop(int n)
{
	// TODO: memory intensive check for loops
	// first only check for 421 loop
	// eventually generalize for any loop
	if(n == 1)
	{
		std::cout << 1 << std::endl;
		return true;
	}
	else return false;
}

Error check_input(int c, char* args[], int& n)
{
	if(c < 2)
	{
		return TOO_FEW_ARGS;
	}
	for(int i = 1; i < c; i++)
	{
		// check command line arguments first
		if(args[i] == "-h") return print_help();
		else
		{
			// TODO: check for input to be integers and fail if it isn't
			// use try catch eventually
			n = std::stoi(std::string(args[i]));
		}
	}
	return NO_ERROR;
}

Error eval_num(int c, int n)
{
	// TODO: recursion could be memory intensive for large numbers if all numbers return to 421 loop 
	// as expected
	if(loop(n)) // check for 421 loop and print loop
		return NO_ERROR;	
	else if(c >= 100)
		return COUNT_EXCEDED; 
	else
	{
		// TODO: print to file instead of console
		std::cout << n << "\n";
		if(n % 2 == 0) // if n is even
		{
			eval_num(c, n / 2);
		}
		else // if n is odd
		{
			eval_num(c, 3 * n + 1);
		}
	}
	return NO_ERROR;
}

int main(int argc, char* argv[])
{
	int num = 0;
	Error err = check_input(argc, argv, num); // evaluate arguments and find the starting n
	err = eval_num(0, num); // begin recursive evaluation until a loop is found
	return static_cast<int>(err); // return with error code
}
