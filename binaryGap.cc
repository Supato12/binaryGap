#include "pch.h"
#include <iostream>
#include <vector>
int Solution(int N)
{
	std::vector<int> binaryRepresentation {}; 
	int longestBinaryGap{};
	int binaryGap{};
	while (N) 
	{
		if (N & 1)  
			binaryRepresentation.push_back(1);
		else
			binaryRepresentation.push_back(0);
		N >>= 1; 
	}
	reverse(binaryRepresentation.begin(), binaryRepresentation.end()); 
	for (size_t i = 0; i < binaryRepresentation.size(); ++i) 
	{
		if (binaryRepresentation.at(i) == 0) 
		{
			binaryGap++;
		}
		else if (binaryRepresentation.at(i) == 1)
		{
			if(binaryGap >= longestBinaryGap)
				longestBinaryGap = binaryGap;
			binaryGap = 0;
		}
	}
	return longestBinaryGap;
}
int main()
{
	int N{};
	do
	{
		std::cout << "Pick decimal positive number to count binary gap(-1 to exit): ";
		std::cin >> N;
		std::cout << "Binary gap is: " << Solution(N) << '\n';
	} while (N =! -1);
	return 0;
}


