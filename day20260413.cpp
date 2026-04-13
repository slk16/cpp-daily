//
//#include <stdio.h>
//#include <stdlib.h>
//#include <random>
//
//typedef struct vector {
//	int size;
//	int count;	
//	int* data;
//}vector;
//
//vector* getNewVector(int n) {
//	vector* p = (vector*)malloc(sizeof(vector));
//	p ->count = 0;
//	p ->size = n;
//	p ->data = (int*)malloc(sizeof(int) * n);
//	return p;
//}
//int insert(vector* v, int pos, int val) {
//	if (pos < 0 || pos > v->count) return 0;
//	if (v->count == v->size) return 0;
//	for (int i = v->count - 1; i >= pos; --i)	
//	{
//		v->data[i + 1] = v->data[i];
//	}
//	v->data[pos] = val;
//	++v->count;
//	return 1;
//}
//int erase(vector* v, int pos) {
//	if (pos < 0 || pos >= v->count) return 0;
//	if (v ->count == 0) return 0;
//	for (int i = pos; i < v->count - 1; ++i) {
//		v->data[i] = v->data[i + 1];
//	}
//	--v->count;
//	return 1;
//}
//void clear(vector* p ) {
//	if (p == NULL)
//		return ;
//	free(p->data);
//	free(p);
//	return ;
//}
//void output_vector(vector* v)
//{
//	int len = 0;
//	for (int i = 0; i < v->size; ++i) {
//		len += printf("%3d", i);
//	}
//	printf("\n");
//	for (int i = 0; i < len; ++i) printf("-");
//	printf("\n");
//	for (int i = 0; i < v->count; ++i) 
//	{
//		printf("%3d", v->data[i]);
//	}
//	printf("\n\n\n");
//}
//#include <iostream>
//int main()
//{
//	std::default_random_engine e(std::random_device{}());
//	std::uniform_int_distribution u;
//
//	#define MAX_OP 20
//	vector* v = getNewVector(MAX_OP);
//	int pos, val;
//	for (int i = 0; i < MAX_OP; ++i) {
//		int op = u(e) % 4;
//		switch(op) {
//			case 0: 
//			case 1:
//			case 2:
//				pos = u(e) %  (v->count + 2);
//				val = u(e) % 100;
//				
//				std::cout << "\033[1;33m" << "insert " << "\033[0m" << val << " at " << pos << " to vector = " << insert(v, pos, val)<< std::endl;
//				break;
//			case 3:
//				pos = u(e) % (v->count + 2); 
//				std:: cout << "\033[1;33m" << "erase " << "\033[0m" << "item at " << pos << " = " << erase(v, pos) << std::endl;  
//		}
//		output_vector(v);
//	}
//	clear(v);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//typedef struct vector{
//	int size;
//	int count;
//	int* data;
//}vector;
//vector* getNewVector(int n) {
//	if (n < 0) return NULL;
//	vector* p = (vector*)malloc(sizeof (vector));
//	p->size = n;
//	p->count = 0;
//	p->data = (int*)malloc(sizeof(int) * n);
//	return p;
//}
//int expand(vector* p) {
//	if (p == NULL) return 0;
//	int* tp =  (int*)realloc(p, 2 * p->size);
//	if (tp == NULL) return 0;
//	p->data = tp;
//	p->size *= 2;
//	return 1;
//}
//int insert(vector* p, int pos, int val) {
//	if (p == NULL) return 0;
//	if (pos < 0 || pos > p->count) return 0;
//	if (p -> count == p-> size && !expand(p)) return 0;
//	for (int i = p->count - 1; i >= pos; --i) {
//		p->data[i + 1] = p->data[i];
//	}
//	p->data[pos] = val;
//	p->count += 1;
//	return 1;
//}
//int erase(vector* p, int pos) {
//	if (p == NULL) return 0;
//	if (pos < 0 || pos > p -> count - 1) return 0;
//	for (int i = pos; i < p -> count - 1; ++i) {
//		p->data[i] = p -> data[i + 1];
//	}
//	p->count -= 1;
//	return 1;
//}
//int clear(vector* p) {
//	if (p == NULL) return 0;
//	free(p->data);
//	free(p);
//	return 1;
//}
//void outputVector(vector* p, int maxLen) {
//	if (p == NULL) return ;
//	int len = 0;
//	for (int i = 0; i < maxLen; ++i) {
//		len += printf("%3d", i);
//	}
//	printf("\n");
//	for (int i = 0; i < len; ++i) {
//		printf("-");
//	}
//	printf("\n");
//	for (int i = 0; i < p -> count; ++i) {
//		printf("%3d", p->data[i]);
//	}
//	printf("\n\n\n");
//	return ;
//}
//
//#define MAX_OP 30
//#define TC_END "\033[0m"
//#define TC_RED "\033[1;31m"
//#define TC_GRN "\033[1;32m"
//#define TC_YLW "\033[1;33m"
//#define TC_BLU "\033[1;34m"
//
//#define B(b) ((b)? TC_GRN "true" TC_END : TC_RED "False" TC_END)
//int main()
//{
//	srand(time(0));	
//	vector* v = getNewVector(MAX_OP);
//	int pos, op, val;
//	for (int i = 0; i < MAX_OP; ++i) {
//		op = rand() % 4;
//		switch(op) {
//		case 0:
//		case 1:
//		case 2: // insert
//			pos = rand() % (v -> count + 3); 
//			val = rand() % 100;
//			printf(TC_GRN "insert" TC_END" %d at %d = %s \n", val, pos, B(insert(v, pos, val)));
//			break;
//		case 3: // erase
//			pos = rand() % (v -> count + 3);
//			printf(TC_YLW "erase" TC_END" item at %d = %s\n", pos, B(erase(v, pos)));
//			break;
//		}
//		outputVector(v, MAX_OP);
//	}
//	return 0;
//}




