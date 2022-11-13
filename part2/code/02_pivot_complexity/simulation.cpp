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


bool brute_force(vecI &nums)
{
    //Solving the pivot problem

    for(int i=0;i<nums.size(); i++)
    {
        auto left = 0;      //left sum
        auto right = 0;     // right sum

        for(int j = 0; j<i; j++)
            left += nums[i];

        for(int j=i+1; j<nums.size(); j++)
            right += nums[i];

        if( left == right)
            return i;
    }

    return false;

}

bool smart_search(vecI & nums)
{
    //Same program but using set search
    auto right = 0;
    for(int i= 0; i<nums.size(); i++)
        right += nums[i];

    auto left = 0; 

    for(int i=0; i<nums.size(); i++)
    {
        right -= nums[i];

        if(left == right)
            return i;

        left += nums[i];
    }

    return false;
}
//function to measure the time consumed by the function F
double measure_time( bool(*F)(vecI&), vecI & nums)
{

      //timing the first call
      auto start = chrono::high_resolution_clock::now();
      F(nums);
      auto end = chrono::high_resolution_clock::now();
      chrono::duration<double, std::milli> diff(end - start);
      return diff.count();
}

int main(int argc, char *argv[])
{

  //simulation over the size of the array
  double time_1 = 0;
  double time_2 = 0;
  int repeat = 20;

  //Creating an out .csv
  ofstream out("results.csv");

  out<<setw(10)<<"Size"<<setw(20)<<"Brute Force"<<setw(20)<<"Smart"<<endl;
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

         time_1 += measure_time(&brute_force, nums);
         time_2 += measure_time(&smart_search,  nums);
      }
      time_1 /= repeat;
      time_2 /= repeat;
      

    //Printing the result
    out<<setw(10)<<size<<setw(20)<<time_1<<setw(20)<<time_2<<endl;

  }

  out.close();

  return 0;
}
