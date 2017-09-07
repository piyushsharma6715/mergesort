#include<iostream>
#include<stdio.h>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
void merge(int arr[][2],int l,int m,int r){
	ofstream a ("asc_merge.txt");
	ofstream b("desc_merge.txt");
	int i,j,k,key,key1;
	int n1 = m - l + 1;
    int n2 =  r - m;
    
    int L[n1][2], R[n2][2];
    
	for (i = 0; i < n1; i++){
		L[i][0] = arr[l + i][0];
		L[i][1] = arr[l+i][1];
//		cout<<L[i][0]<<"\n";
	}
        
    for (j = 0; j < n2; j++){
    	R[j][0] = arr[m + 1+ j][0];
		R[j][1] = arr[m+1+j][1];
//		cout<<R[i][0]<<"\n";
	}
        
        
     i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i][0] <= R[j][0])
        {
        	cout<<L[i][0]<<" "<<R[j][0]<<"\n";
            arr[k][0] = L[i][0];
            arr[k][1]=L[i][1];
            i++;
        }
        else
        {
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k][0] = L[i][0];
        arr[k][1] = L[i][1];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k][0] = R[j][0];
        arr[k][1] = R[j][1];
        j++;
        k++;
    }
	
	for(int i=0;i<k;i++){
		a<<arr[i][0]<<"\n";
	}
	a.close();
	for(int i=k-1;i>=0;i--){
		b<<arr[i][0]<<"\n";
	}
	b.close();
	
	
	ofstream c("priority_merge.txt");
	i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i][1] <= R[j][1])
        {
        	arr[k][0] = L[i][0];
            arr[k][1]=L[i][1];
            i++;
        }
        else
        {
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k][0] = L[i][0];
        arr[k][1] = L[i][1];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k][0] = R[j][0];
        arr[k][1] = R[j][1];
        j++;
        k++;
    }



	for(int i=0;i<k;i++){
		c<<arr[i][0]<<"\n";
	}
	c.close();
}
void mergeSort(int arr[][2], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = (l+r)/2;
 
        // Sort first and second halves
  //      cout<<"call 1"<<"\n";
        mergeSort(arr, l, m);
    //    cout<<"call 2"<<"\n";
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
int main(){
	std::ifstream fp ("num.txt");
	std::string s;
	int A[100][2];
	int t=0;
	while(std::getline(fp,s)){
		std::istringstream l(s);     //convert string to int 
		if(!(l>>A[t][0]>>A[t][1])){
			break;
		}
	t++;	
	}
	mergeSort(A,0,t);	
	return 0;
}
