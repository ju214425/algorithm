#include <cstdio>
#include <vector>

#define l_node (node << 1)
#define r_node (l_node + 1)
#define mid ((begin + end) >> 1)

using namespace std;

int min(int, int);

class SegmentTree_min{
public:
	vector<int> arr, tree;
	int biggest;
	int smallest;
	SegmentTree_min(int size){
		arr.resize(size + 1);
		tree.resize(size * 4);
		biggest = 0x7fffffff;
		smallest = -1;
	}

	int init(int node, int begin, int end){
		if(begin == end) return tree[node] = arr[begin];
		return tree[node] = min(init(l_node, begin, mid), init(r_node, mid+1, end));
	}

	int query(int node, int begin, int end, int l_pos, int r_pos){
		if(end < l_pos or r_pos < begin) return biggest;
		if(l_pos <= begin and end <= r_pos) return tree[node];
		return min(query(l_node, begin, mid, l_pos, r_pos),
					query(r_node, mid+1, end, l_pos, r_pos));
	}
};

class SegmentTree_max{
public:
	vector<int> arr, tree;
	int biggest;
	int smallest;
	SegmentTree_max(int size){
		arr.resize(size + 1);
		tree.resize(size * 4);
		biggest = 0x7fffffff;
		smallest = -1;
	}

	int init(int node, int begin, int end){
		if(begin == end) return tree[node] = arr[begin];
		return tree[node] = max(init(l_node, begin, mid), init(r_node, mid+1, end));
	}

	int query(int node, int begin, int end, int l_pos, int r_pos){
		if(end < l_pos or r_pos < begin) return smallest;
		if(l_pos <= begin and end <= r_pos) return tree[node];
		return max(query(l_node, begin, mid, l_pos, r_pos),
					query(r_node, mid+1, end, l_pos, r_pos));
	}
};

int min(int a, int b){
	return a > b ? b : a;
}

int max(int a, int b){
	return a > b ? a : b;
}


int main(){
	int N, M, A, B;
	scanf("%d %d", &N, &M);
	SegmentTree_min segment_tree_min(N);
	SegmentTree_max segment_tree_max(N);

	for(int i = 1 ; i <= N ; ++i){
		int value;
		scanf("%d", &value);
		segment_tree_min.arr[i] = value;
		segment_tree_max.arr[i] = value;
	}

	segment_tree_min.init(1, 1, N);
	segment_tree_max.init(1, 1, N);

	for(int i = 1 ; i <= M ; ++i){
		scanf("%d %d", &A, &B);
		printf("%d %d\n", 
			segment_tree_min.query(1, 1, N, A, B),
			segment_tree_max.query(1, 1, N, A, B));
	}

	return 0;
}