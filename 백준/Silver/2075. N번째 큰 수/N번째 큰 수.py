import heapq

heap = []
n = int(input())

for _ in range(n):
    arr = map(int, input().split())
    for num in arr:
        
        if len(heap) < n:
            heapq.heappush(heap, num)
        else:
            if heap[0] < num:
                heapq.heappop(heap)
                heapq.heappush(heap, num)
                
print(heap[0])