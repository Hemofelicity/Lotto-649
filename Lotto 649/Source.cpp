#include <Windows.h>
#include <stdint.h>
#include <cmath>
#include <random>
#include <iostream>
#include <vector>

int main()
{
	uint32_t numbers[6]{ NULL };
		
	std::uniform_int_distribution<int> distribution(1, 49);

	while ((numbers[0] == 0) ||
		(numbers[1] == 0) ||
		(numbers[2] == 0) ||
		(numbers[3] == 0) ||
		(numbers[4] == 0) ||
		(numbers[5] == 0))
	{
		std::mt19937 generator(time(NULL));

		uint32_t val = distribution(generator);

		if ((numbers[0] != val) &&
			(numbers[1] != val) &&
			(numbers[2] != val) &&
			(numbers[3] != val) &&
			(numbers[4] != val) &&
			(numbers[5] != val))
		{
			if (numbers[0] == 0)
				numbers[0] = val;
			else if (numbers[1] == 0)
				numbers[1] = val;
			else if (numbers[2] == 0)
				numbers[2] = val;
			else if (numbers[3] == 0)
				numbers[3] = val;
			else if (numbers[4] == 0)
				numbers[4] = val;
			else if (numbers[5] == 0)
				numbers[5] = val;

		}

		for (uint32_t i = 0; i < 6; i++)
		{
			for (uint32_t j = i + 1; j < 6; j++)
			{
				uint32_t swap = 0;

				if (numbers[i] > numbers[j])
				{
					swap = numbers[i];

					numbers[i] = numbers[j];

					numbers[j] = swap;

				}

			}

		}

	}

	for (uint32_t i = 0; i < 6; i++)
	{
		std::cout << numbers[i] << "; ";

	}

	std::cout << std::endl;
	 
	return 0;
}