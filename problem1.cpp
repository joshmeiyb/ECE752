#include <cstdlib>
#include <iostream>
#include <sys/time.h>


#define ITER   10
#define MAX_N 64*1024*1024 
#define MB    (1024*1024)

// LLC Parameters assumed
#define START_SIZE 1*MB
#define STOP_SIZE  32*MB


using namespace std;

char array[MAX_N];



/////////////////////////////////////////////////////////
// Provides elapsed Time between t1 and t2 in milli sec
/////////////////////////////////////////////////////////

double elapsedTime(timeval t1, timeval t2){
  double delta;
  delta = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
  delta += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
  return delta; 
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
    for(ii=0; ii< MAX_N; ii++){
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

double CacheSizeTest(void)
{    
  double retval;

  return retval; 
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
