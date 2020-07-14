#include"Depth.h"
#include"Breath.h"
#include<fstream>
#define NUM_NODES 25
#define NUM_EDGES 50

typedef Graph::Vertex Vertex;
typedef Graph::Edge Edge;
typedef list<typename Vertex> VtxList;
typedef list<typename Edge> EdgeList;
typedef VtxList::iterator VtxItor;
typedef EdgeList::iterator EdgeItor;

void main() {
	Vertex v[NUM_NODES] = {
		Vertex("V00",0,UNEXPLORED) ,
		Vertex("V01",1,UNEXPLORED) ,
		Vertex("V02",2,UNEXPLORED) ,
		Vertex("V03",3,UNEXPLORED) ,
		Vertex("V04",4,UNEXPLORED) ,
		Vertex("V05",5,UNEXPLORED) ,
		Vertex("V06",6,UNEXPLORED) ,
		Vertex("V07",7,UNEXPLORED) ,
		Vertex("V08",8,UNEXPLORED) ,
		Vertex("V09",9,UNEXPLORED) ,
		Vertex("V10",10,UNEXPLORED) ,
		Vertex("V11",11,UNEXPLORED) ,
		Vertex("V12",12,UNEXPLORED) ,
		Vertex("V13",13,UNEXPLORED) ,
		Vertex("V14",14,UNEXPLORED) ,
		Vertex("V15",15,UNEXPLORED) ,
		Vertex("V16",16,UNEXPLORED) ,
		Vertex("V17",17,UNEXPLORED) ,
		Vertex("V18",18,UNEXPLORED) ,
		Vertex("V19",19,UNEXPLORED) ,
		Vertex("V20",20,UNEXPLORED) ,
		Vertex("V21",21,UNEXPLORED) ,
		Vertex("V22",22,UNEXPLORED) ,
		Vertex("V23",23,UNEXPLORED) ,
		Vertex("V24",24,UNEXPLORED) ,
	};

	Edge e[NUM_EDGES] = {
		Edge(v[0] , v[1] , 1) , Edge(v[17] , v[18] , 1) ,
		Edge(v[0] , v[5] , 1) , Edge(v[17] , v[22] , 1) ,
		Edge(v[1] , v[0] , 1) , Edge(v[18] , v[17] , 1) ,
		Edge(v[1] , v[2] , 1) , Edge(v[18] , v[19] , 1) ,
		Edge(v[1] , v[6] , 1) , Edge(v[18] , v[23] , 1) ,
		Edge(v[2] , v[1] , 1) , Edge(v[19] , v[14] , 1) ,
		Edge(v[3] , v[8] , 1) , Edge(v[19] , v[18] , 1) ,
		Edge(v[4] , v[9] , 1) , Edge(v[20] , v[15] , 1) ,
		Edge(v[5] , v[0] , 1) , Edge(v[21] , v[16] , 1) ,
		Edge(v[6] , v[1] , 1) , Edge(v[21] , v[22] , 1) ,
		Edge(v[6] , v[7] , 1) , Edge(v[22] , v[17] , 1) ,
		Edge(v[6] , v[11] , 1) , Edge(v[22] , v[21] , 1) ,
		Edge(v[7] , v[6] , 1) , Edge(v[23] , v[18] , 1) ,
		Edge(v[7] , v[8] , 1) , Edge(v[23] , v[24] , 1) ,
		Edge(v[8] , v[3] , 1) , Edge(v[24] , v[23] , 1) ,
		Edge(v[8] , v[7] , 1) , Edge(v[8] , v[13] , 1) ,
		Edge(v[9] , v[4] , 1) , Edge(v[9] , v[14] , 1) , 
		Edge(v[10] , v[11] , 1) , Edge(v[10] , v[15] , 1) , 
		Edge(v[11] , v[6] , 1) , Edge(v[11] , v[10] , 1) , 
		Edge(v[12] , v[17] , 1) , Edge(v[13] , v[8] , 1) , 
		Edge(v[13] , v[14] , 1) , Edge(v[14] , v[9] , 1) , 
		Edge(v[14] , v[13] , 1) , Edge(v[14] , v[19] , 1) , 
		Edge(v[15] , v[10] , 1) , Edge(v[15] , v[16] , 1) , 
		Edge(v[15] , v[20] , 1) , Edge(v[16] , v[15] , 1) , 
		Edge(v[16] , v[21] , 1) , Edge(v[17] , v[12] , 1) 
	};

	Graph simpleGraph(NUM_NODES);
	ofstream fout;
	fout.open("out.txt");
	if (fout.fail())
		exit(1);
	fout << "Inserting verting ... " << endl;
	for (int i = 0; i < NUM_NODES; i++)
		simpleGraph.insertVertex(v[i]);

	VtxList vtxLst;
	simpleGraph.vertices(vtxLst);

	int count = 0;
	fout << "Inserted vertices : ";
	for (VtxItor vItor = vtxLst.begin(); vItor != vtxLst.end(); ++vItor) {
		fout << *vItor << ", ";
	}
	fout << endl;

	fout << "Inserting edges .. " << endl;
	for (int i = 0; i < NUM_EDGES; i++)
		simpleGraph.insertEdge(e[i]);
	
	fout << "Inserted edges : " << endl;
	count = 0;
	EdgeList egLst;
	simpleGraph.edges(egLst);

	for (EdgeItor p = egLst.begin(); p != egLst.end(); ++p) {
		count++;
		fout << *p << ", ";
		if (count % 5 == 0)
			fout << endl;
	}
	fout << endl;

	fout << "Print out Graph based on Adjacency List .. " << endl;
	simpleGraph.printGraph(fout);

	DepthFirstSearch dfs(simpleGraph);

	BreadthFirstSearch bfs(simpleGraph);

	VtxList path;
	dfs.showConnectivity(fout);//

	dfs.findPath(v[0], v[24], path);
	fout << "Path ( " << v[0] << " => " << v[24] << " ) : ";
	for (VtxItor vItor = path.begin(); vItor != path.end(); ++vItor) {
		fout << *vItor << "      ";
	}
	fout << endl;
	path.clear();

	dfs.findPath(v[24], v[0], path);
	fout << "Path ( " << v[24] << " => " << v[0] << " ) : ";
	for (VtxItor vItor = path.begin(); vItor != path.end(); ++vItor) {
		fout << *vItor << "      ";
	}
	fout << endl;

	bfs.findShortestPath(v[0], v[24], path);

	bfs.findShortestPath(v[24], v[0], path);
	fout.close();
}