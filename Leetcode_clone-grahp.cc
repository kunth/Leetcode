/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	map<int, UndirectedGraphNode*>dm;
	map<int, vector<UndirectedGraphNode*>>raw;
	void dfs_travel(UndirectedGraphNode *node)
	{
		if(dm.find(node->label)==dm.end())
		{
			UndirectedGraphNode* nd = new UndirectedGraphNode(node->label);
			dm[node->label] = nd;
			raw[node->label] = node->neighbors;
			for(int i = 0; i<node->neighbors.size(); ++i)
			{
				if(dm.find(node->neighbors[i]->label)==dm.end())
					dfs_travel(node->neighbors[i]);
			}
		}
	}

	void dfs_assign(UndirectedGraphNode *node)
	{
		if(dm[node->label]->neighbors.empty())
		{
			for(int i = 0; i<raw[node->label].size(); ++i)
			{
				dm[node->label]->neighbors.push_back(dm[raw[node->label][i]->label]);
				if(dm[node->neighbors[i]->label]->neighbors.empty())
					dfs_assign(dm[node->neighbors[i]->label]);
			}
		}
	}

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(!node)
			return node;
		dfs_travel(node);
		dfs_assign(node);
		return dm[node->label];
	}
};
