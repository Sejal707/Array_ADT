#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct array
{
	int* A;
	int size;
	int length;
};

void display(struct array a)
{
	int i;
	for (i = 0; i < a.length; i++)
		printf("%d ", a.A[i]);
	printf("\n");
}

void add(struct array* a, int x)
{
	if (a->length >= a->size)
	{
	
	printf("Array is Full! Cannot add element.\n");
	return;
}
	else
	{
		a->A[a->length++] = x;
	}
}

void insert(struct array* a, int index, int x)
{
	if (index<0 || index>a->length)
	{
		printf("Invalid index!\n");
		return;
	}
	if (a->length >= a->size)
	{
		printf("Array is Full! Cannot insert element.\n");
		return;
	}
	for (int i = a->length; i > index; i--)
	{
		a->A[i] = a->A[i - 1];
	}
	a->A[index] = x;
	a->length++;
}

void delete(struct array* a, int index)
{
	if (index<0 || index>=a->length)
	{
		printf("Invalid index!\n");
		return;
	}
	if (a->length == 0)
	{
		printf("Array is Empty! Cannot delete element.\n");
		return;
	}
	else
	{
		int x = a->A[index];
		for (int i = index; i < a->length - 1; i++)
		{
			a->A[i] = a->A[i + 1];
		}
		printf("Element deleted is %d\n", x);
		a->length--;
	}
}

void linear_search(struct array a, int e)
{
	for (int i = 0; i < a.length; i++)
	{
		if (a.A[i] == e)
		{
			printf("Element found at %d index\n", i);
			return;
		}
	}
	printf("Element not found!\n");
}

void binary_search(struct array a, int e)
{
	
	int l = 0,h=a.length-1,mid;
	while (l <= h)
	{
		mid = (l + h) / 2;
		if (e == a.A[mid])
		{
			printf("Element found at %d index\n", mid);
			return;
		}
		else if (e < a.A[mid])
		{
			h = mid - 1;
		}
		else
			l = mid + 1;
	}
	printf("Element not found!\n");
}

void get(struct array a, int index)
{
	if (index >= 0 && index < a.length)
	{
		printf("Element is %d\n", a.A[index]);
	}
	else
	{
		printf("Invalid index!\n");
	}
}

void set(struct array* a, int index, int e)
{
	if (index >= 0 && index < a->length)
	{
		int o = a->A[index];
		a->A[index] = e;
		printf("Element %d changed to %d\n", o,e);
	}
	else
	{
		printf("Invalid index!\n");
	}
}

void maximum(struct array a)
{
	int max = a.A[0];
	for (int i = 1; i < a.length; i++)
	{
		if (a.A[i] > max)
			max = a.A[i];
	}
	printf("MAXIMUM : %d\n", max);
}

void minimum(struct array a)
{
	int min = a.A[0];
	for (int i = 1; i < a.length; i++)
	{
		if (a.A[i] < min)
			min = a.A[i];
	}
	printf("MINIMUM : %d\n", min);
}

int sum(struct array a)
{
	int s = 0;
	for (int i = 0; i < a.length; i++)
	{
		s += a.A[i];
	}
	printf("Sum is %d\n", s);
	return s;
}

void avg(struct array a)
{
	if (a.length == 0) {
		printf("Cannot calculate average. Array is empty.\n");
		return;
	}
	printf("Average is %.2f\n",(float)sum(a)/a.length);
}

void rev(struct array* a)
{
	for (int i = 0, j = a->length - 1; i < j; i++, j--)
	{
		int temp = a->A[i];
		a->A[i] = a->A[j];
		a->A[j] = temp;
	}
}

void left(struct array* a)
{
	int first = a->A[0];
	for (int i = 0; i < a->length-1; i++)
	{
		a->A[i] = a->A[i + 1];
	}
	a->A[a->length - 1] = first;
}

void right(struct array* a)
{
	int last = a -> A[a->length - 1];
	for (int i = a->length-1;i>0; i--)
	{
		a->A[i] = a->A[i-1];
	}
	a->A[0] = last;
}

struct array sort(struct array* a)
{
	for (int i = 0; i < a->length; i++)
	{
		for (int j = i + 1; j < a->length; j++)
		{
			if (a->A[i] > a->A[j])
			{
				int x = a->A[i];
				a->A[i] = a->A[j];
				a->A[j] = x;
			}
		}
	}
	return *a;
}

