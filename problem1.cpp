#include <cstdlib>
#include <iostream>
#include <random>
#include <sys/time.h>

#define MB     1024*1024
#define KB     1024
#define B      1

using namespace std;

std::random_device rd;  //seed
std::default_random_engine generator(rd()); //random number generator


double elapsedTime(timeval t1, timeval t2){
  double delta;
  delta = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
  delta += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
  return delta; 
}

void cacheAccess(int size){

  timeval t1, t2;
  int ii, iterid;
  
  //Initialize buffer 
  int buffer_size = size / B;           //cache unit size is Byte
  char* buffer = new char[buffer_size]; //Generate a dynamic array to hold data
  fill(buffer, buffer+buffer_size, 1);  //initialize buffer array with all 1s

  std::uniform_int_distribution<int> distribution(0, buffer_size - 1);  //distribution on which to apply the generator

  int access_time = 100000000;          //Make a large access number

  vector<int> random_index;
  for (int i; i < access_time; i++){
    int index = distribution(generator);
    random_index.push_back(index);      //push the element into a the random_index vector from the back
  }

  int total_data = 0;

  // start timer
  gettimeofday(&t1, NULL);
  for(int i = 0; i < access_time; i++){
    total_data += buffer[random_index[i]];
  }
  // stop timer
  gettimeofday(&t2, NULL);

  double time_span = elapsedTime(t1,t2);
  int buffer_size_kb = buffer_size / B;
  double throughput = double(total_data / B) / time_span; //throughput kbps

  delete[] buffer;  //free memory
}


// /////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////

// double DummyTest(void)
// {    
//   timeval t1, t2;
//   int ii, iterid;

//   // start timer
//   gettimeofday(&t1, NULL);

//   for(iterid=0;iterid<ITER;iterid++){
//     for(ii=0; ii< STEPS; ii++){
//       array[ii] += rand();
//     }
//   }

//   // stop timer
//   gettimeofday(&t2, NULL);
 
//   return elapsedTime(t1,t2);
// }



// /////////////////////////////////////////////////////////
// // Change this, including input parameters
// /////////////////////////////////////////////////////////

// double CacheNumLevelsTest(void)
// {    
//   double retval;

//   return retval; 
// }


// /////////////////////////////////////////////////////////
// // Change this, including input parameters
// /////////////////////////////////////////////////////////

// double CacheSizeTest(int stride)
// {    
  
//   //TODO: 1. Create a array with the size of L1 cache ITER*size 
//   //      2. Iterate over the buffer to load all data into cache
//   //      3. 
  
  
//   timeval t1, t2;

//   for (int i = 0; i < ITER ; i++){
//     // start timer
//     gettimeofday(&t1, NULL);
//     for (int j = 0; j < STEPS; j = j + (stride*Byte)){ //use different stride in loop, strides shows cache block size in each way
//       array[(j * 16) % sizeof(array)]++;
//     }
//     // stop timer
//     gettimeofday(&t2, NULL);
//     printf("ITER num: %d, size cache: %d, stride: %d, access time: %f\n", i, STEPS, stride, elapsedTime(t1, t2));
//   }

//   return 0;
// }


// /////////////////////////////////////////////////////////
// // Change this, including input parameters
// /////////////////////////////////////////////////////////

// double LineSizeTest(void)
// {    
//   double retval;

//   return retval; 
// }


// /////////////////////////////////////////////////////////
// // Change this, including input parameters
// /////////////////////////////////////////////////////////

// double MemoryTimingTest(void)
// {    
//   double retval;

//   return retval; 
// }



// /////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////

// int main(){
  
//   cout << "\nStarting DummyTest:" << "\n";
//   cout << "Test took " << DummyTest()/1000.0 << " seconds\n";

//   int stride = 64; //skip amount of memory before next access

//   printf("Start CacheSizeTest\n");
//   CacheSizeTest(stride);

//   // Add your code here, and comment above

//   cout << "\n";
// }

// /////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////
