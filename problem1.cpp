//TODO: debug cache line access
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
  for (int i = 0; i < access_time; i++){
    int index = distribution(generator);
    random_index.push_back(index);      // Push the element into a the random_index vector from the back
  }

  int total_data = 0;
  // start timer
  gettimeofday(&t1, NULL);
  for(int i = 0; i < access_time; i++){
    total_data += buffer[random_index[i]];  // Total_data array increment 1 byte by each access
                                            // If index is within one level cache the access time will be small
                                            // Otherwise, the access time will be large 
  }
  // stop timer
  gettimeofday(&t2, NULL);

  double time_span = elapsedTime(t1,t2);
  double throughput = double(total_data / KB) / time_span; //throughput kbps
  // printf("Buffer size is %d KB, throughput is %f kbps\n", (size / KB), throughput);
  printf("%d,%f\n", (size / KB), throughput);

  delete[] buffer;  //free memory
}

void cacheSize_test(){
  
  vector<int> sizes{ 1*KB, 2*KB, 4*KB, 8*KB, 16*KB, 32*KB, 50*KB, 64*KB, 72*KB, 80*KB, 96*KB, 128*KB, 192*KB, 256*KB, 384*KB, 512*KB,
                     1*MB, 2*MB, 3*MB, 4*MB, 5*MB, 6*MB, 7*MB, 8*MB, 9*MB, 10*MB, 11*MB, 12*MB, 16*MB, 32*MB, 64*MB, 128*MB};

  for(auto size : sizes){
    cacheAccess(size);
  }
}

void cacheLineAccess(int stride){
  
  timeval t1, t2;
  int ii, iterid;
  
  int buffer_size = 400 * MB;
  // Initialize buffer array with all 1
  int* buffer = new int [buffer_size / B];
  std::fill(buffer, buffer+(buffer_size / B), 1);  

  // Generate a large number of access 
  // Each access index is within the stride size
  // int access_time = 9999999;
  // std::uniform_int_distribution<int> distribution(0, (stride / B) - 1);

  // vector<int> random_index;
  // for (int i = 0; i < access_time; i++){
  //   int index = distribution(generator);
  //   random_index.push_back(index);
  // }

  // Start test
  // Try different strides
  // If stride is within the cache line, the access will hit
  // If stride is out of cache line, the access will miss 
  int total_data = 0;
  gettimeofday(&t1, NULL);
  for(int i = 0; i < stride; i++){              
    for(int j = 0; j < (buffer_size / B); j+=stride){
        total_data += buffer[j];                          
    }
  }
  // for(int i = 0; i < access_time; i++){
  //   for(int j = 0; j < ()){
      
  //   }
  //   total_data += buffer[random_index[i]];
  // }
  gettimeofday(&t2, NULL);

  double time_span = elapsedTime(t1,t2);
  double throughput = double(total_data / KB) / time_span;
  printf("%d,%f\n", stride, throughput);

}

void cacheLine_test(){

  // int buffer_size = 100*MB;  // initialize a large memory size for test, larger than L3 cache

  vector<int> strides{ 1*B, 2*B, 4*B, 8*B, 16*B, 32*B, 50*B, 64*B, 72*B, 80*B, 96*B, 128*B, 192*B, 256*B, 384*B, 512*B,
                     1*KB, 2*KB, 3*KB, 4*KB, 5*KB, 6*KB, 7*KB, 8*KB, 9*KB, 10*KB, 11*KB, 12*KB, 16*KB, 32*KB, 64*KB, 128*KB};

  for(auto stride : strides){
    cacheLineAccess(stride);
  }
}

int main(/*int argc, char **argv*/){  // equivalent expression is (int argc, char* argv[])

  // cacheSize_test();
  cacheLine_test();

  return 0;
}