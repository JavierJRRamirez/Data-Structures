// Javier Ramirez
// November 11, 2016
// Professor Boese

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

#include "Graph.hpp"

using namespace std;

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::addEdge(string v1, string v2, int distance)
{
	// add code here
	for(int i = 0; i<vertices.size(); i++)
		{
			if(vertices[i].name == v1)
				{
					for(int k = 0; k < vertices.size(); k++)
						{
							if(vertices[k].name == v2 && i != k)
								{
									adjVertex av;
									av.v = &vertices[k];
									av.distance = distance;
									vertices[i].adj.push_back(av);
								}
						}
				}
		}


}

void Graph::addVertex(string n)
{
	bool found = false;
	for(int i = 0; i < vertices.size(); i++)
		{
			if(vertices[i].name == n)
				{
					found = true;
					cout << vertices[i].name << " found." << endl;
				}
		}
		if(found == false)
			{
				vertex v;
				v.name = n;
				v.district = -1;
				vertices.push_back(v);
			}
}

void Graph::displayEdges()
{
    for(int i = 0; i < vertices.size(); i++)
	{
        cout << vertices[i].district << ":" <<vertices[i].name << "-->";
        for(int j = 0; j < vertices[i].adj.size(); j++)
		{
            cout << vertices[i].adj[j].v->name;
			cout << " (" << vertices[i].adj[j].distance << " miles)"; 
            if (j != vertices[i].adj.size()-1)
                cout << "***";
        }
        cout << endl;
    }
}

void Graph::assignDistricts()
{
    // Starting district numbers at 1
    int distID = 1;

    // For each of the vertices
    for(int i = 0; i < vertices.size(); i++)
    {
        // Only consider a vertex that has not been assigned a district.
        if (vertices[i].district == -1)
        {
            // Run breadth first traversal and assign each node in the network to this district.
            BFTraversalLabel(vertices[i].name,distID);
            distID++;
        }
    }
}

void Graph::BFTraversalLabel(std::string startingCity, int distID)
{
  queue<vertex*> q;
  // Label all as unvisited.
  for(int i = 0; i < vertices.size(); i++)
  {
    vertices[i].visited = false;
  }
  // Find the starting node and enqueue it.
  for(int i = 0; i < vertices.size(); i++)
  {
      if (vertices[i].name == startingCity)
      {
          // set current vertex to be visited.

  		  vertices[i].visited = true;
          q.push(&vertices[i]);
          vertices[i].district = distID;
          break;
      }
  }
 // Now do the rest of the search.
 while (q.empty() != true)
 {
     vertex * u = q.front();		// get the next one from the queue
     q.pop();						// remove that one from the queue

	 for(int i = 0; i < u->adj.size(); i++)
     {
         if (u->adj[i].v->visited == false)
         {
             u->adj[i].v->visited = true;
             u->adj[i].v->district = distID;
             q.push(u->adj[i].v);
         }
     }
 }
}

vertex * Graph::findVertex(std::string name)
{
	for(int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i].name == name)
            return &vertices[i];
    }
	
    return NULL;
}
