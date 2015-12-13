#include <stdio.h>
#include <pthread.h>
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std::chrono;
using std::cout;

#define NUMBER_OF_ITERATIONS 100000000

int use_spin_lock;
pthread_spinlock_t spinlock;
pthread_mutex_t global_mutex;
volatile int global = 0;

void increment(){
	if (use_spin_lock){
        pthread_spin_lock(&spinlock);
        global++;
        pthread_spin_unlock(&spinlock);
	}else{
		pthread_mutex_lock(&global_mutex);
		global++;
		pthread_mutex_unlock(&global_mutex);
	}
}

void *compute(void *arg)
{
    for (int i = 0; i < NUMBER_OF_ITERATIONS; i++){
		increment();
    }
    return NULL;
}

void test()
{
	global = 0;
    pthread_t tids[3];
	time_point<high_resolution_clock> start, end;
    start = high_resolution_clock::now();
    for (int i = 0; i < 3; i++)
        pthread_create(&tids[i], NULL, compute, NULL);

    for (int i = 0; i < 3; i++)
        pthread_join(tids[i], NULL);
    end = high_resolution_clock::now();
    duration<double> elapsed_seconds = end - start;
    cout << "Time: " << elapsed_seconds.count() << "s\n";
    printf("global = %d\n", global);
}

int main()
{

    pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE);
	pthread_mutex_init(&global_mutex, NULL);
	use_spin_lock = 0;
	cout << "With spin lock: \n";
    test();
	cout << "With mutex: \n";
	use_spin_lock = 1;
	test();
}
