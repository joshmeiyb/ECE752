//TODO: fix the bug when having multiple cache accesses

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

void cacheAccess(int size){ //input size is *KB

  // printf("\nCache access started, input test size is %dB\n", size);

  timeval t1, t2;
  int ii, iterid;
  
  //Initialize buffer 
  // int buffer_size = size / B;           // Cache unit size is Byte
  // printf("DEBUG, size of char is: %ld\n", sizeof(char));
  // int buffer_size = size;
  // printf("DEBUG, buffer_size value is %d\n", buffer_size);

  int* buffer = new int[size / B]; // Generate a dynamic array to hold data
  // std::vector<char> buffer(size / B);

  // for(int i = 0; i < (size / B); i++){
  //   printf("DEBUG: Buffer: %d\n", buffer[i]);
  // }
  // printf("DEBUG: Buffer memory is initialized\n");
  std::fill(buffer, buffer+(size / B), 1);  // Initialize buffer array with all 1
  // printf("DEBUG: Buffer memory is initialized with all 1\n");
  // int count = 0;
  // for(int i = 0; i < (size / B); i++){
  // printf("DEBUG: Buffer initialized: %d\n", buffer[i]);
  //   // count++;
  // }
  // printf("DEBUG: buffer element count: %d\n\n", count);
    

  std::uniform_int_distribution<int> distribution(0, (size / B) - 1);  // Distribution on which to apply the generator

  int access_time = 99999999;          // Make a large access number

  vector<int> random_index;             // Index vector to access random place in buffer
  for (int i; i < access_time; i++){
    int index = distribution(generator);
    // printf("index = %d\n", index);
    random_index.push_back(index);      // Push the element into a the random_index vector from the back
  }
  // printf("DEBUG: Random index is generated, size of \n");


  int total_data = 0;
  // start timer
  gettimeofday(&t1, NULL);
  for(int i = 0; i < access_time; i++){
    // printf("DEBUG: random_index[%d] = %d\n", i, random_index[i]);
    total_data += buffer[random_index[i]];  //total_data array increment 1 byte by each access
  }
  // for(int i = 0; i < size; i++){
  //   total_data += buffer[i];  //total_data array increment 1 byte by each access
  // }
  // stop timer
  gettimeofday(&t2, NULL);
  // printf("DEBUG: time is captured!\n");
  // printf("DEBUG: total data = %d\n", total_data);
  
  // printf("DEBUG, random_index is filled!\n");
  // for(int i = 0; i < (size / B); i++){
  //   printf("DEBUG: Buffer is filled with random data from random index: %d\n", buffer[i]);
  // }

  double time_span = elapsedTime(t1,t2);
  double throughput = double(total_data / KB) / time_span; //throughput kbps
  printf("Buffer size is %d KB, throughput is %f kbps\n", (size / KB), throughput);
  // printf("Buffer memory size is %ldB\n", sizeof(buffer));

  delete[] buffer;  //free memory
  
  // for(int i = 0; i < (size / B); i++){
  //   printf("DEBUG: Buffer: %d\n", buffer[i]);
  // }
  // printf("Buffer memory is freed!\n");
}

void cacheSize_test(){
  // vector<int> sizes{ 1*KB, 2*KB, 4*KB, 8*KB, 16*KB, 32*KB, 64*KB, 128*KB, 192*KB, 256*KB, 384*KB, 512*KB, 1024*KB, 2048*KB, 3072*KB, 4096*KB, 6144*KB, 8192*KB };

  // for(auto size : sizes){
  //   cacheAccess(size);
  // }
  // cacheAccess(1*KB);
  // cacheAccess(2*KB);
  // cacheAccess(4*KB);
  // cacheAccess(8*KB);
  // cacheAccess(16*KB);
  // cacheAccess(32*KB);
  // cacheAccess(64*KB);
  cacheAccess(12*MB);
}

int main(int argc, char **argv){  // equivalent expression is (int argc, char* argv[])

  cacheSize_test();

  return 0;
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
