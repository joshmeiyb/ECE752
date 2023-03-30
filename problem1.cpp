#include <cstdlib>
#include <iostream>
#include <sys/time.h>


#define ITER   10
#define STEPS 64*1024*1024 //64MB, arbitraty number of steps
#define MB    (1024*1024)

// LLC Parameters assumed
#define START_SIZE 1*MB
#define STOP_SIZE  12*MB


using namespace std;

char array[STEPS];



/////////////////////////////////////////////////////////
// Provides elapsed Time between t1 and t2 in milli sec
/////////////////////////////////////////////////////////

double elapsedTime(timeval t1, timeval t2){
  double delta;
  delta = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
  delta += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
  return delta; STEPS
}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

double DummyTest(void)
{    
  timeval t1, t2;
  int ii, iterid;

  // start timer
  gettimeofday(&t1, NULL);

  for(iterid=0;iterid<ITER;iterid++){
    for(ii=0; ii< STEPS; ii++){
      array[ii] += rand();
    }
  }

  // stop timer
  gettimeofday(&t2, NULL);
 
  return elapsedTime(t1,t2);
}



/////////////////////////////////////////////////////////
// Change this, including input parameters
/////////////////////////////////////////////////////////

double CacheNumLevelsTest(void)
{    
  double retval;

  return retval; 
}


/////////////////////////////////////////////////////////
// Change this, including input parameters
/////////////////////////////////////////////////////////

double CacheSizeTest(int stride)
{    
  timeval t1, t2;

  // start timer
  gettimeofday(&t1, NULL);

  for (int i = 0; i < STEPS; i = i + stride){ //use different stride in loop, strides shows cache size
    array[(i*16) % sizeof(array)]++;
  }

  // stop timer
  gettimeofday(&t2, NULL);

  return elapsedTime(t1,t2); 
}


/////////////////////////////////////////////////////////
// Change this, including input parameters
/////////////////////////////////////////////////////////

double LineSizeTest(void)
{    
  double retval;

  return retval; 
}


/////////////////////////////////////////////////////////
// Change this, including input parameters
/////////////////////////////////////////////////////////

double MemoryTimingTest(void)
{    
  double retval;

  return retval; 
}



/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

int main(){
  
  cout << "\nStarting DummyTest:" << "\n";
  cout << "Test took " << DummyTest()/1000.0 << " seconds\n";

  // Add your code here, and comment above

  cout << "\n";
}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
