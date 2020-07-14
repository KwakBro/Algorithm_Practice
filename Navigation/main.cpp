#include"Breath.h"
#include"Depth.h"
#include"graph.h"
#include<fstream>
#define NUM_NODES 20
#define NUM_EDGES 70

typedef Graph::Vertex Vertex;
typedef Graph::Edge Edge;
typedef list<typename Vertex> VtxList;
typedef list<typename Edge> EdgeList;
typedef list<typename Vertex>::iterator VtxItor;
typedef list<typename Edge>::iterator EdgeItor;

void main() {
	Vertex v[NUM_NODES] =
	{
		Vertex("Seattle", 0, UNEXPLORED),
		Vertex("SanFrancisco", 1, UNEXPLORED),
		Vertex("LosAngels", 2, UNEXPLORED),
		Vertex("SaltLakeCity", 3, UNEXPLORED),
		Vertex("RapidCity", 4, UNEXPLORED),
		Vertex("Denver", 5, UNEXPLORED),
		Vertex("Phoenix", 6, UNEXPLORED),
		Vertex("Minneapolis", 7, UNEXPLORED),
		Vertex("Dallas", 8, UNEXPLORED),
		Vertex("Houston", 9, UNEXPLORED),
		Vertex("NewOrleans", 10, UNEXPLORED),
		Vertex("Memphis", 11, UNEXPLORED),
		Vertex("StLouis", 12, UNEXPLORED),
		Vertex("Chicago", 13, UNEXPLORED),
		Vertex("Detroit", 14, UNEXPLORED),
		Vertex("Miami", 15, UNEXPLORED),
		Vertex("Atlanta", 16, UNEXPLORED),
		Vertex("WashingtonDC", 17, UNEXPLORED),
		Vertex("NewYork", 18, UNEXPLORED),
		Vertex("Boston", 19, UNEXPLORED)
	};

	Edge edges[NUM_EDGES] =
	{
		Edge(v[0], v[1], 820), Edge(v[1], v[0], 820),
		Edge(v[0], v[3], 828), Edge(v[3], v[0], 828),
		Edge(v[0], v[4], 1144), Edge(v[4], v[0], 1144),
		Edge(v[1], v[2], 380), Edge(v[2], v[1], 380),
		Edge(v[1], v[3], 745), Edge(v[3], v[1], 745),
		Edge(v[2], v[3], 688), Edge(v[3], v[2], 688),
		Edge(v[2], v[6], 381), Edge(v[6], v[2], 381),
		Edge(v[3], v[4], 657), Edge(v[4], v[3], 657),
		Edge(v[3], v[5], 521), Edge(v[5], v[3], 521),
		Edge(v[4], v[5], 389), Edge(v[5], v[4], 389),
		Edge(v[4], v[7], 611), Edge(v[7], v[4], 611),
		Edge(v[5], v[6], 816), Edge(v[6], v[5], 816),
		Edge(v[5], v[7], 920), Edge(v[7], v[5], 920),
		Edge(v[5], v[8], 780), Edge(v[8], v[5], 780),
		Edge(v[5], v[12], 861), Edge(v[12], v[5], 861),
		Edge(v[6], v[8], 1067), Edge(v[8], v[6], 1067),
		Edge(v[7], v[13], 409), Edge(v[13], v[7], 409),
		Edge(v[8], v[9], 246), Edge(v[9], v[8], 246),
		Edge(v[8], v[11], 454), Edge(v[11], v[8], 454),
		Edge(v[9], v[10], 352), Edge(v[10], v[9], 352),
		Edge(v[10], v[11], 393), Edge(v[11], v[10], 393),
		Edge(v[10], v[15], 861), Edge(v[15], v[10], 861),
		Edge(v[10], v[16], 473), Edge(v[16], v[10], 473),
		Edge(v[11], v[12], 285), Edge(v[12], v[11], 285),
		Edge(v[11], v[16], 394), Edge(v[16], v[11], 394),
		Edge(v[12], v[13], 297), Edge(v[13], v[12], 297),
		Edge(v[12], v[17], 845), Edge(v[17], v[12], 845),
		Edge(v[13], v[14], 286), Edge(v[14], v[13], 286),
		Edge(v[14], v[17], 534), Edge(v[17], v[14], 534),
		Edge(v[14], v[18], 640), Edge(v[18], v[14], 640),
		Edge(v[14], v[19], 834), Edge(v[19], v[14], 834),
		Edge(v[15], v[16], 661), Edge(v[16], v[15], 661),
		Edge(v[16], v[17], 632), Edge(v[17], v[16], 632),
		Edge(v[17], v[18], 237), Edge(v[18], v[17], 237),
		Edge(v[18], v[19], 211), Edge(v[19], v[18], 211)
	};
	int test_start = 0;
	int test_end = 15;
	Graph simpleGraph(NUM_NODES);
	ofstream fout;
	fout.open("output.txt");
	if (fout.fail())
	{
		cout << "Fail to open output.txt file!!" << endl;
		exit(1);
	}

	cout << "Inserting vertices .." << endl;
	for (int i = 0; i<NUM_NODES; i++)
		simpleGraph.insertVertex(v[i]);

	VtxList vtxLst;
	simpleGraph.vertices(vtxLst);
	int count = 0;

	cout << "Inserted vertices: ";
	for (VtxItor vItor = vtxLst.begin(); vItor != vtxLst.end(); ++vItor)
		cout << *vItor << ", ";
	cout << endl;

	cout << "Inserting edges .." << endl;
	for (int i = 0; i<NUM_EDGES; i++)
		simpleGraph.insertEdge(edges[i]);

	cout << "Inserted edges: " << endl;
	count = 0;
	EdgeList egLst;
	simpleGraph.edges(egLst);
	for (EdgeItor p = egLst.begin(); p != egLst.end(); ++p)
	{
		count++;
		cout << *p << ", ";
		if (count % 5 == 0)
			cout << endl;
	}
	cout << endl;

	cout << "Print out Graph based on Adjacency List .." << endl;
	simpleGraph.printGraph(fout);
	BreadthFirstSearch bfsGraph(simpleGraph);
	VtxList A1, A2;
	bfsGraph.findShortestPath(v[0], v[10],A1,fout);
	bfsGraph.findShortestPath(v[5], v[10],A2,fout);
}