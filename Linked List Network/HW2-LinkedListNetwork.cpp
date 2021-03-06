// ==========================================
// Author: Javier Ramirez
// Date: 9/20/2016
// Description: Linked List
// ==========================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

struct city
{
    string 	name; 			// name of the city
    city 	*next; 			// pointer to the next city
	int 	numberMessages;	// how many messages passed through this city
    string 	message; 		// message we are sending accross
};

city* addCity(city *head, city *previous, string cityName );
city* deleteCity(city *head, string cityName);
city* deleteEntireNetwork(city *head);
city* searchNetwork(city *head, string cityName);
city* loadDefaultSetup(city *head);
void transmitMsg(city *head, string receiver, string filename);
void printPath(city *head);
void displayMenu();
city* handleUserInput(city *head);

/* Do NOT modify main function */
int main(int argc, char* argv[])
{
    // pointer to the head of our network of cities
    city *head = NULL;

	head = handleUserInput(head);
	printPath(head);
	head = deleteEntireNetwork(head);
	if (head == NULL)
		cout << "Path cleaned" << endl;
	else
		printPath(head);

	cout << "Goodbye!" << endl;
    return 0;
}

/*
 * Purpose: handle the interaction with the user
 * @param head the start of the linked list
 * @return the start of the linked list
 * Do NOT modify
 */
city* handleUserInput(city *head)
{
    bool quit = false;
    string s_input;
    int input;

    // loop until the user quits
    while (!quit)
    {
        displayMenu();

		// read in input, assuming a number comes in
        getline(cin, s_input);
		input = stoi(s_input);

        switch (input)
        {
            // print all nodes
            case 1: 	//rebuild network
                head = loadDefaultSetup(head);
                printPath(head);
                break;

            case 2:		// print path
                printPath(head);
                break;

            case 3: //message is read in from file
			  {
        		string cityReceiver;
				cout << "Enter name of the city to receive the message: " << endl;
				getline(cin, cityReceiver);

				cout << "Enter the message to send: " << endl;
				string message;
				getline(cin, message);

                transmitMsg(head, cityReceiver, message);
			  }
                break;

            case 4:
			  {
        		string newCityName;
        		string prevCityName;
                cout << "Enter a new city name: " << endl;
                getline(cin, newCityName);

                cout << "Enter the previous city name (or First): " << endl;
                getline(cin, prevCityName);

                // find the node containing prevCity
    			city *tmp = NULL;
                if(prevCityName !="First")
                    tmp = searchNetwork(head, prevCityName);
                // add the new node
                head = addCity(head, tmp, newCityName);
                printPath(head);
			  }
                break;

            case 5: 	// delete city
			  {
        		string city;
                cout << "Enter a city name: " << endl;
                getline(cin, city);
                head = deleteCity(head, city);
                printPath(head);
			  }
                break;

            case 6: 	// delete network
                head = deleteEntireNetwork(head);
                break;

            case 7: 	// quit
                quit = true;
				cout << "Quitting... cleaning up path: " << endl;
                break;

            default: 	// invalid input
                cout << "Invalid Input" << endl;
                break;
        }
    }
	return head;
}

/*
 * Purpose: Add a new city to the network
 *   between the city *previous and the city that follows it in the network.
 * @param head pointer to start of the list
 * @param previous name of the city that comes before the new city
 * @param cityName name of the new city
 * @return pointer to first node in list
 */
city* addCity(city *head, city *previous, string cityName )
{
    city *help = new city;
    if(head == NULL)
    {
        head = help;
        head->name = cityName; // if initialized to name it adds to cityName structure
        head->next = NULL;
        return head;

    if(previous == NULL){
             previous->next = previous->next; //access elements from help and assigned it to previous
        previous->next = help;
        previous->name = cityName; }

    }
      else
        help->next = previous->next; //access elements from help and assigned it to previous
        previous->next = help;
        help->name = cityName; // access element from help and put it in cityName
    return head; //puts the head int the middle of the names
}


