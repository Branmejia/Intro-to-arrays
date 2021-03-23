//Brandon Mejia
//CPSC 120-02
//2021-03-22
//branmejia21@csu.fullerton.edu
//@branmejia
//
//Lab 06-02
//
//This finds the avg of the floats provided
//
#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <random>
//  Add the following header files algorithm, array, cstdlib,
// iostream, random

using namespace std;

/// The RandomNumberGenerator class is a wrapper around the Standard C++
/// Library's Mersenne Twister pseudo random number generator.
/// This class is complete and correct; please do not make any changes to it.
///
/// In lieu of directly working with the [Mersenne Twister
/// class]
/// (https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine),
/// this class serves as a lightweight wrapper around the necessary elements of
/// the library. The usage of this class is very simple and requires a
/// minimum and maximum value for initialization.
/// \code
/// int minimum_random_number = 1;
/// int maximum_random_number = 10;
/// RandomNumberGenerator my_random_number_generator{minimum_random_number,
/// maximum_random_number}; int random_number =
/// my_random_number_generator.next();
/// \endcode
class RandomNumberGenerator {
 private:
  /// A hardware entropy source (a device on your computer to give random bits)
  std::random_device rd;
  /// A sequence of random bits to seed the Mersenne Twister engine
  std::seed_seq seed;
  /// A Mersenne Twister engine
  std::mt19937 mt_engine;
  /// A uniform distribution; select numbers randomly in a uniform manner
  std::uniform_int_distribution<> uniform_dist;

 public:
  /// Constructor to the RandomNumberGenerator class
  ///
  /// The RandomNumberGenerator generates random integer numbers between
  /// \p minimum and \p maximum. The constructor initializes and prepares
  /// the engine. To generate a number use the <RandomNumberGenerator::next>()
  /// method.
  ///
  /// \param minimum The lowest value the random number generator will return
  /// \param maximum The largest value the random number generator will return
  RandomNumberGenerator(int minimum, int maximum)
      : seed{rd()}, mt_engine{rd()}, uniform_dist{minimum, maximum} {}

  /// Return a random number
  ///
  /// Returns a random integer number between the minimum and maximum set
  /// when the constructor was called.
  /// \sa RandomNumberGenerator::RandomNumberGenerator
  ///
  /// \returns An integer between the minimum and maximum set when
  /// the constructor was called
  auto next() -> int {
    int random_number = uniform_dist(mt_engine);
    // std::cout << "Debugging: The random number is " << random_number << "\n";
    return random_number;
  }
};

/// number_elements defines how large the C++ array will be. It must be global
/// so that it can be used in all the functions.
const int number_elements = 10;

/// ErrorMessage prints out \p message first and then prints the standard
/// message
/// \code
/// "There was an error. Exiting.\n".
/// \endcode
///
/// \param message The programmer defined string that specifies the current
/// error.
void ErrorMessage(const string& message) {
  cout << message;
  cout << "There was an error. Exiting.\n";
  //implement ErrorMessage
}

/// PrintArray print out the elements of \p the_array each on a line of
/// their own. _Must be done with a range-based for loop._
///
/// \code
/// array<int, number_elements> the_array{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
/// PrintArray(array);
/// \endcode
///
/// This above code will print:
/// \code
/// 1
/// 2
/// 3
/// 4
/// 5
/// 6
/// 7
/// 8
/// 9
/// 10
/// \endcode
///
/// \param the_array This is the array of integers created in the main function.
void PrintArray(const array<int, number_elements>& the_array) {
  for(const auto& element : the_array){
    cout << element << "\n";
  }
  // TODO: Implement the function such that it prints out each element of
  // the given array, one element per line.
  // You must use a range-for loop.
}

/// FillArray filles \p the_array with random numbers given by
/// \p random_number_generator. _Must be done with a range-based for loop._
///
/// The body of this function loops through each location of the \p the_array
/// and assigns it a random value.
///
/// \param the_array The array of integers created in the main function.
/// \param random_number_generator The random number generator created in
/// the main function.
/// \sa RandomNumberGenerator::next()
void FillArray(array<int, number_elements>& the_array,
               RandomNumberGenerator& random_number_generator) {
                 for(auto& element : the_array){
                   element = random_number_generator.next();
                 }

  // TODO: assign a random number to each element in the array using
  // random_number_generator.next().
  // You must use a range-for loop
}

/// CalculateAverage calculates the average (arithmetic mean) of all the
/// values stored in \p the_array. _Must be done with a range-based for loop._
///
/// The algorithm starts by delcaring and initializing an integer variable
/// which will represent the sum of all the values in \p the_array. Using
/// a loop, visit each element in \p the_array and sum them (accumulate)
/// into the integer variable. After the loop completes, calculate the average
/// by promoting the sum and the size of \p the_array to floats and find the
/// quotient.
///
/// \f[\bar{x} = \frac{1}{n}\sum_{i = 1}^{n} x_i\f]
///
/// \param the_array The array of integers created in the main function.
///
/// \returns The average (arithmetic mean) value in the array as a float
float CalculateAverage(const array<int, number_elements>& the_array) {
  float sum = 0;
    for(const auto& element : the_array){
      sum = sum + element;
    }
      float average = float(sum) / float(the_array.size());
      return average;
    }
  //for(auto the_array)

  // TODO: Calculate the average of the values contained in the array
  


/// Entry point to the find_min program
/// \remark Must have at least 2 arguments. The first argument is the minimum
/// number generated by the random number generator and the second argument
/// is the maximum number generated by the random number generator.
int main(int argc, char* argv[]) {
  if (argc < 3) {
    ErrorMessage(
        "Please provide two positive integers as the maximum and "
        "minimum for this exercise.");
    exit(1);
  }
  string argv_one_minimum = string(argv[1]);
  string argv_two_maximum = string(argv[2]);
  int minimum_number = 0;
  int maximum_number = 0;
  try{
    minimum_number = stoi(argv_one_minimum);
  }catch(const exception& e){
    ErrorMessage("The problem is arg 1");
    exit(1);
  }try{
    maximum_number = stoi(argv_two_maximum);
  }catch(const exception& e){
    ErrorMessage("The problem is arg 2");
    exit(1);
  }
  // TODO: convert argv_one_minimum and argv_two_maximum to integers and
  // assign to minimum_number and maximum_number.
  /*int maxtoint(argv_one_minimum, argv_two_maximum){
    int minimum_number = 0;
    int maximum_number = 0;
    minimum_number = stoi(argv[1]);
    maximum_number = stoi(argv[2]);
    return maximum_number&& maximum_number;
  }*/
  // TODO: Check to make sure minimum_number is less than maximum_number,
  // and that both of them are greater than zero. Otherwise, print an 
  // error message an exit.
    if(maximum_number <= minimum_number || maximum_number <= 0 || minimum_number <=0){
  ErrorMessage("min is greater than max");
  exit(1);
}
    
  RandomNumberGenerator rng(minimum_number, maximum_number);
  array<int, number_elements> random_numbers{};

  FillArray(random_numbers, rng);
  PrintArray(random_numbers);
  float average = CalculateAverage(random_numbers);
  cout << "The average value of the array is " << average << "\n";
  return 0;
}
