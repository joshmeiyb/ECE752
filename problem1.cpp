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

void cacheAccess(int size){

  timeval t1, t2;
  int ii, iterid;
  
  //Initialize buffer 

  int* buffer = new int[size / B]; // Generate a dynamic array to hold data
  std::fill(buffer, buffer+(size / B), 1);  // Initialize buffer array with all 1

  std::uniform_int_distribution<int> distribution(0, (size / B) - 1);  // Distribution on which to apply the generator

  int access_time = 99999999;          // Make a large access number

  vector<int> random_index;             // Index vector to access random place in buffer
  for (int i; i < access_time; i++){
    int index = distribution(generator);
    random_index.push_back(index);      // Push the element into a the random_index vector from the back
  }

  int total_data = 0;
  // start timer
  gettimeofday(&t1, NULL);
  for(int i = 0; i < access_time; i++){
    total_data += buffer[random_index[i]];  //total_data array increment 1 byte by each access
  }
  // stop timer
  gettimeofday(&t2, NULL);

  double time_span = elapsedTime(t1,t2);
  double throughput = double(total_data / KB) / time_span; //throughput kbps
  printf("Buffer size is %d KB, throughput is %f kbps\n", (size / KB), throughput);

  delete[] buffer;  //free memory
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