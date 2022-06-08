#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>
#include<bits/stdc++.h>
#include <time.h>
using namespace std;
#define MAX 5
int key = 0;
int dem = 0;
vector<vector<int> > matrix(MAX, vector<int>(MAX, 0));
vector<vector<int> > solution(MAX, vector<int>(MAX, 0));
vector<vector<int> > vec(MAX, vector<int>(MAX, 0));
vector<vector<int> > hs(MAX, vector<int>(MAX, 0));
vector<vector<int> > hs1(MAX, vector<int>(MAX, 0));
vector<vector<int> > population(MAX, vector<int>(MAX*MAX, 0));
vector<vector<int> > children(MAX, vector<int>(MAX, 0));
vector<int> fit(100);
int matrix2;
void Input(int n,int m){
	int rac,rac1;
    ifstream filein("solve.txt");
    filein >> rac;
    filein >> rac1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            filein >> matrix[i][j];
        }
    }
    filein.close();
};
void resi(vector<vector<int> > &temp, int a ,int b){
	temp.resize(a);
	for ( int i = 0 ; i < a ; i++ ){
   		temp[i].resize(b);
}
}
int giaiThua(int n)
{
    if (n == 1)
        return 1;
    return n * giaiThua(n - 1);
}
void Output(int n,int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<setw(4)<<left<<matrix[i][j];
        }
        cout<<endl;
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
bool solve(int r, int c,int r1,int c1,vector<int> res = {})
{
	if(abs(r-r1)>0 && c==c1 && solution[r][c] == 0 && matrix[r][c] != 0 && r>=0 && c>=0){
		solution[r][c] = 1;
        res.push_back(matrix[r][c]);
        if(solve(r+1, c,r1,c1,res))
            return 1;
        if(solve(r-1, c,r1,c1,res))
            return 1;
        res.pop_back();
        solution[r][c] = 0;
        return 0;
	}
	if(abs(c-c1)>0 && r==r1 && solution[r][c] == 0 && matrix[r][c] != 0 && r>=0 && c>=0){
		solution[r][c] = 1;
        
        res.push_back(matrix[r][c]);
        
        if(solve(r, c-1,r1,c1,res))
            return 1;
		if(solve(r, c+1,r1,c1,res))
            return 1;
        res.pop_back();
        solution[r][c] = 0;
        return 0;
	}
    if((r==r1) && (c==c1))
    {
        solution[r][c] = 1;
        res.push_back(matrix[r][c]);
		for (int k = 0; k < res.size(); k++){
			dem+=res[k];
}	
	for (int k = 0; k < res.size(); k++){
			cout<<res[k]<<" ";
}
        return 1;
    }
    if(solution[r][c] == 1 ){
    	return 0;
	}
    if((r!=r1 || c!=c1) && solution[r][c] == 0 && matrix[r][c] != 0 && r>=0 && c>=0)
    {
        solution[r][c] = 1;
        res.push_back(matrix[r][c]);
        
		if(solve(r, c-1,r1,c1,res))
            return 1;
		if(solve(r, c+1,r1,c1,res))
            return 1;
        if(solve(r+1, c,r1,c1,res))
            return 1;
        if(solve(r-1, c,r1,c1,res))
            return 1;
        res.pop_back();
        solution[r][c] = 0;
        return 0;
    }
    return 0;
}
void printAllPath(vector<vector<int> > vec,vector<vector<int> > hs,int i, int j,int i1, int j1 ,vector<int> res = {},vector<int> temp = {} )
{
	if (i < 0 || j < 0 || i >= vec.size() ||j >= vec[0].size() || hs[i][j] == 1)
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
		if(sum > matrix2){
			fill(temp.begin(), temp.end(), 0);
			matrix2 = sum;
			temp = res;
		for(int k = 0; k < temp.size(); k++)
			cout << temp[k] << " ";
		cout<<endl;
		cout<<"Tong quang duong la: "<<matrix2;	
	}
	sum = 0;
}	
	hs[i][j] = 1;
	res.push_back(vec[i][j]);
	printAllPath(vec, hs, i, j + 1,i1,j1, res,temp);
	printAllPath(vec, hs, i + 1, j,i1,j1, res,temp);
	printAllPath(vec, hs, i - 1, j,i1,j1, res,temp);
	printAllPath(vec, hs, i, j - 1,i1,j1, res,temp);
	res.pop_back();
	hs[i][j] = 0;
}
bool checkarray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0; j<matrix.size();j++){
            for(int k = 0; k<matrix[0].size();k++){
                if((matrix[j][k] == arr[i] && matrix[j][k+1] == arr[i+1]) || (matrix[j][k] == arr[i] && matrix[j][k-1] == arr[i+1]) 
                || (matrix[j][k] == arr[i] && matrix[j+1][k] == arr[i+1]) || (matrix[j][k] == arr[i] && matrix[j-1][k] == arr[i+1])){
                    continue;
                }
            	else{
                	return 0;
            	}
        	}
    	}
	}
    return 1;
}
vector<int> create_gnome(int x,int y){
	vector<int> p;
    while(true){
        int ran = 1 + rand() % (4 + 1 - 1);
        if(solution[x][y+1] == 1 && solution[x][y-1] == 1 && solution[x+1][y] == 1 && solution[x-1][y] == 1 ){
            break;
        }
        if(ran == 1 && x >= 0 && y >= 0 && solution[x][y] == 0){
            p.push_back(matrix[x][y]);
            solution[x][y] = 1;
            x--;
        }
        else if(ran == 2 && x >= 0 && y >= 0 && solution[x][y] == 0){
            p.push_back(matrix[x][y]);
            solution[x][y] = 1;
            y++;
        }
        else if(ran == 3 && x >= 0 && y >= 0 && solution[x][y] == 0){
            p.push_back(matrix[x][y]);
            solution[x][y] = 1;
            x++;
        }
        else if(ran == 4 && x >= 0 && y >= 0 && solution[x][y] == 0){
            p.push_back(matrix[x][y]);
            solution[x][y] = 1;
            y--;
        }
    }
    return p;
}
void Reproduction(){
    int maxpre,maxaff;
    for(int i=0;i<population.size();i++){
        maxpre = 0;
        for(int j=0;j<population[0].size();j++){
            maxpre+= population[i][j];
        }
        fit[i] = maxpre;
    }
    cout<<"----------Mien nghiem ----------"<<endl;
    for(int i=0;i<population.size();i++){
        for(int j=0;j<population[0].size();j++){
            cout<<setw(4)<<left<<population[i][j];
        }
        cout<<" Fit:"<<fit[i]<<endl;
        if(!checkarray(population[i])){
            for(int key = 0;key <population[0].size();key++){
                population[i][key] = 0;
            }
            i--;
        }
    } 
    cout<<"-----Bat dau chon ra cac nghiem toi uu-----"<<endl;
    for(int i = 0; i<fit.size();i++){
        if( fit[i]<fit[i+1] && population[i].size() > population[i+1].size()){
            for(int j=0;j<population[i].size();j++){
                int a = population[i][j];
                population[i][j] = population[i+1][j];
                population[i+1][j] = a;
        }
    }
        if(fit[i]<fit[i+1] && population[i].size() < population[i+1].size()){
            for(int j=0;j<population[i+1].size();j++){
                int a = population[i][j];
                population[i][j] = population[i+1][j];
                population[i+1][j] = a;
        }
    }
}
}
void Crossover(){
    cout<<"-----Bat dau lai tao-----"<<endl;
    for(int i=0;i<4;i+2){
        for(int j = 0;j<population[i].size()/2;j++){
            int a = population[i][population[i].size()/2+j];
            population[i][population[i].size()/2+j] = population[i+1][population[i].size()/2+j];
            population[i+1][population[i].size()/2+j] = a;
        }
    }
    cout<<"-----So nghiem con sinh ra-----"<<endl;
    for(int i=0;i<population.size();i++){
        for(int j=0;j<population[i].size();j++){
            cout<<setw(4)<<left<<population[i][j];
        }
        cout<<endl;
    }
    
}
void Mutation(int n,int m){
    for(int i=0;i<population.size();i++){
        int ran3 = 0 + rand() % (population[i].size() + 1 - 0);
        if(ran3 > population[i].size()){
            int ran = n/2 + rand() % (n + 1 - n/2);
            int ran1 = m/2 + rand() % (m + 1 - m/2);
            population[i][ran3] = matrix[ran][ran1];
        }
        if(ran3 <= population[i].size()){
            int ran = 0 + rand() % (n/2 + 1 - 0);
            int ran1 = 0 + rand() % (m/2 + 1 - 0);
            population[i][ran3] = matrix[ran][ran1];
        }
    }
    cout<<"-----So nghiem con da duoc dot bien-----"<<endl;
    for(int i=0;i<population.size();i++){
        for(int j=0;j<population[i].size();j++){
            cout<<setw(4)<<left<<population[i][j];
        }
    }
}
int main(){
	int n,m,sum1;
	ifstream filein("solve.txt");
    filein >> n;
    filein >> m;
    filein.close();
    if(n!= MAX && m!= MAX){
    	resi(matrix,n,m);
		resi(solution,n,m);
		resi(hs,n,m);
		resi(hs1,n,m);
		resi(vec,n,m);
		resi(population,n,m*m)
	}
    Input(n,m);
	for ( int i = 0 ; i < n ; i++ ){
   		for( int j = 0 ; j < m ; j++ ){
   			vec[i][j]=matrix[i][j];
	}
}
    Output(n,m);
    int a;
    cout<<"Chon 1 de tim duong di , chon 2 de tim duong di dai nhat, chon 3 de chay thuat toan genetic, chon 4 de thoat:  ";
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
    	printAllPath(vec, hs, s1, s2,d1,d2);
    	cout << "\n";
}
	if(a==3){
		int mn,choice;
	    cout<<"Nhap so phan tu muon tao: ";
	    cin>>mn;
	    vector<int> p;
	    for(int i =0;i<mn;i++){
	        p = create_gnome(0,0);
	        for(int j =0 ; j < p.size(); j++){
	            population[i][j] = p[j];
	        }
	        fill(p.begin(), p.end(), 0);
	        fill(solution[i].begin(), solution[i].end(), 0);
	    }
	    cout<<"Bat dau tim nghiem: "<<endl;
	    cout<<"Nhap 1 de tao ra mot mien nghiem moi, chon 0 de thoat: "<<endl;
	    cin>>choice;
	    while(choice == 1){
	        Reproduction();
	        Crossover();
	        Mutation(n,m);
	        Reproduction();
	        cout<<"Nhap 1 de tao ra mot mien nghiem moi, chon 0 de thoat: "<<endl;
	        cin>>choice;
	    }
}
	if(a==4){
		break;
/*		const clock_t begin_time = clock();

		cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
*/
	}
	cout<<"Chon 1 de tim duong di , chon 2 de tim duong di dai nhat, chon 3 de chay thuat toan genetic, chon 4 de thoat:  ";
    cin>>a;
    if(n!=MAX && m!= MAX){

    	for(int i = 0;i<n;i++){
    		fill(hs[i].begin(), hs[i].end(), 0);
    		fill(hs1[i].begin(), hs1[i].end(), 0);
    		fill(solution[i].begin(), solution[i].end(), 0);
}
}
	else{
		for(int i = 0;i<MAX;i++){
    		fill(hs[i].begin(), hs[i].end(), 0);
    		fill(hs1[i].begin(), hs1[i].end(), 0);
    		fill(solution[i].begin(), solution[i].end(), 0);
	}
}
	key = 0;
	matrix2 = 0;
} while(a!=0);
    return 0;
}
