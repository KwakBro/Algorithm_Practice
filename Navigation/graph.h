#ifndef GRAPH_H
#define GRAPH_H

#include<list>
#include<vector>
#include<iostream>
#include<iomanip>
#include<limits>
#include<string>

#define PLUS_INF INT_MAX/2

enum VertexStatus { UNEXPLORED, VISITED, VRTX_NOT_FOUND };
enum EdgeStatus { DISCOVERY, BACK, CROSS, EDGE_UNEXPLORED, EDGE_VISITED, EDGE_NOT_FOUND };

using namespace std;

class Graph {

public:
	class Vertex {
		friend ostream& operator <<(ostream& out, Vertex& right) {
			out << right.name;
			return out;
		}
	private:
		string name;
		int ID;
		VertexStatus vtxStatus;
	public:
		Vertex() : name(), ID(-1) {}
		Vertex(string n, int id, VertexStatus vs) :
			name(n), ID(id), vtxStatus(vs) {}
		Vertex(char *pN, int id, VertexStatus vs) :
			name(string(pN)), ID(id), vtxStatus(vs) {}
		Vertex(int id) : ID(id) {}
		string getName() { return name; }
		int getID() { return ID; }
		void setName(string c_name) { name = c_name; }
		void setID(int id) { ID = id; }
		bool operator ==(Vertex v) {
			return ((ID == v.getID()) && (name == v.getName()));
		}
		bool operator !=(Vertex v) {
			return ((ID != v.getID()) || (name != v.getName()));
		}
		void setVtxStatus(VertexStatus vs) { vtxStatus = vs; }
		VertexStatus getVtxStatus() { return vtxStatus; }
	};	// Vertex END

public:
	typedef list<Vertex> VtxList;

