/*Chris Paldino
I pledge my honor that I have abided by the Stevens Honor System*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int main(int argc, char **argv){
	if (argc != 4)
		{fprintf(stderr,"Wrong number of command-line arguments\n");
		return -1;}
	int M=atoi(argv[1]);//height of matrix
  int N=atoi(argv[2]);//width of matrix
	int B=atoi(argv[3]);//width of block
	float *A,*T;
	A=(float*) malloc((N*M)*sizeof(float));
	T=(float*) malloc((N*M)*sizeof(float));
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			A[i*N+j]=(float)rand()/RAND_MAX;}}
	struct timeval tvstart,tvend;
	gettimeofday(&tvstart,NULL);
	for(int i=0;i<M;i+=B){
		for(int j=0;j<N;j+=B){
			for(int k=i;k<i+B;k++){
				for(int l=j;l<j+B;l++){
          if(k>M-1 || l>N-1){continue;}
					else{T[l*M+k]=A[k*N+l];}}}}}
	gettimeofday(&tvend,NULL);
	/*PRINTER
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			printf("%.2f\t",A[i*N+j]);}
		printf("\n");}
	printf("\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			printf("%.2f\t",T[i*M+j]);}
		printf("\n");}*/
	printf("Transposition time: %ld microseconds\n",
		((tvend.tv_sec-tvstart.tv_sec)*1000000)+
		(tvend.tv_usec-tvstart.tv_usec));
	free(A);
	free(T);
	return 0;}
