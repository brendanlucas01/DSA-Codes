// A C Program to demonstrate adjacency list  
// representation of graphs 
#include <stdio.h> 
#include <stdlib.h> 
#define max 30
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

void addEdge(struct Graph* graph, int src, int dest,int indegree[]) 
{ AdjListNode* q;
    // Add an edge from src to dest.  A new node is
    // added to the adjacency list of src.  The node 
    // is added at the beginning 
    AdjListNode* newNode = (AdjListNode*) malloc(sizeof(AdjListNode));  
	newNode->dest = dest; 
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
	indegree[dest]=indegree[dest]+1;
	
    //graph->array[src].head = newNode; 
    // Since graph is undirected, add an edge from 
    // dest to src also
    //printf("2");
} 

void toposort(Graph* graph,int indegree[])
{
	int queue[max],front=-1,rear=-1,i;
	AdjListNode* p;
	for(i=1;i<=graph->V;i++)
	{
		if(indegree[i]==0)
		{
			queue[(++rear)%max]=i;
		}
	}
	printf("\n\nTopological sort of the DAG is:-\n");
	while((front%max)!=(rear%max))
	{
		i=queue[(++front)%max];
		printf("%d  ",i);
		indegree[i]=-1;
		p=graph->array[i].head;
		while(p!=NULL)
		{
			indegree[p->dest]=indegree[p->dest]-1;
			if(indegree[p->dest]==0)
			{
				queue[(++rear)%max]=p->dest;
			}
			p=p->next;
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
            printf("-> %d", pCrawl->dest); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    } 
} 

  
// Driver program to test above functions 

int main() 
{ 
	int v,i,e,v1,v2,*indegree; 
    printf("Enter the Number of vertices in graph\n");
    scanf("%d",&v);
    struct Graph* graph = createGraph(v); 
    indegree=(int)malloc((v+1)*sizeof(int));
    for(i=0;i<=v;i++)
    {
    	indegree[i]=0;
    }
    indegree[0]=-1;
    printf("Enter the Number of Edges in graph\n");
    scanf("%d",&e);
    for(i=1;i<=e;i++)
    {
    	printf("Enter the edge points\neg. p1  p2\n");
    	scanf("%d %d",&v1,&v2);
    	addEdge(graph, v1, v2,indegree);
    }
 	// print the adjacency list representation of the graph 

    printGraph(graph); 
    for(i=0;i<=v;i++)
    {
    	printf("%d -> %d\n",i,indegree[i]);
    }
    toposort(graph, indegree);
    return 0; 
}
