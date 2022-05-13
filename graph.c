// A C Program to demonstrate adjacency list  
// representation of graphs 
#include <stdio.h> 
#include <stdlib.h> 
#define max 30
// A structure to represent an adjacency list node 
typedef struct AdjListNode 
{ 
    int dest; 
    int cost;
    struct AdjListNode* next; 
}AdjListNode; 

  
// A structure to represent an adjacency list 

typedef struct AdjList 
{ 
     AdjListNode *head;  
}AdjList; 

// A structure to represent a graph. A graph 
// is an array of adjacency lists. 
// Size of array will be V (number of vertices  
// in graph) 

typedef struct Graph 
{ 
    int V; 
    struct AdjList* array; 
}Graph; 

  
// A utility function to create a new adjacency list node 

// A utility function that creates a graph of V vertices 


Graph* createGraph(int V) 
{ 
    Graph* graph = (Graph*) malloc(sizeof(Graph)); 
    graph->V = V; 
    // Create an array of adjacency lists.  Size of
    // array will be V 
    graph->array =  
    (AdjList*) malloc((V+1) *sizeof(AdjList)); 

    // Initialize each adjacency list as empty by  
    // making head as NULL 
    int i; 
    for (i = 1; i <= V; i++) 
	{
        graph->array[i].head = NULL; 
	}
    return graph; 
} 


// Adds an edge to an undirected graph 

void addEdge(struct Graph* graph, int src, int dest,int ct) 
{ AdjListNode* q;
    // Add an edge from src to dest.  A new node is
    // added to the adjacency list of src.  The node 
    // is added at the beginning 
    AdjListNode* newNode = (AdjListNode*) malloc(sizeof(AdjListNode));  
	newNode->dest = dest; 
	newNode->cost=ct;
	//newNode->next = graph->array[src].head;
	newNode->next = NULL;
	if(graph->array[src].head==NULL)
	{
		graph->array[src].head = newNode; 
	}
	else
	{
		q=graph->array[src].head;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=newNode;
	}
	
    //graph->array[src].head = newNode; 
    // Since graph is undirected, add an edge from 
    // dest to src also
    //printf("2");
    newNode = (AdjListNode*) malloc(sizeof(AdjListNode));
    newNode->dest = src; 
	newNode->cost = ct;
    newNode->next = NULL;
	if(graph->array[dest].head==NULL)
	{
		graph->array[dest].head = newNode;
	} 
	else
	{
		q=graph->array[dest].head;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=newNode;
	}
     
} 
void printDFS(int v, int visited[],Graph* graph)
{
	visited[v]=1;
	AdjListNode* pCrawl = graph->array[v].head;
	printf("%d  ",v);
	while(pCrawl)
	{
		if(visited[pCrawl->dest]!=1)
		{
			printDFS(pCrawl->dest, visited, graph);
		}
		pCrawl=pCrawl->next;
	}
}
void setDFS(Graph* graph, int entry)
{
  	int visited[graph->V+1],i;
  	for(i=0;i<=graph->V;i++)
  	{
  		visited[i]=0;
  	}
  	printDFS(entry, visited, graph);
}
// A utility function to print the adjacency list  
// representation of graph 
void BFS(Graph* graph,int entry)
{
	int visited[graph->V+1],i;
	int q[max],front=-1,rear=-1;
	AdjListNode* p;
  	for(i=0;i<=graph->V;i++)
  	{
  		visited[i]=0;
  	}
  	q[(++front)%max]=entry;
  	while((front%max)!=(rear%max))
  	{
  		i=q[(++rear)%max];
  		printf("%d  ",i);
  		p=graph->array[i].head;
  		visited[i]=1;
  		while(p)
  		{
  			if(visited[p->dest]==0)
  			{
  				visited[p->dest]=1;
  				q[(++front)%max]=p->dest;
  			}
  			p=p->next;
  		}
  		
  	}
}
void DFSitr(Graph* graph,int entry)
{
	int visited[graph->V+1],i;
	int s[max],tos=-1;
	AdjListNode* p;
  	for(i=0;i<=graph->V;i++)
  	{
  		visited[i]=0;
  	}
  	s[++tos]=entry;
  	while(tos!=-1)
  	{
  		i=s[tos--];
  		if(visited[i]==0)
  		{
  			printf("%d  ",i);
  			p=graph->array[i].head;
  			visited[i]=1;
  			while(p)
  			{
  				if(visited[p->dest]==0)
  				{
  					s[++tos]=p->dest;
  				}
  				p=p->next;
  			}
  		}
  	}
}
void printGraph(Graph* graph) 
{ 
    int v; 
    for (v = 1; v <= graph->V; ++v) 
    { 
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v); 
        while (pCrawl) 
        { 
            printf("-> %d (%d) ", pCrawl->dest,pCrawl->cost); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    } 
} 

