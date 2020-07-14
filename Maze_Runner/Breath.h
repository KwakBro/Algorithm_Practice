#pragma once
#include"graph.h"
using namespace std;
enum BFS_PROCESS_STATUS { NOT_SELECTED, SELECTED };

class BreadthFirstSearch {
protected:
	typedef Graph::Vertex Vertex;
	typedef Graph::Edge Edge;
	typedef list<typename Vertex> VertexList;
	typedef list<typename Edge> EdgeList;
	typedef EdgeList::iterator EdgeItor;
	typedef VertexList::iterator VtxItor;
protected:
	Graph& graph;
	Vertex start;
	bool done;
	int **ppDistMtrx;
	
public:
	BreadthFirstSearch(Graph& g) : graph(g) {
		const int num = g.getNumVertices();
		
		for (int i = 0; i < num; i++)
			ppDistMtrx = new int*[num];
		for (int i = 0; i < num; i++)
			ppDistMtrx[i] = new int[num];

		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				ppDistMtrx[i][j] = PLUS_INF;
	}
	void initialize();
	void bfsTraversal(Vertex& v, Vertex& target, VertexList& path) {
		int** ppDistMtrx;
		int* pLeastCost;
		int num_nodes, num_selected;
		int* pPrev;
		int minID, minCost;
		BFS_PROCESS_STATUS* pBFS_Process_Stat;
		Vertex* pVrtxArray;
		Vertex vrtx, *pPrevVrtx;
		Edge e;
		int start_vrtxid, target_vrtxid, curVrtx_ID, vrtxID;
		EdgeList* pAdjLstArray;
		pVrtxArray = graph.getpVrtxArray();
		pAdjLstArray = graph.getpAdjLstArray();
		start_vrtxid = start.getID();
		target_vrtxid = target.getID();
		num_nodes = graph.getNumVertices();
		ppDistMtrx = getppDistMtrx();
		pLeastCost = new int[num_nodes];
		pPrev = new int[num_nodes];
		pBFS_Process_Stat = new BFS_PROCESS_STATUS[num_nodes];
		// initialize L(n) = w(start, n);
		for (int i = 0; i < num_nodes; i++)
		{
			pLeastCost[i] = ppDistMtrx[start_vrtxid][i];
			pPrev[i] = start_vrtxid;

			pBFS_Process_Stat[i] = NOT_SELECTED;
		}
		pBFS_Process_Stat[start_vrtxid] = SELECTED;
		num_selected = 1;
		int round = 0;
		while (num_selected < num_nodes)	 // ÀüºÎ´Ù ¼¿·ºÆ® µÇ¸é Å»Ãâ
		{
			round++;
			cout << "=== round " << round << " ==== " << endl;
			// find current node with LeastCost
			minID = -1;
			minCost = PLUS_INF;
			for (int i = 0; i < num_nodes; i++) {
				if ((pLeastCost[i] < minCost) && (pBFS_Process_Stat[i] != SELECTED)) {
					minID = i;
					minCost = pLeastCost[i];
				}
			}
			if (minID == -1) {
				cout << "Error in FindShortestPath() ";
				cout << "target is not connected to the start !!" << endl;
				break;
			}
			else {
				pBFS_Process_Stat[minID] = SELECTED;
				num_selected++;
				if (minID == target_vrtxid) // target reached
				{
					cout << "reached to the target node !!" << endl;
					cout << "Least Cost = " << minCost << endl;
					vrtxID = minID;
					do {
						vrtx = pVrtxArray[vrtxID];
						path.push_front(vrtx);
						vrtxID = pPrev[vrtxID];
					} while (vrtxID != start_vrtxid);
					vrtx = pVrtxArray[vrtxID];
					path.push_front(vrtx); // start node
					break;
				}
			}
			int pLS, ppDistMtrx_i;
			for (int i = 0; i<num_nodes; i++)
			{
				if ((pBFS_Process_Stat[i] != SELECTED) &&
					(pLeastCost[i] > (pLeastCost[minID] + ppDistMtrx[minID][i]) ))
				{ // update distances with relaxation
					pPrev[i] = minID;
					pLeastCost[i] = pLeastCost[minID] + ppDistMtrx[minID][i];
				}
			}
			// print out the pLeastCost[] for debugging
			for (int i = 0; i < num_nodes; i++)
			{
				if (pLeastCost[i] == 1073741823)
				{
					cout << "v" << i << setw(5) << "+oo" << ", ";
				}
				else
				{
					cout << "v" << i << setw(5) << pLeastCost[i] << ", ";
				}

			}
			cout << endl;
		}
	}
	virtual bool isDone() const { return done; }
	
	void visit(Vertex& v);
	void visit(Edge& e);
	void unvisit(Vertex& v);
	void unvisit(Edge& e);
	bool isVisited(Vertex& v);
	bool isVisited(Edge& e);
	void setEdgeStatus(Edge& e, EdgeStatus es);
	EdgeStatus getEdgeStatus(Edge& e);

public:	
	void initDistMtrx();
	void printDistMtrx();
	void findShortestPath(Vertex& s, Vertex& t, VertexList& path);
	
	// void dijkstra(Vertex& s, int* pPrev);
	Graph& getGraph() { return graph; }
	int** getppDistMtrx() { return ppDistMtrx; }
};