/*
 * Purpose: Search the network for the specified city and return a pointer to that node
 * @param ptr head of the list
 * @param cityName name of the city to look for in network
 * @return pointer to node of cityName, or NULL if not found
 * @see addCity, deleteCity
 */
city *searchNetwork(city *ptr, string cityName)
{
    city *tracker = ptr;
    while(tracker != NULL) // tracker cant be null
    {
        if(tracker->name == cityName) // tracker access element of name and then have it equal to cityName
        {
            ptr = tracker; //has the pointer equal the tracker
            return ptr;
        }
        else
        {
            tracker = tracker->next; //tracker then points elements of next and add them to tracker
        }
    }
    return ptr; // return what tracker address is
}

/*
 * Purpose: deletes all cities in the network starting at the head city.
 * @param ptr head of list
 * @return NULL as the list is empty
 */
city* deleteEntireNetwork(city *ptr)
{
    while(ptr != NULL)
    {
        city *tracker = ptr;
        ptr = ptr->next; //if ptr accesses the elements of next
		cout << "deleting: " << tracker->name << endl; //name of the element that tracker received
        delete tracker; // deletes that element

    }
	cout << "Deleted network" << endl;
    // return head, which should be NULL
    return ptr;
}

/* sends messages from file */
void transmitMsg(city *head, string receiver, string message)
{
    city *sender = head; // sender assigned to a address
    sender->message = message; // sender puts the elements in messages and adds it to the structure
    if(head == NULL)
	{
        cout << "Empty list" << endl;
        return;
    }
    else
    {
        while(sender->name != receiver)
        {
            sender->numberMessages++; // checks for the send message
            cout << sender->name << " [# messages passed: " << sender->numberMessages << "] received: " << sender->message << endl;
            sender->next->message = sender->message; // sender point to next which points to the message and says the message was from sender
            sender = sender->next; //sender checks back again
        }
    }
    return;
}


/*
 * Purpose: delete the city in the network with the specified name.
 * @param head first node in list
 * @param cityName name of the city to delete in the network
 * @return head node of list
 */
city* deleteCity(city *head, string cityName)
{
    city *tracker = head;
    while(tracker != NULL)
    {
        if(tracker->next->name == cityName) // if tracker point to next ad then points to name and its equal to a city name
        {
            city *del = tracker->next; // del equals to the tracker that is the element of the of next
            tracker->next = tracker->next->next; // del checks the name of the citys
            delete del; // deletes the city name
            return head; // return the function
        }
        tracker = tracker->next;
    }
    cout << "City does not exist." << endl;
    // if the city dosn't exist, nothing we can do.
	// 		use this output statement
    return head;
}


/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void printPath(city *ptr)
{
    cout << "== CURRENT PATH ==" << endl;

    // If the head is NULL
    if (ptr == NULL)
        cout << "nothing in path" << endl;
    else
        while(ptr != NULL)
        {
            cout<<ptr->name<<" -> ";  // print the names of the city names
            ptr = ptr->next;
        }
    cout << "NULL" <<endl;
    cout << "===" << endl;
}

/*
 * Purpose: populates the network with the predetermined cities
 * @param head start of list
 * @return head of list
 */
city* loadDefaultSetup(city *head)
{
    head = deleteEntireNetwork(head);
    head = addCity(head,NULL,"Los Angeles");
    addCity(head,searchNetwork(head, "Los Angeles"), "Phoenix");
    addCity(head,searchNetwork(head, "Phoenix"), "Denver");
    addCity(head,searchNetwork(head, "Denver"), "Dallas");
    addCity(head,searchNetwork(head, "Dallas"), "Atlanta");
    addCity(head,searchNetwork(head, "Atlanta"), "New York");

    return head;
}

/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
	cout << "Select a numerical option:" << endl;
    cout << "======Main Menu=====" << endl;
    cout << "1. Build Network" << endl;
    cout << "2. Print Network Path" << endl;
    cout << "3. Transmit Message" << endl;
    cout << "4. Add City" << endl;
    cout << "5. Delete City" << endl;
    cout << "6. Clear Network" << endl;
    cout << "7. Quit" << endl;
}

