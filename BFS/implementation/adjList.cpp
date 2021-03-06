/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : adjList.cpp
 * Created on    : Tuesday 23 July 2019 09:07:55 AM IST
 * Last modified : Tuesday 23 July 2019 10:39:13 AM IST
 * Description   : implementation of breadth first search using adjacency 
 *                 list. 
 * ***********************************************************************/


#include <iostream>
#include <list>


class Graph {
	private:
		int v; 			// number of vertices
		std::list<int> *adjList;

	public:
		Graph (int v);
		void addEdge (int src, int dest);
		void BFS (int src);
		void print ();
};

Graph::Graph (int v):v{v}
{	
	adjList = new std::list<int>[v];
}

void Graph::addEdge (int src, int dest)
{
	adjList[src].push_back(dest);
	adjList[dest].push_back(src);
}

void Graph::BFS (int src)
{
	bool visited[v] = {0};
	std::list<int> queue;

	visited[src] = true;    // marking source vertex, visited
	queue.push_back(src);   // adding source in the queue
	std::cout << "Breadth first traversal for the graph: \n";

	while (!queue.empty()){
		int bfs = queue.front(); 	// storing front element 
		queue.pop_front();			// deque first element

		std::cout << bfs << " ";

		// exploring adjacent vertex and pushing in the queue
		// and marking visited node
		for (auto temp:adjList[bfs]){
			if (visited[temp] != true){
				visited[temp] = true;
				queue.push_back(temp);
			}
		}
	}

	std::cout << std::endl;
}

void Graph::print ()
{
	for (auto i = 0; i < v; i++){
		std::cout << i << "->";
		for (auto temp:adjList[i])
			std::cout << temp << "->";

		std::cout << std::endl;
	}
}

int main ()
{
	Graph graph(6);

	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(0, 4);
	graph.addEdge(1, 5);
	graph.addEdge(2, 5);
	graph.addEdge(2, 3);

	graph.print();
	graph.BFS(0);

	return 0;
}
