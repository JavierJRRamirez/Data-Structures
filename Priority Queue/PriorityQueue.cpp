/*
Javier Ramirez
November 5, 2016
Instructor: Boese
*/

#include <iostream>
#include "PatientQueue.hpp"

using namespace std;

bool goingdown = false;

PatientQueue::PatientQueue()
{
		lastIndex = 0;
}

PatientQueue::~PatientQueue()	// release memory and delete queue
{
	cout << "We're CLOSING! Deleting patient queue!" << endl;
	for(int i = 1; i <lastIndex+1; i++)
		{
			//cout << "We're CLOSING! Deleting patient queue!" << endl;
			cout << "Removing " << waitlist[i]->name << " from the queue."<< endl; 
			delete waitlist[i];	
		}
	
}

void PatientQueue::enqueue(int priority, std::string name)
	
{
	lastIndex++;
		
	Patient *pat = new Patient(priority,name);
	cout << "Adding " << pat->priority << " " << pat->name << endl;
	
	waitlist[lastIndex] = pat;
	//lastIndex++;
	if(lastIndex != 1)
	{
		swap(lastIndex, lastIndex/2);
	}
		printList();
		
}

bool PatientQueue::isEmpty(){
	
		if(lastIndex != 0){
			//cout <<"Not Empty" << endl;
			return false;
		}
		else{
			//cout << "Empty" << endl;
			return true;
		}
	}

Patient* PatientQueue::dequeue()
	{
		cout << "Processing " << waitlist[1] -> priority << " " << waitlist[1] -> name << endl;
		if(lastIndex == 1)
		{
			waitlist[1]=NULL;
			lastIndex--;
		}
		else {
			if(isEmpty())
			{
				return NULL;
			}	
			else {
				Patient* pointer = waitlist[1];			
				//copy lastIndex to root
				waitlist[1] = waitlist[lastIndex];
				//remove lastIndex
				waitlist[lastIndex] = NULL;				
				//decriment lastIndex
				lastIndex--;
				//swap
			goingdown = true;
			if(waitlist[2]->priority < waitlist[1]->priority && waitlist[2]->priority < waitlist[3]->priority)
			{
			 	swap(2, 1);
			}
			else if(waitlist[3]->priority < waitlist[1]->priority && waitlist[3]->priority < waitlist[2]->priority)
				{
					swap(3, 1);
				}
				goingdown = false;
				return pointer;
			}
			
		}
	}

int PatientQueue::size()
	{
		return lastIndex;
	}
	
void PatientQueue::printList()					// print the array
	{
		
		cout <<"==="<< endl << "Patients Waiting " << endl;
		if(isEmpty() != true)
			{
				for(int i =1; i <= lastIndex; i++){
				cout <<"[" << waitlist[i]->priority << "] " << waitlist[i]->name << endl;
				}
			}
		else {
			cout << "No one waiting!" << endl;
		}
		cout << "===" << endl;
	}
	
 void PatientQueue::swap(int index1, int index2)	// swap the contents in the array
 {
			
	 if(waitlist[index1]->priority < waitlist[index2]->priority)
		 {
			 //cout<< "hello2" << endl;
			 //cout << "swapping " << waitlist[index1]->name << " with " << waitlist[index2]->name << endl;
			 Patient *temp = waitlist[index1];
			 waitlist[index1] = waitlist[index2];
			 waitlist[index2] = temp;
			 if (goingdown && index1 < lastIndex/2) {
				 //cout << "hello" << endl;
				 if(waitlist[index1*2]->priority < waitlist[index1]->priority && waitlist[index1*2]->priority < waitlist[index1*2+1]->priority)
					 {
						 swap(index1*2, index1);
					 }
					else if(waitlist[index1*2+1]->priority < waitlist[index1]->priority && waitlist[index1*2+1]->priority < waitlist[index1*2]->priority)
						{
							swap(index1*2+1, index1);
						}
				}
			 else if(index2 != 1) // not going down
				{
					swap(index2, index2/2);
				}
		}
}
	
	
	
	
