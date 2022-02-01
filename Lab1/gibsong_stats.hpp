/*
 * Author: Grace Gibson
 * Date Created: 2/1/2022
 * This header file contains statistical functions for 
 * calculating min/max, mean, and standard deviation of arrays. 
 * Also, there is a function that can estimate a histogram from input arguments. 
 */

namespace arrStats {
	class basicStats {
		public:
			//mini() calculates and returns the minimum value of an input array
			float mini(std::vector<float>);
			//max() calculates and returns the maximum value of an input array
			float  max(std::vector<float>);
			//mean() calculates and returns the mean value of an input array
			int mean(int in_arr[]);
			//stdev() calculates and returns the standard deviation of an input array
			int stdev(int in_arr[]);
			//hist()
	};
}
