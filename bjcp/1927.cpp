#include <iostream>

using namespace std;

int heap[100001];
int h_size, n;

void	insert_min_heap(int num)
{
	int child;
	h_size++;
	child = h_size;
	while (child > 1)
	{
		if (num < heap[child / 2])
			heap[child] = heap[child / 2];
		else
			break ;
		child /= 2;
	}
	heap[child] = num;
}

void	delete_min_heap(void)
{
	int child, parent, tmp;
	if (h_size == 0)
	{
		cout << "0" << '\n';
		return ;
	}
	cout << heap[1] << '\n';
	parent = 1;
	child = 2;
	tmp = heap[h_size];
	h_size--;
	while (child <= h_size)
	{
		if (child < h_size && (heap[child] > heap[child + 1]))
			child++;
		if (tmp < heap[child])
			break ;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = tmp;
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	int num;
	heap[0] = 0;
	h_size = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num == 0)
			delete_min_heap();
		else
			insert_min_heap(num);
	}
}