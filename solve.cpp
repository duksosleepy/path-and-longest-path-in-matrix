#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
#define MAX 5
#define vocung 100001
int key = 0;
int n, p, q;
int dem = 0;
int matrix[MAX][MAX];
int solution[MAX][MAX];
int matrix2[MAX*MAX];

void Input(){
    ifstream filein("Cau12.txt");
    filein >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            filein >> matrix[i][j];
        }
    }
    filein.close();
};

void sortarr(){
	for(int i = 0; i < MAX*MAX; i++){
        for(int j = i + 1; j < MAX*MAX; j++){
            if(matrix2[i] < matrix2[j]){
                int tg = matrix2[i];
                matrix2[i] = matrix2[j];
                matrix2[j] = tg;        
            }
        }
    }
}
void Output(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout<<setw(4)<<left<<matrix[i][j];
        }
        cout<<endl;
    }
}
void printsolution(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout<<setw(4)<<left<<solution[i][j];
        }
        cout << endl;
    }
}

int max(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (max < a[i])
            max = a[i];
    return max;
}
int sum_array_elements( int arr[] ) {
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum;
   	for(int i = 0; i<n ; i++){
       sum+=arr[i];
   	}
   	return sum;
}
int solve(int r, int c,int r1,int c1)
{
	if(abs(r-r1)==1 && c==c1 && r>=0){
		solution[r][c] = 1;
        
        cout<<matrix[r][c]<<" ";
		
		dem+=matrix[r][c];
		if(solve(r+1, c,r1,c1))
            return 1;
        if(solve(r-1, c,r1,c1) && r>=0)
            return 1;
        solution[r][c] = 0;
}

    else if(abs(c-c1)==1 && r==r1 && c>=0){
		solution[r][c] = 1;
        
        cout<<matrix[r][c]<<" ";
		
		dem+=matrix[r][c];
    	if(solve(r, c-1,r1,c1) && c>=0)
            return 1;
		if(solve(r, c+1,r1,c1))
            return 1;
        solution[r][c] = 0;
}
    if((r==r1) && (c==c1))
    {
        solution[r][c] = 1;
        dem+=matrix[r][c];
        cout<<matrix[r][c]<<" ";
        return 1;
    }
    if((r!=r1 || c!=c1) && solution[r][c] == 0 && matrix[r][c] != 0 && r>=0 && c>=0)
    {
        solution[r][c] = 1;
        
        cout<<matrix[r][c]<<" ";
		
		dem+=matrix[r][c];
		if(solve(r, c-1,r1,c1))
            return 1;
		if(solve(r, c+1,r1,c1))
            return 1;
        if(solve(r+1, c,r1,c1))
            return 1;
        if(solve(r-1, c,r1,c1))
            return 1;
        
        solution[r][c] = 0;
        return 0;
    }
    return 0;
}

void printAllPath(vector<vector<int> > vec,vector<vector<int> > hash,int i, int j,int i1, int j1 ,vector<int> res = {} )
{
	if (i < 0 || j < 0 || i >= vec.size() ||j >= vec[0].size() || hash[i][j] == 1)
		return ;

	if (i == i1 && j == j1) {

		res.push_back(vec[i][j]);
		if(count(res.begin(), res.end(), 0)){
			return;
		}
		int sum;
		for (int k = 0; k < res.size(); k++){
			sum+=res[k];
}		
		matrix2[key++]=sum;
		cout << "\n";
		return;
	}

	hash[i][j] = 1;

	res.push_back(vec[i][j]);

	printAllPath(vec, hash, i, j + 1,i1,j1, res);

	printAllPath(vec, hash, i + 1, j,i1,j1, res);

	printAllPath(vec, hash, i - 1, j,i1,j1, res);

	printAllPath(vec, hash, i, j - 1,i1,j1, res);

	res.pop_back();

	hash[i][j] = 0;
}

void printAllPath2(vector<vector<int> > vec,vector<vector<int> > hash1, int i, int j,int i1, int j1 ,vector<int> res1 = {}  )
{

	if (i < 0 || j < 0 || i >= vec.size() ||j >= vec[0].size() || hash1[i][j] == 1)
		return ;

	if (i == i1 && j == j1) {
		
		res1.push_back(vec[i][j]);
		
		if(count(res1.begin(), res1.end(), 0)){
			return;
		}
		
		int sum;
		for (int k = 0; k < res1.size(); k++){
			sum+=res1[k];
}		
		if(sum == matrix2[0]){
			for(int k = 0; k < res1.size(); k++)
				cout << res1[k] << " ";
	}
		cout << "\n";
		return;
}
	hash1[i][j] = 1;

	res1.push_back(vec[i][j]);

	printAllPath2(vec, hash1, i, j + 1,i1,j1, res1);

	printAllPath2(vec, hash1, i + 1, j,i1,j1, res1);

	printAllPath2(vec, hash1, i - 1, j,i1,j1, res1);

	printAllPath2(vec, hash1, i, j - 1,i1,j1, res1);

	res1.pop_back();

	hash1[i][j] = 0;

}

int main(){
	int sum1;
    Input();
	vector<vector<int> > vec(n);
	for ( int i = 0 ; i < n ; i++ )
   		vec[i].resize(n);
	vector<vector<int> > hash(MAX, vector<int>(MAX, 0));
	vector<vector<int> > hash1(MAX, vector<int>(MAX, 0));
	for ( int i = 0 ; i < n ; i++ )
   		for( int j = 0 ; j < n ; j++ )
   			vec[i][j]=matrix[i][j];
   	for ( int i = 0 ; i < n ; i++ )
   		for( int j = 0 ; j < n ; j++ )
   			sum1+=matrix[i][j];
	
    Output();
    int a;
    cout<<"Chon 1 de tim duong di , chon 2 de tim duong di dai nhat, chon 3 de exit:  ";
    cin>>a;
    do
	{
	if(a==1){
		dem=0;
		cout << "\nChon dinh muon xuat phat:";
    	int s1,s2,d1,d2;
    	cin>>s1>>s2;
    	cin.ignore();
    	cout << "\nChon dinh muon den:";
    	cin>>d1>>d2;
    	cout<<"QUANG DUONG CO THE DI LA: ";
    	if(solve(s1,s2,d1,d2))
       		cout<<"";
    	else{
        	cout<<"No solution\n";
}
        cout<<endl;
        cout<<"Tong quang duong la: "<<dem<<endl;
	}
	if(a==2){
		cout << "\nChon dinh muon xuat phat:";
    	int s1,s2,d1,d2;
    	cin>>s1>>s2;
    	cin.ignore();
    	cout << "\nChon dinh muon den:";
    	cin>>d1>>d2;
    	printAllPath(vec, hash, s1, s2,d1,d2);
    	sortarr();
    	cout<<"QUANG DUONG DAI NHAT LA: ";
    	printAllPath2(vec, hash1, s1, s2,d1,d2);
    	cout<<"Tong quang duong: "<<matrix2[0]<<endl;

}
	if(a==3){
		break;
}
	
	cout<<"Chon 1 de tim duong di , chon 2 de tim duong di dai nhat, chon 3 de exit:  ";
    cin>>a;
} while(a!=0);
    return 0;
}
