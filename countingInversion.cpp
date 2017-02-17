//IT IS AN ALGOTITHM DESIGNED TO COUNT THE NO. OF INVERSIONS i.e. a[i]>a[j] SUCH THAT i<j WHERE i,j ARE INDICES AND a IS THE ARRAY
//THIS ALGORITHM ACTUALLY MAKES THE USE OF THE MERGESORT ALGORITHM
//THUS IT EVEN HAS A TIME COMPLEXITY OF O(n*lg n)
//THIS ALGOTITHM IS ACTUALLY USED IN FINDING CROSSOVERS IN THOUGHTS OF HUMANS(IF WE SEE THIS EXTENSIVELY)
#include<iostream>
using namespace std;
#define SIZE 100
int arr[SIZE];
int inv=0;
int merge(int l,int m,int u)//THE lower bound,mid position and upper bound are received
{
	int i,j,k;
	int n1=m-l+1;//SIZE OF 1ST ARRAY
	int n2=u-m;//SIZE OF 2ND ARRAY
	int a[n1],b[n2];
	//THE ELEMENT ON EITHER SIDES OF MID ARE PARTITIONED BETWEEN THE TWO ARRAY
	for(i=0;i<n1;i++)
	a[i]=arr[l+i];
	for(j=0;j<n2;j++)
	b[j]=arr[m+1+j];
	i=0;
	j=0;
	//THE MERGING OF ELEMENTS ACCORDING TO THE COMPARISONS TAKE PLACE
	for(k=l;i<n1 && j<n2;k++)
	{
		if(a[i]<=b[j])
		arr[k]=a[i++];
		else
		{
			arr[k]=b[j++];
			inv=inv+(n1-i);//THIS COUNTS THE NO. OF ELEMENTS LEFT IN a[] WHENEVER AN ELEMENT FROM b[] IS MERGED
		}
	}
	//THE REMAINING ELEMENTS IN a[] and b[] ARE PUSHED INTO RESULTANT ACCORDINGLY
	while(i<n1)
	arr[k++]=a[i++];
	while(j<n2)
	arr[k++]=b[j++];
	return 0;
}
//THE RECURSIVE FUNCTION TO DIVIDE THE ARRAY INTO SUBARRAYS
int countInversion(int l,int u)
{
	int m;
	if(l<u)
	{
		m=l+(u-l)/2;
		countInversion(l,m);
		countInversion(m+1,u);
		merge(l,m,u);
	}
	return 0;
}
//main FUNCTION TO SEND THE SIZE OF ARRAY AND PRINT THE NO. OF INVERSIONS
int main()
{
	int n,i;
	cout<<"Enter the no. of elements of the array:";
	cin>>n;
	cout<<"Enter the elements:"<<"\n";
	for(i=0;i<n;i++)
	cin>>arr[i];
	countInversion(0,n-1);
	cout<<"The number of inversions present is "<<inv<<"\n.";
	return 0;
}
//END OF PROGRAM
