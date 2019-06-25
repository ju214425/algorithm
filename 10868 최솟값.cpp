#include <cstdio>
#include <vector>

#define l_node (node << 1)
#define r_node (l_node + 1)
#define mid ((begin + end) >> 1)

using namespace std;


class SegmentTree{
public:
	vector<int> arr, tree;
	int biggest;
	int smallest;
	SegmentTree(int size){
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
		//out of bound
		if(end < l_pos or r_pos < begin) return biggest;
		// in the bound
		if(l_pos <= begin and end <= r_pos) return tree[node];
		// none of above
		return min(query(l_node, begin, mid, l_pos, r_pos),
					query(r_node, mid+1, end, l_pos, r_pos));
	}
};

int min(int a, int b){
	return a > b ? b : a;
}


int main(){
	int N, M, A, B;
	scanf("%d %d", &N, &M);
	SegmentTree segment_tree(N);

	for(int i = 1 ; i <= N ; ++i){
		scanf("%d", &segment_tree.arr[i]);
	}

	segment_tree.init(1, 1, N);

	for(int i = 1 ; i <= M ; ++i){
		scanf("%d %d", &A, &B);
		printf("%d\n", segment_tree.query(1, 1, N, A, B));
	}

	return 0;
}