void bubblesort(int arr[][2],int n)
{
	// Declaring variables
	int j,i,swap,temp_val,temp_loc,temp_viz;
	
	//First for loop
	for(i=0;i<n-1;i++)
	{
		//setting swap to 0
		swap=0;
		
		//Second for loop
		for(j=0;j<n-i-1;j++)
		{
			//If current element is greater than the next element
			if(arr[j][1]>arr[j+1][1])
			{
				temp_val=arr[j][0];
				temp_loc=arr[j][1];
				//temp_viz=arr[j][2];
				arr[j][0]=arr[j+1][0];
				arr[j][1]=arr[j+1][1];
				//arr[j][2]=arr[j+1][2];
				arr[j+1][0]=temp_val;
				arr[j+1][1]=temp_loc;
				//arr[j+1][2]=temp_viz;
				swap++;
			}
		}
		
		//If no swapping is done i.e. array is sorted, then break
		if(swap==0)
		{
			break;
		}
	}
//	return arr;
}

void print_prims(Graph* graph,int v,int visited[],int distance[])
{
	int count=0,i;
	AdjListNode* p;
	if(visited[v]==1)
	{
		return;
	}
	p=graph->array[v].head;
	visited[v]=1;
	printf("%d (%d)\n",v,distance[v]);
	while(p)
  	{
  		count++;
  		p=p->next;
  	}
  	int cost[count][2];
  	p=graph->array[v].head;
  	count=0;
  	while(p)
  	{
  		//printf("in While\n");
  		if(distance[p->dest]>distance[v]+p->cost)
  		{
  			distance[p->dest]=distance[v]+p->cost;
  			//printf("in if 2\n");
  		}
  		cost[count][0]=distance[v]+p->cost;
  		cost[count][1]=p->dest;
  		p=p->next;
  		count++;
  	}
  	//printf("in outside if\n");
  	bubblesort(cost, count);
  	p=graph->array[v].head;
    for(i=0;i<count;i++)
	{
		if(visited[cost[i][1]]!=1)
		{
			print_prims(graph, cost[i][1], visited, distance);
		}
	}
  	
}
void dijkstra_algo(Graph* graph,int entry)
{
	int mstset[graph->V+1],i,j;
	int distance[graph->V+1];
	int min_cost,min_dest,v,count=0;
	int cost[graph->V+1][2];
	AdjListNode* p;
	
  	for(i=0;i<=graph->V;i++)
  	{
  		mstset[i]=0;
  		distance[i]=INT32_MAX;
  		cost[i][0]=i;
  		cost[i][1]=INT32_MAX;
  		//cost[i][2]=0;
  	}
  	distance[entry]=0;
  	cost[entry][1]=0;
  	//print_prims(graph, entry, visited, distance);
  	v=entry;
  	for(i=1;i<=graph->V;i++)
  	{
  		p=graph->array[v].head;
		mstset[v]=1;
		//cost[v][2]=1;
		printf("%d (%d)\n",v,distance[v]);
		count=0;
  		while(p)
  		{
  			//printf("\nin While\n");
  			if(distance[p->dest]>distance[v]+p->cost)
  			{
  				distance[p->dest]=distance[v]+p->cost;
  				//printf("in if 2\n");
  				for(j=0;j<=graph->V;j++)
  				{
  					if(cost[j][0]==p->dest)
  					{
  						cost[j][1]=distance[v]+p->cost;
  						break;
  					}
  				}
  				//cost[count][0]=p->dest;
  			}
  			p=p->next;
  			count++;
  		}
  		bubblesort(cost, graph->V+1);
  		/*
  		for(j=0;j<=graph->V;j++)
		{
			printf("%d %d %d %d\n",cost[j][0],cost[j][1],cost[j][2],visited[cost[j][0]]);
		}
		*/
  		for(j=0;j<=graph->V;j++)
		{
			if(mstset[cost[j][0]]!=1&&cost[j][0]!=0)
			{
				v=cost[j][0];
				break;
			}
		}
  	}
  	printf("\n\nDistance array\n");
  	for(i=1;i<=graph->V;i++)
  	{
  		printf("%d=>>(%d)  ",i,distance[i]);
  	}
}

