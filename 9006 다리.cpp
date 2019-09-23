// // #include <cstdio>
// // #include <vector>
// // #include <algorithm>

// // using namespace std;

// // typedef long long ll;

// // void print(vector<int> v){
// // 	for(int i = 0 ; i < v.size() ; i++){
// // 		printf("%d ", v[i]);
// // 	}
// // 	printf("\n");
// // }

// // ll func(vector<int> a, vector<int> b, int val){
// // 	ll sum = 0;
// // 	int A = a.size();
// // 	int B = b.size();
// // 	for(int i = 0 ; i < A ; i++){
// // 		sum += (B * (abs(a[i] - val)));
// // 	}
// // 	for(int i = 0 ; i < B ; i++){
// // 		sum += (A * (abs(b[i] - val)));
// // 	}
// // 	return sum;
// // }

// // int main(){
// // 	int t;
// // 	scanf("%d", &t);
// // 	while(t--){
// // 		ll result=0x7fffffffffffffff;
// // 		int n, m;
// // 		int mid;
// // 		int hi, lo;
// // 		double val;
// // 		scanf("%d%d", &n, &m);
// // 		vector<int> a(n), b(m), c(n+m);

// // 		for(int i = 0 ; i < n ; i++){
// // 			scanf("%d", &a[i]);
// // 			c[i] = a[i];
// // 		}
// // 		for(int i = 0 ; i < m ; i++){
// // 			scanf("%d", &b[i]);
// // 			c[n+i] = b[i];
// // 		}

// // 		sort(c.begin(), c.end());
// // 		c.erase(unique(c.begin(), c.end()), c.end());
// // 		// for(int i = 0 ; i < c.size() ; i++){
// // 		// 	ll d = func(a, b, c[i]);
// // 		// 	if(result > d){
// // 		// 		result = d;
// // 		// 		val = c[i];
// // 		// 	}
// // 		// }
// // 		lo = c[0]; hi = c[n+m-1];
// // 		while(hi - lo > 3){
// // 			if(func(a, b, lo) < func(a, b, hi)){
// // 				hi = (2*hi+lo) / 3;
// // 			}
// // 			if(func(a, b, lo) > func(a, b, hi)){
// // 				lo = (hi+2*lo) / 3;
// // 			}
// // 		}
// // 		for(; hi >= lo ; hi--){
// // 			ll d = func(a, b, hi);
// // 			if(result >= d){
// // 				result = d;
// // 				val = hi;
// // 			}	
// // 		}



// // 		printf("%.1f\n", val);	
// // 	}
// // }

// #include <cstdio>
// #include <vector>
// #include <algorithm>

// using namespace std;

// typedef long long ll;

// void print(vector<int> v){
// 	for(int i = 0 ; i < v.size() ; i++){
// 		printf("%d ", v[i]);
// 	}
// 	printf("\n");
// }

// ll func(vector<int> a, vector<int> b, int val){
// 	ll sum = 0;
// 	int A = a.size();
// 	int B = b.size();
// 	for(int i = 0 ; i < A ; i++){
// 		sum += (B * (abs(a[i] - val)));
// 	}
// 	for(int i = 0 ; i < B ; i++){
// 		sum += (A * (abs(b[i] - val)));
// 	}
// 	return sum;
// }

// int main(){
// 	int t;
// 	scanf("%d", &t);
// 	while(t--){
// 		ll result=0x7fffffffffffffff;
// 		int n, m;
// 		int mid;
// 		int hi, lo;
// 		double val;
// 		scanf("%d%d", &n, &m);
// 		vector<int> a(n), b(m), c(n+m);

// 		for(int i = 0 ; i < n ; i++){
// 			scanf("%d", &a[i]);
// 			c[i] = a[i];
// 		}
// 		for(int i = 0 ; i < m ; i++){
// 			scanf("%d", &b[i]);
// 			c[n+i] = b[i];
// 		}

// 		sort(a.begin(), a.end());
// 		sort(b.begin(), b.end());
// 		sort(c.begin(), c.end());
// 		c.erase(unique(c.begin(), c.end()), c.end());
// 		for(int i = 0 ; i < c.size() ; i++){
// 			ll d = func(a, b, c[i]);
// 			if(result > d){
// 				result = d;
// 				val = c[i];
// 			}
// 			else{
// 				break;
// 			}
// 		}
// 		// lo = c[0]; hi = c[n+m-1];
// 		// while(hi - lo > 3){
// 		// 	if(func(a, b, lo) < func(a, b, hi)){
// 		// 		hi = (2*hi+lo) / 3;
// 		// 	}
// 		// 	if(func(a, b, lo) > func(a, b, hi)){
// 		// 		lo = (hi+2*lo) / 3;
// 		// 	}
// 		// }
// 		// for(; hi >= lo ; hi--){
// 		// 	ll d = func(a, b, hi);
// 		// 	if(result >= d){
// 		// 		result = d;
// 		// 		val = hi;
// 		// 	}
			
// 		// }



// 		printf("%.1f\n", val);	
// 	}
// }

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<int> v(n+m);
		for(int i = 0 ; i < n ; i++){
			cin >> v[i];
		}
		for(int i = n ; i < n+m ; i++){
			cin >> v[i];
		}

		sort(v.begin(), v.end());
		for(int i = 0 ; i < v.size() ; i++){
			cout << v[i] << " ";
		}
		printf("%.1f\n", (double)v[(n+m-1)/2]);
	}
}