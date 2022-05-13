// A C Program to demonstrate adjacency list  
// representation of graphs 
#include <stdio.h> 
#include <stdlib.h> 
#define max 30
int total_colors=1;
// A structure to represent an adjacency list node 
typedef struct AdjListNode 
{ 
    int dest; 
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

void addEdge(struct Graph* graph, int src, int dest) 
{ AdjListNode* q;
    // Add an edge from src to dest.  A new node is
    // added to the adjacency list of src.  The node 
    // is added at the beginning 
    AdjListNode* newNode = (AdjListNode*) malloc(sizeof(AdjListNode));  
	newNode->dest = dest; 
	//newNode->cost=ct;
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
	//newNode->cost = ct;
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
void get_colors(int v, int visited[],Graph* graph,int start_col)
{
	AdjListNode* pCrawl = graph->array[v].head;
	int prev_col=1,this_col=1;
	if(start_col!=0)
	{
		prev_col=this_col=start_col;
	}
	while(pCrawl)
	{
		if(visited[pCrawl->dest]==this_col)
		{
			this_col++;
			//printf("%d% d\n",v,pCrawl->dest);
		}
		pCrawl=pCrawl->next;
		if(prev_col!=this_col)
		{
			prev_col=this_col;
			pCrawl = graph->array[v].head;
		}
	}
	visited[v]=this_col;
	printf("%d->(%d)  ",v,this_col);
	if(this_col>total_colors)
	{
		total_colors=this_col;
	}
	pCrawl = graph->array[v].head;
	while(pCrawl)
	{
		if(visited[pCrawl->dest]==0)
		{
			get_colors(pCrawl->dest, visited, graph,0);
		}
		pCrawl=pCrawl->next;
	}
}
void set_colors(Graph* graph, int entry,start_col)
{
  	int visited[graph->V+1],i;
  	for(i=0;i<=graph->V;i++)
  	{
  		visited[i]=0;
  	}
  	get_colors(entry, visited, graph,start_col);
}
// A utility function to print the adjacency list  
// representation of graph 
void printGraph(Graph* graph) 
{ 
    int v; 
    for (v = 1; v <= graph->V; ++v) 
    { 
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v); 
        while (pCrawl) 
        { 
            printf("-> %d ", pCrawl->dest); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
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
    	printf("Enter the edge points\neg. p1  p2\n");
    	scanf("%d %d",&v1,&v2);
    	addEdge(graph, v1, v2);
    }
   
    // print the adjacency list representation of the above graph 

    printGraph(graph); 
    
    printf("\nSolutions to the problem are\n");
    i=1;
  	while(i<=total_colors)
  	{
  		set_colors(graph,1,i);
  		printf("\n");
  		i++;
  	}
    return 0; 
}