void prims_algo(Graph* graph,int entry)
{
	int mstset[graph->V+1],i,j;
	int distance[graph->V+1];
	int min_cost,min_dest,v,count=0;
	int cost[graph->V+1][2];
	AdjListNode* p;
	
  	for(i=0;i<=graph->V;i++)
  	{
  		mstset[i]=0;
  		distance[i]=INT32_MAX;
  		cost[i][0]=i;
  		cost[i][1]=INT32_MAX;
  		//cost[i][2]=0;
  	}
  	distance[entry]=0;
  	cost[entry][1]=0;
  	//print_prims(graph, entry, visited, distance);
  	v=entry;
  	for(i=1;i<=graph->V;i++)
  	{
  		p=graph->array[v].head;
		mstset[v]=1;
		//cost[v][2]=1;
		printf("%d (%d)\n",v,distance[v]);
		count=0;
  		while(p)
  		{
  			//printf("\nin While\n");
  			if(distance[p->dest]>p->cost&&mstset[p->dest]!=1)
  			{
  				distance[p->dest]=p->cost;
  				//printf("in if 2\n");
  				for(j=0;j<=graph->V;j++)
  				{
  					if(cost[j][0]==p->dest)
  					{
  						cost[j][1]=p->cost;
  						break;
  					}
  				}
  				//cost[count][0]=p->dest;
  			}
  			p=p->next;
  			count++;
  		}
  		bubblesort(cost, graph->V+1);
  		/*
  		for(j=0;j<=graph->V;j++)
		{
			printf("%d %d %d\n",cost[j][0],cost[j][1],visited[cost[j][0]]);
		}
		*/
  		for(j=0;j<=graph->V;j++)
		{
			if(mstset[cost[j][0]]!=1&&cost[j][0]!=0)
			{
				v=cost[j][0];
				break;
			}
		}
  	}
  	printf("\n\nDistance array\n");
  	for(i=1;i<=graph->V;i++)
  	{
  		printf("%d=>>(%d)  ",i,distance[i]);
  	}
}

// Driver program to test above functions 

int main() 
{ 
	int v,i,e,v1,v2,ct; 
    // create the graph given in above figure 
    printf("Enter the Number of vertices in graph\n");
    scanf("%d",&v);
    struct Graph* graph = createGraph(v); 
    printf("Enter the Number of Edges in graph\n");
    scanf("%d",&e);
    for(i=1;i<=e;i++)
    {
    	printf("Enter the edge points\neg. p1  p2 cost\n");
    	scanf("%d %d %d",&v1,&v2,&ct);
    	addEdge(graph, v1, v2,ct);
    }
   // addEdge(graph, 0, 1); 

   // addEdge(graph, 0, 4); 

    //addEdge(graph, 1, 2); 

   // addEdge(graph, 1, 3); 

   // addEdge(graph, 1, 4); 

    //addEdge(graph, 2, 3); 

    //addEdge(graph, 3, 4); 

  

    // print the adjacency list representation of the above graph 

    printGraph(graph); 
    /*
    printf("\nDFS using Recursion\n");
	setDFS(graph,1);
    printf("\nBFS using Iteration\n");
    BFS(graph, 1);
    printf("\nDFS using iteration\n");
	DFSitr(graph, 1);
    */
    //dijkstra_algo(graph, 1);
    prims_algo(graph, 1);
    return 0; 
}