	class Edge {
		friend ostream& operator <<(ostream& out, Edge& e) {
			out << " Edge ( ";
			out << setw(2) << setfill('0') << e.vrtx_1.getName();		// setfill 사용하면 되는구만! 아예없는 공백으로 사용하려 해서 그러네
			out << " , ";
			out << setw(2) << setfill('0') << e.vrtx_2.getName();
			out << " , d ( " << e.distance << " ) )";
			return out;
		}
	private:
		Vertex vrtx_1;
		Vertex vrtx_2;
		Vertex* pVrtx_1;
		Vertex* pVrtx_2;
		int distance;
		EdgeStatus edgeStatus;
	public:
		Edge() : pVrtx_1(NULL), pVrtx_2(NULL), distance(PLUS_INF) {}
		Edge(Vertex v1, Vertex v2, int d) :
			vrtx_1(v1), vrtx_2(v2), distance(d), pVrtx_1(NULL), pVrtx_2(NULL), edgeStatus(EDGE_UNEXPLORED) {}
		void endVertices(VtxList& vtxlist) {
			vtxlist.push_back(*pVrtx_1);
			vtxlist.push_back(*pVrtx_2);			// 이해 ~
		}
		Vertex opposite(Vertex v) {
			if (v == *pVrtx_1)
				return *pVrtx_2;
			else if (v == *pVrtx_2)
				return *pVrtx_1;	// 양방향성이 보장되니까 가능한거
			else {
				cout << " ERROR IN OPPOSITE() " << endl;
				return Vertex(NULL);
			}		// v 로 이어지거나 , 이은 Vertex 찾아서 반환.
		}
		Vertex* getpVtrx_1() { return pVrtx_1; }
		Vertex* getpVtrx_2() { return pVrtx_2; }
		Vertex getVtrx_1() { return vrtx_1; }
		Vertex getVtrx_2() { return vrtx_2; }
		int getDistance() { return distance; }
		void setpVrtx_1(Vertex* pV) { pVrtx_1 = pV; }
		void setpVrtx_2(Vertex* pV) { pVrtx_2 = pV; }
		void setDistance(int d) { distance = d; }
		bool operator !=(Edge e) {
			return ((*pVrtx_1 != (e.getVtrx_1())) || (*pVrtx_2 != (e.getVtrx_2())));
		}
		bool operator ==(Edge e) {
			return ((*pVrtx_1 == (e.getVtrx_1())) && (*pVrtx_2 == (e.getVtrx_2())));
		}
		void setEdgeStatus(EdgeStatus es) { edgeStatus = es; }
		EdgeStatus getEdgeStatus() { return edgeStatus; }
	};		// Edge END

public:
	typedef list<Vertex> VtxList;
	typedef list<Edge> EdgeList;
	typedef list<Vertex>::iterator VtxItor;
	typedef list<Edge>::iterator EdgeItor;
private:
	Vertex* pVrtxArray;
	EdgeList* pAdjLstArray;
	int num_vertices;

public:
	Graph() : pVrtxArray(NULL), pAdjLstArray(NULL) {}
	Graph(int num_nodes): pVrtxArray(NULL), pAdjLstArray(NULL) {
		num_vertices = num_nodes;
		
		pVrtxArray = new Vertex[num_vertices];
		for (int i = 0; i < num_nodes; i++)
			pVrtxArray[i] = NULL;
		pAdjLstArray = new EdgeList[num_vertices];
		for (int i = 0; i < num_nodes; i++)
			pAdjLstArray[i].clear();
	}
	~Graph() {
		delete []pVrtxArray;
		delete []pAdjLstArray;
	}
	void vertices(VtxList& vtsLst) {
		vtsLst.clear();
		for (int i = 0; i < getNumVertices(); i++)
			vtsLst.push_back(pVrtxArray[i]);		// Vrtx Array 에 있는 모든요소 리스트에 다 담는듯.
	}
	void edges(EdgeList& egLst) {
		EdgeItor eItor;
		Edge e;

		egLst.clear();
		for (int i = 0; i < getNumVertices(); i++) {
			eItor = pAdjLstArray[i].begin();
			while (eItor != pAdjLstArray[i].end()) {
				e = *eItor;
				egLst.push_back(e);
				eItor++;
			}			// 모든 edge 리스트에 담는 과정인듯.
		}
	}
	bool isAdjacentTo(Vertex v, Vertex w) {
		int vtx_1 = v.getID();
		int vtx_2= w.getID();

		EdgeItor eItor;
		eItor = pAdjLstArray[vtx_1].begin();
		while (eItor != pAdjLstArray[vtx_1].end()) {
			if (eItor->getVtrx_2().getID() == vtx_2)
				return true;
			eItor++;
		}
		return false;			// 연결된놈인지 확인
	}
	void insertVertex(Vertex& v) {
		int vtx_ID;
		vtx_ID = v.getID();
		if (pVrtxArray[vtx_ID] == NULL)
			pVrtxArray[vtx_ID] = v;			// Vertex 삽입.
	}
	void insertEdge(Edge& e) {
		Vertex vtx_1, vtx_2;
		int vtx_1_ID, vtx_2_ID;
		
		vtx_1 = e.getVtrx_1();
		vtx_2 = e.getVtrx_2();
		vtx_1_ID = vtx_1.getID();
		vtx_2_ID = vtx_2.getID();

		if (pVrtxArray[vtx_1_ID] == NULL)
			pVrtxArray[vtx_1_ID] = vtx_1;
		if (pVrtxArray[vtx_2_ID] == NULL)
			pVrtxArray[vtx_2_ID] = vtx_2;

		e.setpVrtx_1(&pVrtxArray[vtx_1_ID]);
		e.setpVrtx_2(&pVrtxArray[vtx_2_ID]);

		pAdjLstArray[vtx_1_ID].push_back(e);
	}
	void eraseEdge(Edge e) {
		int vtx_1_ID = e.getVtrx_1().getID();

		EdgeItor etor;

		etor = pAdjLstArray[vtx_1_ID].begin();

		while (etor != pAdjLstArray[vtx_1_ID].end()) {
			if (etor == pAdjLstArray[vtx_1_ID].end()) {
				etor = pAdjLstArray[vtx_1_ID].erase(etor);
				break;
			}
			etor++;
		}
	}
	void eraseVertex(Vertex v) {
		int vtx_ID = v.getID();
		if (pVrtxArray[vtx_ID] != v)
			return;
		else
			pAdjLstArray[vtx_ID].clear();
		// 그리고 이 노드에서 가는 길 말고 다른 길도 찾아서 삭제하기.
	}
	int getNumVertices() { return num_vertices; }
	void incidentEdges(Vertex v, EdgeList& edges) {
		Edge e;
		EdgeItor eItor;
		int vtx_id = v.getID();
		
		eItor = pAdjLstArray[vtx_id].begin();
		while (eItor != pAdjLstArray[vtx_id].end()) {
			e = *eItor;
			edges.push_front(e);
			eItor++;
		}
	}
	Vertex* getpVrtxArray() { return pVrtxArray; }
	EdgeList* getpAdjLstArray() { return pAdjLstArray; }
	ostream& printGraph(ostream& out) {
		int i, j;
		EdgeItor eItor;
		Edge e;
		
		for (int i = 0; i < getNumVertices(); i++) {
			setw(2);
			out << setw(2) << setfill('0') << i;
			out << "  ";
			eItor = pAdjLstArray[i].begin();
			while (eItor != pAdjLstArray[i].end()) {
				e = *eItor;
				out << e << "   ";
				eItor++;
			}
			out << endl;
		}
		return out;
	}
};

#endif