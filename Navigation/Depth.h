#pragma once
#include"graph.h"

class DepthFirstSearch {
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

protected:
	void initialize() {
		int num_nodes = graph.getNumVertices();
		Vertex vtx_1, vtx_2;
		int vtx_1_ID, vtx_2_ID;
		
		done = false;
		
		for (int i = 0; i < num_nodes; i++)
			pVrtxStatus[i] = UNEXPLORED;

		for (int i = 0; i < num_nodes; i++)
			for (int j = 0; j < num_nodes; j++)
				ppEdgeStatus[i][j] = EDGE_UNEXPLORED;
	}
	void dfsTraversal(Vertex& v, Vertex& target, VertexList& path) {
		visit(v);
		if (v == target) {
			done = true;
			return;
		}
		EdgeList incidentEdges;
		incidentEdges.clear();
		graph.incidentEdges(v, incidentEdges);		// Vertex �� �����մ� �� Ž��
		EdgeItor pe = incidentEdges.begin();
		while (!isDone() && (pe != incidentEdges.end())) {
			Edge e = *pe++;
			EdgeStatus eStat = getEdgeStatus(e);
			if (eStat == EDGE_UNEXPLORED) {
				visit(e);
				Vertex w = e.opposite(v);
				if (!isVisited(w)) {				// ���� ���� �� ���� �湮�Ȱ� �ƴϸ�
					//traverseDiscovery(e,v);
					path.push_back(w);		// �༱���� �߰�.
					setEdgeStatus(e, DISCOVERY);		// �ش� ���� Ž�� �Ϸ�.
					if (!isDone()) {
						dfsTraversal(w, target, path);		// �ٵ� ���� �ƴϸ� ? -> �� ��ġ���� �ٽ� ���.
						if (!isDone()) {
							//traversBack(e,v);
							Vertex last_pushed = path.back();		// ���̻� ������ ���µ��� ���� �ȳ��� �׳� �ٽ� �ǵ��ư���.
							path.pop_back();
						}
					}
				}
				else {								// �̹� �湮�� ���̾�����.
					setEdgeStatus(e, BACK);
				}
			}
		}
	}
	//virtual void traversDiscovery(const Edge& e, const Vertex& from) {
		//?
	//}
	//virtual void traversBack(const Edge& e, const Vertex& from) {
		//?
	//}
	//virtual void finishVisit(const Vertex& v) {
		//?
	//}

	virtual bool isDone() const { return done; }
	void visit(Vertex& v) {
		pVrtxStatus[v.getID()] = VISITED;
		v.setVtxStatus(VISITED);
	}
	void visit(Edge& e) {
		ppEdgeStatus[e.getVtrx_1().getID()][e.getVtrx_2().getID()] = EDGE_VISITED;
		e.setEdgeStatus(EDGE_VISITED);
	}
	void unvisit(Vertex& v) {
		pVrtxStatus[v.getID()] = UNEXPLORED;
		v.setVtxStatus(UNEXPLORED);
	}
	void unvisit(Edge& e) {
		ppEdgeStatus[e.getVtrx_1().getID()][e.getVtrx_2().getID()] = EDGE_UNEXPLORED;
		e.setEdgeStatus(EDGE_UNEXPLORED);
	}
	bool isVisited(Vertex& v) {
		return (pVrtxStatus[v.getID()] == VISITED);
	}
	bool isVisited(Edge& e) {
		return (ppEdgeStatus[e.getVtrx_1().getID()][e.getVtrx_2().getID()] == EDGE_VISITED);
	}
	void setEdgeStatus(Edge& e, EdgeStatus es) {
		ppEdgeStatus[e.getVtrx_1().getID()][e.getVtrx_2().getID()] = es;
		e.setEdgeStatus(es);
	}
	EdgeStatus getEdgeStatus(Edge& e) {
		return ppEdgeStatus[e.getVtrx_1().getID()][e.getVtrx_2().getID()];
	}
public:
	DepthFirstSearch(Graph& g) : graph(g) , done(false) {
		int num_nodes = graph.getNumVertices();
		pVrtxStatus = new VertexStatus[num_nodes];
		for (int i = 0; i < num_nodes; i++)
			pVrtxStatus[i] = UNEXPLORED;

		ppEdgeStatus = new EdgeStatus*[num_nodes];
		for (int i = 0; i < num_nodes; i++)
			ppEdgeStatus[i] = new EdgeStatus[num_nodes];
		for (int i = 0; i < num_nodes; i++)
			for (int j = 0; j < num_nodes; j++)
				ppEdgeStatus[i][j] = EDGE_UNEXPLORED;

		ppConnectivity = new int*[num_nodes];
		for (int i = 0; i < num_nodes; i++)
			ppConnectivity[i] = new int[num_nodes];
		for (int i = 0; i < num_nodes; i++)
			for (int j = 0; j < num_nodes; j++)
				ppConnectivity[i][j] = PLUS_INF;

		Vertex vtx_1, vtx_2;
		int vtx_1_ID, vtx_2_ID;
		EdgeList edges;
		edges.clear();
		graph.edges(edges);
		
		for (EdgeItor pe = edges.begin(); pe != edges.end(); ++pe) {
			vtx_1 = (*pe).getVtrx_1();
			vtx_1_ID = vtx_1.getID();
			vtx_2 = (*pe).getVtrx_2();
			vtx_2_ID = vtx_2.getID();
			ppConnectivity[vtx_1_ID][vtx_2_ID] = (*pe).getDistance();
		}		// �����ϴ� ��� �����鿡�� �Ÿ� ���� �ʱ�ȭ�ϳ�

		for (int i = 0; i < num_nodes; i++)
			ppConnectivity[i][i] = 0;		// �ڱ� �ڽ����� ���°� 0
		
	}
	void findPath(Vertex& s, Vertex& t, VertexList& path) {
		initialize();
		done = false;
		dfsTraversal(s, t, path);
	}
	Graph& getGraph() {	return graph;	}
	void showConnectivity(ostream& fout) {
		int num_nodes = graph.getNumVertices();
		int dist;
		
		fout << "Connectivitiy of graph : " << endl;
		fout << "     ��";
		for (int i = 0; i < num_nodes; i++) {
			fout << "   " << setw(2) << setfill('0') << i;
		}
		fout << endl;
		
		fout << "-----+---------------------------------------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < num_nodes; i++) {
			fout << "  " << setw(2) << setfill('0') << right << i << "��";
			for (int j = 0; j < num_nodes; j++) {
				dist = ppConnectivity[i][j];
				if (dist == PLUS_INF)
					fout << " +oo";
				else {
					fout << setw(6) << setfill(' ') << dist;
				}
			}
			fout << endl;
		}
	}
	
private:
	VertexStatus* pVrtxStatus;			// �̰� �迭 ���ѰŰ�
	EdgeStatus** ppEdgeStatus;		// �׳� 2���� �迭 ���Ѱſ���
	int** ppConnectivity;
};