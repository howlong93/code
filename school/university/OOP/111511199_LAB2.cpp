#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

/////////////////////////////////////////////////////////////
////            Function Declartion + Definition             //
///////////////////////////////////////////////////////////////

void parseImage(ifstream& FILEIN, vector<vector<int> >& image){
	int size;
	FILEIN >> size;
	image = vector<vector<int>> (size, vector<int> (size, 0));

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			FILEIN >> image[i][j];
		}
	}
}


void parseImage(vector<vector<int> >& image, int n){
	int temp = 1;
	image = vector<vector<int>> (n, vector<int> (n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			image[i][j] = temp++;
		}
	}
}


void tranposeImage(vector<vector<int> >& image){
	int size = image.size();
	vector<vector<int>> save = vector<vector<int>> (size, vector<int> (size, 0));

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			save[i][j] = image[j][i];
		}
	}
	image = save;
}

void reverseRow(vector<vector<int> >& image){
	int size = image.size();
	vector<vector<int>> save = vector<vector<int>> (size, vector<int> (size, 0));

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			save[i][j] = image[i][size-j-1];
		}
	}
	image = save;
}

void printImage(ofstream& FILEOUT, vector<vector<int> >& image){
	int rowSize = image[0].size();
	for(int i = 0; i < rowSize; i++){
		for(int j = 0; j < rowSize; j++){
			FILEOUT << setw(4) << image[i][j] << " ";
		}
        FILEOUT << endl;
	}
}

/*
void print (vector<vector<int>>& image) {
	for (int i = 0; i < image.size(); i++) {
		for (int j = 0; j < image.size(); j++) {
			cout << image[i][j] << ' ';
		}
		cout << '\n';
	}
	return;
}
*/
	

int main(int argc, char* argv[]){

	ifstream input;
	ofstream output;

	int graph, degree, file = 1;
	vector<vector<int>> image;

	cout << "Is n user defined ? ";
	cin >> graph;
	
	if (graph == 0) {
		input.open(argv[file]);
		parseImage(input, image);
		file++;
	}
	else if (graph == 1) {
		int size = 0;
		cout << "n = ? ";
		cin >> size;
		parseImage(image, size);
	}

	cout << "The rotate degree is : ";
	cin >> degree;

	for (int i = 0; i < degree/90; i++) {
		tranposeImage(image);
	//	print(image);
		reverseRow(image);
	//	print(image);
	}
	output.open(argv[file]);

	printImage(output, image);

	input.close();
	output.close();

	return 0;
}