void union_opr(struct array a, struct array b)
{
	int i=0, j=0, k = 0;
	sort(&a);
	sort(&b);
	struct array c;
	c.size = a.length + b.length;
	c.A = (int*)malloc(c.size * sizeof(int));
	while (i < a.length && j < b.length)
	{
		if (a.A[i] < b.A[j])
			c.A[k++] = a.A[i++];
		else if (a.A[i] > b.A[j])
			c.A[k++] = b.A[j++];
		else
		{
			c.A[k++] = a.A[i++];
			j++;
		}
	}
	for (; i < a.length; i++)
		c.A[k++] = a.A[i];
	for (; j < b.length; j++)
		c.A[k++] = b.A[j];
	c.length = k;
	
	printf("Union : ");
	for (int i = 0; i < c.length; i++)
	{
		printf("%d ", c.A[i]);
	}
	printf("\n");
	free(c.A);
}
void intersection_opr(struct array a, struct array b)
{
	int i = 0, j = 0, k = 0;
	sort(&a);
	sort(&b);
	struct array c;
	c.size = a.length + b.length;
	c.A = (int*)malloc(c.size * sizeof(int));
	while (i < a.length && j < b.length)
	{
		if (a.A[i] < b.A[j])
			i++;
		else if (a.A[i] > b.A[j])
			j++;
		else if (a.A[i] == b.A[j])
		{
			c.A[k++] = a.A[i++];
			j++;
		}
		
	}
	c.length = k;
	if (k == 0)
		printf("No common elements! Intesection Empty.\n");
	else
	{
		printf("Intersection : ");
		for (int i = 0; i < c.length; i++)
		{
			printf("%d ", c.A[i]);
		}
		printf("\n");
	}
	free(c.A);
}
void diff_opr(struct array a, struct array b)
{
	int i = 0, j = 0, k = 0;
	sort(&a);
	sort(&b);
	struct array c;
	c.size = a.length + b.length;
	c.A = (int*)malloc(c.size * sizeof(int));
	while (i < a.length && j < b.length)
	{
		if (a.A[i] < b.A[j])
			c.A[k++] = a.A[i++];
		else if (a.A[i] > b.A[j])
			j++;
		else
		{
			i++,j++;
		}
	}
	for (; i < a.length; i++)
		c.A[k++] = a.A[i];
		c.length = k;

	printf("Difference: ");
	for (int i = 0; i < c.length; i++)
	{
		printf("%d ", c.A[i]);
	}
	printf("\n");
	free(c.A);
}
void merge(struct array a, struct array b)
{
	int i = 0, j = 0, k = 0;
	sort(&a);
	sort(&b);
	struct array c;
	c.size = a.length + b.length;
	c.A = (int*)malloc(c.size * sizeof(int));
	while (i < a.length && j < b.length)
	{
		if (a.A[i] < b.A[j])
			c.A[k++] = a.A[i++];
		else 
			c.A[k++] = b.A[j++];
	}
	for (; i < a.length; i++)
		c.A[k++] = a.A[i];
	for (; j < b.length; j++)
		c.A[k++] = b.A[j];
	c.length = k;

	printf("Merged Array : ");
	for (int i = 0; i < c.length; i++)
	{
		printf("%d ", c.A[i]);
	}
	printf("\n");
	free(c.A);
}
void manage_arrays()
{
	int element, idx,x,y;
	struct array* arrays = NULL;
	int arr_count = 0, op = 0, choice = 0;
	while (op != 5)
	{
		printf("\nChoose an option: \n1.Create New Array\n2.Show All Arrays\n3.Manage an Existing Array\n4.Set operations\n5.Exit\n");
		printf("Enter option: ");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			create_new_array:
			arr_count++;
			arrays = (struct array*)realloc(arrays, arr_count * sizeof(struct array));
			struct array* n_array = &arrays[arr_count - 1];
			printf("Enter array size: ");
			scanf("%d", &n_array->size);
			n_array->A = (int*)malloc(n_array->size * sizeof(int));
			n_array->length = 0;
			int n;
			do {
				printf("Enter number of elements: ");
				scanf("%d", &n);
				if (n > n_array->size)
					printf("Number of elements exceeds array size!\n");
			} while (n > n_array->size);
			printf("Enter all elements : \n");
			for (int i = 0; i < n; i++)
				scanf("%d", &n_array->A[i]);
			n_array->length = n;
			printf("Array %d created successfully!\n", arr_count);
			break;
		case 2:
			if (arr_count == 0)
			{
				printf("No Array is created yet!\n");
				break;
			}
			printf("\nDisplaying all arrays: \n");
			for (int i = 0; i < arr_count; i++)
			{
				printf("Array %d : ", i + 1);
				display(arrays[i]);
			}
			break;
		case 3:
			if (arr_count == 0) {
				printf("No arrays to manage! Create a new array first.\n");
				break;
			}
			int arr_no = 0;
			do
			{
				printf("Enter the Array number to manage: ");
				scanf("%d", &arr_no);
				if (arr_no<1 || arr_no>arr_count)
				{
					printf("Invalid Array Number!\n");
				}
			} while (arr_no<1 || arr_no>arr_count);
			struct array* m_array = &arrays[arr_no - 1];
			while (choice != 17)
			{
				printf("\nChoose an option: \n1.Display\n2.Add\n3.Insert\n4.Delete\n5.Linear search\n6.Binary search\n7.Get element\n8.Set element\n9.Maximum\n10.Minimum\n11.Sum\n12.Average\n13.Reverse\n14.Left Rotate\n15.Right Rotate\n16.Sort\n17.Exit\n");
				printf("\nEnter option: ");
				scanf("%d", &choice);
				printf("\n");
				switch (choice)
				{
				case 1:
					display(*m_array);
					break;
				case 2:
					printf("Enter Element to add at end : ");
					scanf("%d", &element);
					add(m_array, element);
					break;
				case 3:
					printf("Enter index and element: ");
					scanf("%d %d", &idx, &element);
					insert(m_array, idx, element);
					break;
				case 4:
					printf("Enter index of deletion: ");
					scanf("%d", &idx);
					delete(m_array, idx);
					break;
				case 5:
					printf("Enter element to search: ");
					scanf("%d", &element);
					linear_search(*m_array, element);
					break;
				case 6:
					printf("Enter element to search: ");
					scanf("%d", &element);
					binary_search(*m_array, element);
					break;
				case 7:
					printf("Enter index: ");
					scanf("%d", &idx);
					get(*m_array, idx);
					break;
				case 8:
					printf("Enter element: ");
					scanf("%d", &element);
					printf("Enter index: ");
					scanf("%d", &idx);
					set(m_array, idx, element);
					display(*m_array);
					break;
				case 9:
					maximum(*m_array);
					break;
				case 10:
					minimum(*m_array);
					break;
				case 11:
					sum(*m_array);
					break;
				case 12:
					avg(*m_array);
					break;
				case 13:
					rev(m_array);
					display(*m_array);
					break;
				case 14:
					left(m_array);
					display(*m_array);
					break;
				case 15:
					right(m_array);
					display(*m_array);
					break;
				case 16:
					sort(m_array);
					display(*m_array);
					break;
				case 17:
					break;
				default:
					printf("Enter valid option!\n");
					break;
				}
			}
			break;
		case 4:
			choice = 0;
			if (arr_count < 2)
			{
				printf("Minimum 2 arrays required! Create a new array.\n");
				goto create_new_array;
			}
			do {
				printf("Enter first Array number:  ");
				scanf("%d", &x);
				if (x <= 0 || x > arr_count)
				{
					printf("Array %d doesn't exist! Please enter valid number!\n", x);
				}
			} while (x <= 0 || x > arr_count);
			do{
				printf("Enter second Array number:  ");
				scanf("%d", &y);
				if (y <= 0 || y > arr_count)
				{
					printf("Array %d doesn't exist! Please enter valid number!\n", y);
				}
				if (x == y)
					printf("Array %d already selected! Please select another array!\n", y);
			} while (y <= 0 || y > arr_count ||y==x);
			while (choice != 5) {
				printf("Choose Operation: \n1.Union\n2.Intersection\n3.Difference\n4.Merge\n5.Exit\n");
				printf("Enter Choice: ");
				scanf("%d", &choice);
			
				switch (choice)
				{
				case 1:
					union_opr(arrays[x-1], arrays[y-1]);
					break;
				case 2:
					intersection_opr(arrays[x-1], arrays[y-1]);
					break;
				case 3:
					diff_opr(arrays[x-1], arrays[y-1]);
					break;
				case 4:
					merge(arrays[x-1], arrays[y-1]);
					break;
				case 5:
					break;
				default:
					printf("Enter valid option!\n");
					break;
				}
			
			}
			choice = 0;
			break;
		case 5:
			for (int i = 0; i < arr_count; i++) {
				free(arrays[i].A);
			}
			free(arrays);
			break;
		default:
			printf("Enter valid option!\n");
			break;
		}
	}
}
int main()
{
	manage_arrays();
	return 0;
}
