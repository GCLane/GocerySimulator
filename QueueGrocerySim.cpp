/*
    Name: Grant Lane
    Date: 2/2/2022
    Class: IT 279
    Prof: Dr. Calif

    Part of program1 and implementing the queue in
    a supermarket to be used to track customers
*/
//Method that prints the arrival of a customer

#include <iostream>
#include "Queue.h"
#include <string>
#include <ctime>

using namespace std;

void custArrival(int custNum, int min);
void custDepart(int custNum, int min);

int determineMax(int max, int current);


int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        cerr << "Correct usage: " << argv[0] << "<range of number of minutes> <seed for the random number generator>" << endl;
        exit(1);
    }

    int x = atoi(argv[1]);
    int seed = atoi(argv[2]);
    if(seed < 0)
    {
        srand(time(0));
    }
    else
    {
        srand(seed);
    }

    Queue custQueue;
    Queue timeQueue;
    //Variables used for keeping track of the wait time and max size
    int queueMaxLength = custQueue.getSize();
    int maxWaitTime = 0;
    int waitTime = 0;


    long minuteCount = rand() % x + 1; //time when the first customer arrives
    int serveCount = 1; //keeps track of the time a customer is being served

    //for keeping track of the customers
    int custNum = 1;
    int amtServed = 0;

    //First Customer arrives to be served
    custArrival(custNum, minuteCount);
    int serviceTime = rand() % x + 1;
    int nextArrival = rand() % x + 1 + minuteCount;
    int nextServiceTime = rand() % x + 1; //for changing the service times
    

    bool inService = true; //determines whether or not a customer is being served


    while(minuteCount <= 720)
    {   //Queues the customer when they walk in and their is somebody being served
        if(inService && nextArrival == minuteCount)
        {
            custNum++;
            custArrival(custNum, minuteCount);
            custQueue.enqueue(nextServiceTime);
            int nextServiceTime = rand() % 1 + x;
            queueMaxLength = determineMax(queueMaxLength, custQueue.getSize());
            timeQueue.enqueue(nextArrival);
            nextArrival = rand() % x + 1 + minuteCount;
            if(serveCount > serviceTime)
            {
                serveCount = 0;
            }
        }
        else if(nextArrival == minuteCount)
        {
            custNum++;
            custArrival(custNum, minuteCount);
            serviceTime = rand() % x + 1;
            nextArrival = rand() % x + 1 + minuteCount;
            inService = true;
            if(serveCount > serviceTime)
            {
                serveCount = 0;
            }
        }

        if(serviceTime == serveCount && inService)
        {
            inService = false;
            amtServed++;
            custDepart(amtServed, minuteCount);
            if(!custQueue.isEmpty())
            {
                serviceTime = custQueue.dequeue();
                waitTime = timeQueue.dequeue();
                maxWaitTime = determineMax(maxWaitTime, waitTime);
                inService = true;
            }
            else
            {
                serviceTime = nextServiceTime;
            }
            serveCount = 0;
        }
    
        serveCount++;
        minuteCount++;
    }
    cout << "Largest number of customers in queue: " << queueMaxLength << endl;
    cout << "Longest wait time for a customer: " << maxWaitTime << endl;
}

void custArrival(int custNum, int min)
{
    cout << "Customer " << custNum << " arrived at " << min << "." <<endl;
}

void custDepart(int custNum, int min)
{
    cout << "Customer " << custNum << " departed at " << min << "." << endl;
}

int determineMax(int max, int current)
{
    if(max < current)
        max = current;
    return max;
}

