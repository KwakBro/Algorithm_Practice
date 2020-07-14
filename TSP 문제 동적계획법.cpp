#include<stdio.h>
#define MAX 25000000

enum CITIES { 인천, 서울, 강릉, 천안, 청주, 동해, 대전, 울진, 대구, 울산, 광주, 부산 };

int Ways[12][12] = {
	{0,7,MAX,1,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX } , // 인천
	{3,0,5,MAX,8,MAX,MAX,MAX,MAX,MAX,MAX,MAX } ,		// 서울
	{MAX,3,0,MAX,MAX,3,MAX,MAX,MAX,MAX,MAX,MAX } , // 강릉
	{3,MAX,MAX,0,4,MAX,4,MAX,MAX,MAX,MAX,MAX } ,		// 천안
	{MAX,13,MAX,3,0,1,MAX,2,MAX,MAX,MAX,MAX } ,			// 청주
	{MAX,MAX,5,MAX,2,0,MAX,5,MAX,MAX,MAX,MAX } ,		// 동해
	{MAX,MAX,MAX,5,MAX,MAX,0,5,3,MAX,3,MAX } ,				// 대전
	{MAX,MAX,MAX,MAX,2,3,5,0,3,3,MAX,MAX } ,					// 울진
	{MAX,MAX,MAX,MAX,6,MAX,6,MAX,0,2,MAX,1 } ,				// 대구
	{MAX,MAX,MAX,MAX,MAX,MAX,MAX,1,MAX,0,MAX,2 } ,	// 울산
	{MAX,MAX,MAX,MAX,MAX,MAX,3,MAX,6,MAX,0,5 } ,		// 광주
	{MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,3,4,0 }	// 부산
};
int Dist[12][0b1000000000000];
int P[12][0b1000000000000];

void ps(int num_k, int last_pow,int num, int starting) {			//부분집합 만들기

	if (num_k == 0) {
		if (num < 0b111111111111) {
			if (!(num & (0b000000000001 << starting))) {	// starting 비트가 부분집합에 속하지 않는 경우에만 수행... 

				for (int z = 0; z < 12; z++)
					if ((z != starting) && (!(num & (0b000000000001 << z) )) ) {			// z는 시작점 X, 부분집합 X 

						int min_index = 0, min_value = MAX;

						for (int index = 0; index < 12; index++) {
							if ((index != starting) && (num & (0b000000000001 << index))) {		// 최소값 체크를 위한 index는 시작점 X, 부분집합 O
								if (min_value > Ways[z][index] + Dist[index][num - (0b000000000001 << index)]) {
									min_value = Ways[z][index] + Dist[index][num - (0b000000000001 << index)];
									min_index = index;
								}
							}
						}

						Dist[z][num] = min_value;
						P[z][num] = min_index;

						printf(" +++ D[ %02d ][ ",z);
						for (int a = 11; a >= 0; --a) {
							printf("%d ", (num >> a) & 1);
						}
						printf(" ] = %d \n", min_value);

					}
			}
		}
	}
	else {
		if (last_pow <= 11) {
			ps(num_k - 1, last_pow + 1, num + (0b000000000001 << last_pow), starting);
			ps(num_k, last_pow + 1, num, starting);
		}
	}
}

void main() {
	int starting;

	{
		printf("  ================================================================================================== \n");
		printf("  인천 0, 서울 1, 강릉 2, 천안 3 , 청주 4, 동해 5, 대전 6, 울진 7, 대구 8, 울산 9, 광주 10, 부산 11  \n");
		printf("  ================================================================================================== \n");
		printf(" 출발/도착지 : ");
		scanf_s("%d", &starting);
	}
	/// printf 출발/목적지 정의부분

	for (int i = 0; i < 12; i++) {
		if (i != starting) {
			printf(" /// D[ %02d ][ ",i);
			for (int a = 11; a >= 0; --a) {
				printf("%d ", (0 >> a) & 1);
			}
			printf(" ] = %d\n", Ways[i][starting]);
			Dist[i][0] = Ways[i][starting];
		}
	}

	for (int k = 1; k <= 10; k++) {
		printf(" k = %d \n", k);
		ps(k, 0, 0b000000000000, starting);
	}

	int min_index = 0, min_value = MAX;

	for (int index = 0; index < 12; index++) 
		if (index != starting) {
			if (min_value > Ways[starting][index] + Dist[index][0b111111111111 - (0b000000000001 << index) - (0b000000000001 << starting)]) {
				min_value = Ways[starting][index] + Dist[index][0b111111111111 - (0b000000000001 << index) - (0b000000000001 << starting)];
				min_index = index;
			}
		}
	printf("\n\n 최소 값 : %d \n", min_value);

	Dist[starting][0b111111111111 - (0b000000000001 << starting)] = min_value;
	P[starting][0b111111111111 - (0b000000000001 << starting)] = min_index;



	printf(" 최소 루트 : %d -> %d ", starting, min_index);
	int nm = 0b111111111111 - (0b000000000001 << starting) - (0b000000000001 << min_index);
	int n = min_index;

	enum CITIES ct;

	for (int i = 0; i < 10; i++) {
		printf("-> %d ",  P[n][nm]);
		n = P[n][nm];
		nm = nm - (0b000000000001 << n);
	}
	printf("-> %d\n\n", starting);

}

