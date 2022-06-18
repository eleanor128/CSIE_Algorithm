#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

// A structure to represent a Point in 2D plane
struct Point
{
	int x, y;
};

int compareX(const void* a, const void* b)  // 對X軸 sort
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x - p2->x);
}

int compareY(const void* a, const void* b) // 對Y軸 sort 
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->y - p2->y);
}


float distance(Point p1, Point p2) // 兩點距離 
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) );
}


 float bruteForce(Point P[], int n) //暴力解 
{
	float min = FLT_MAX; // 先設成無限大 
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if (distance(P[i], P[j]) < min)
				min = distance(P[i], P[j]);
	return min;
} 


float min(float x, float y)
{
	if(x<y){
		return x;
	}
	else{
		return y;
	}
}

float stripClosest(Point strip[], int size, float d)
{
	float min = d; 

	qsort(strip, size, sizeof(Point), compareY);

	for (int i = 0; i < size; ++i)
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
			if (distance(strip[i],strip[j]) < min)
				min = distance(strip[i], strip[j]);

	return min;
}

float closestUtil(Point P[], int n)
{
	if (n <= 49)
		return bruteForce(P, n);

	int mid = n/2;
	Point midPoint = P[mid];

	float dleft = closestUtil(P, mid);
	float dright = closestUtil(P + mid, n-mid);
  
	float d = min(dleft, dright);

	Point strip[n];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(P[i].x - midPoint.x) < d)
			strip[j] = P[i], j++;

	return min(d, stripClosest(strip, j, d) );
}

float closest(Point P[], int n)
{
	qsort(P, n, sizeof(Point), compareX);
	return closestUtil(P, n);
}

int main()
{
	int input_size;
	scanf("%d",&input_size);
	Point P[input_size] = {{0,0},{0,0}};
	for(int i=0;i<input_size;i++){
		scanf("%d %d",&P[i].x, &P[i].y);	
	}

	printf("%.3f ", closest(P, input_size));
	return 0;
}
