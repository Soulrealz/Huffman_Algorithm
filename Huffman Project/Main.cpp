#include <iostream>
#include <string>


int main()
{
	char symbol;
	do
	{
		std::cout << "Choose program:\n";
		std::cout << "1 - Insert text from console\n";
		//std::cout << "2) Input text from file\n";
		//std::cout << "3) Decode from file with encoded data and saved tree\n";
		std::cout << "4 - Exit\n";

		std::cout << "\nEnter option: ";
		std::cin >> symbol;
	} while (symbol != '1' && symbol != '2' && symbol != '3' && symbol != '4');

	std::cout << "\n\n";

	switch (symbol)
	{
	case '1':
	{
		std::string str = "";
		std::cout << "Enter text to compress:";
		std::cin >> str;
		
	}	
	break;		
	case '2':
		break;
	case '3':
		break;
	default: std::cout << "Exiting...";
		break;
	}
	

	return 0;
}



/*
#include <cstdio>
#include <queue>
#include <vector>
#include <limits.h>

#define pi pair<int,int>

using namespace std;

int n,m;
int used[int(1e6)+5], dist[int(1e6)+5], parent[int(1e6)+5];

struct Edge{
	int to,weight;

	Edge(int to=0,int weight = 0){
		this->to = to;
		this->weight = weight;
	}
};

vector<Edge>gr[int(1e6)+5];

void init(){
	int from,to,weight;

	scanf("%d %d",&n,&m);

	for(int i=0;i<m;i++){
		scanf("%d %d %d",&from,&to,&weight);

		gr[from].push_back({to,weight});
		gr[to].push_back({from,weight});
	}
}

void dijkstra(int start){
	priority_queue<pi,vector<pi>, greater<pi>>toVisit;///{dist,node}. Dist is first since i want to use the pair comparator

	fill(dist,dist+n,INT_MAX/10);///initialize distances with big numbers

	dist[start] = 0;///distance to start is 0
	toVisit.push({0,start});///add it to the queue
	parent[start]=-1;///it is the first node so it has no parent

	while(!toVisit.empty()){
		int node = toVisit.top().second;///take a node and remove it from the queue
		toVisit.pop();

		if(used[node])continue;///if it is not the first time we see it just skip

		used[node]=1;///mark it as used

		for(Edge neighbor:gr[node]){///for each of its neighbors
			if(dist[node] + neighbor.weight >= dist[neighbor.to])continue;///compare the new distance if we use the path trough node with the old distance

			///if it is better update the distance and add to the queue.
			dist[neighbor.to] = dist[node] + neighbor.weight;
			parent[neighbor.to] = node;///if the new distance is better, then we use the path trough node to go to its neighbor, so its parent is node.
			toVisit.push({dist[neighbor.to],neighbor.to});
		}
	}
}

void print(){
	for(int i=0;i<n;i++){
		printf("dist to %d is %d\n",i,dist[i]);
	}
}

int main(){
	init();
	dijkstra(2);
	print();
}

*/