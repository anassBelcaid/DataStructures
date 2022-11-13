#include <iostream>
#include <ratio>
#include <string>
#include <set>
#include <vector>
#include <random>
#include <iomanip>
#include <chrono>
#include <fstream>

using namespace std;


//Alias
using vecI = vector<int>;


//Creating a random engine
default_random_engine e1;

//Uniform integers between 1 and 100
uniform_int_distribution<int> D(1, 100);


vecI randomArray(int size)
{
    //Create a random array with size [size] chosen from a random 
    //Distribution D
    vecI out;
    while(size-->0)
        out.push_back(D(e1));

    return out;
}


bool brute_force(vecI &nums, int target)
{
    for(int i=0; i<nums.size()-1; i++)
    {
        for(int j=i+1; j<nums.size(); j++)
            if( nums[i] + nums[j] == target)
                return true;
    }

    return false;

}

bool set_search(vecI & nums, int target)
{
    //Same program but using set search
    set<int> cache(nums.begin(), nums.end());

    for(auto v: nums)
        if( cache.find( target - v) != cache.end() )
            return true;

    return false;
}
//function to measure the time consumed by the function F
double measure_time( bool(*F)(vecI&, int), vecI & nums, int target)
{

      //timing the first call
      auto start = chrono::high_resolution_clock::now();
      F(nums, target);
      auto end = chrono::high_resolution_clock::now();
      chrono::duration<double, std::milli> diff(end - start);
      return diff.count();
}

int main(int argc, char *argv[])
{

  //simulation over the size of the array
  double time_1 = 0;
  double time_2 = 0;
  int repeat = 30;

  //Creating an out .csv
  ofstream out("results.csv");

  out<<setw(10)<<"Size"<<setw(20)<<"Brute Force"<<setw(20)<<"Using sets"<<endl;
  for(int size = 100; size < 2E4; size *= 2)
  {
      time_1 = 0;
      time_2 = 0;
      for(int r = 0; r<repeat; r++)
      {

          //Getting the array
          auto nums = randomArray(size);

          //Taget
          auto target = 300;

         time_1 += measure_time(&brute_force, nums, target);
         time_2 += measure_time(&set_search,  nums, target);
      }
      time_1 /= repeat;
      time_2 /= repeat;
      

    //Printing the result
    out<<setw(10)<<size<<setw(20)<<time_1<<setw(20)<<time_2<<endl;

  }

  out.close();

  return 0;
}
