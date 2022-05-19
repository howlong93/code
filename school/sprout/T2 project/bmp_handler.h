#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void word_picture(char*);
void color (char*);
void edge_detect(char*);
void gray_spaces(char*);
void video(int);
void CleanScreen();

typedef struct FileHeader{
	uint32_t filesize; 
	uint32_t reserved;
	uint32_t data_offset;
}  __attribute__ ((packed)) FileHeader;

typedef struct BMPHeader{
	uint32_t headersize;
	int32_t width;
	int32_t height;
	int16_t planes;
	int16_t colors;
	int32_t compression;
	uint32_t datasize;
	uint32_t h_resolution;
	uint32_t v_resolution;
	uint32_t palette_colors;
	uint32_t important_colors;
} __attribute__ ((packed)) BMPHeader;

typedef vector<int> V1d;
typedef vector<V1d> V2d;
typedef vector<V2d> V3d;

struct BMP {
	char fileID[2];
	FileHeader fileHeader;
	BMPHeader bmpHeader;
	V3d bitmap;
	public:
	BMP(int width, int height){
		unsigned datasize = bmpDataSize(width, height);
		fileHeader = FileHeader{0, datasize+54, 54U};
		bmpHeader = BMPHeader{ 40, width, height, 1, 24, 0, datasize, 0, 0, 0, 0};
		bitmap = V3d(height, V2d(width, V1d(3, 0)));
	}
	BMP(string fn){
		read(fn);
	}
	bool read(string fn){
		std::fstream fin(fn, std::ios::in|std::ios::binary);
		// check file status
		if (!fin.good()) {
			std::cerr << "Can not open file \"" << fn << "\" for reading.\n";
			std::cerr << "Abort.\n";
			return 0;
		}
		// read file type
		fin.read(fileID, 2);
		if(fileID[0] != 'B' || fileID[1] != 'M') {
			std::cerr << "File type of \"" << fn << "\" is not BMP.\n";
			std::cerr << "Abort.\n";
			return 0;
		}
		// read file header
		fin.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
		if(fileHeader.filesize > 100 * 1024 * 1024) {
			std::cerr << "File size greater than 100MB is too big.\n";
			std::cerr << "Abort.\n";
			return 0;
		}
		// read bmp header
		fin.read(reinterpret_cast<char*>(&bmpHeader), sizeof(bmpHeader));
		if(bmpHeader.planes != 1) 
			std::cerr << "Planes not equal to 1, file might be corrupted. Continuing...\n";
		if(bmpHeader.colors != 24){
			std::cerr << "Color encoding \'" << bmpHeader.colors << "\' is not suppported,";
			std::cerr << "we only support 24 bit color encoding.\n";
			std::cerr << "Abort.\n";
			return 0;
		}
		if(bmpHeader.compression != 0)
			std::cerr << "Compression is not suppported for 24 bit color encoding. Continuing...\n";

		// read data into buffer
		unsigned char buffer[height()][alignWidth()];
		fin.seekg(fileHeader.data_offset);
		fin.read(reinterpret_cast<char*>(buffer), bmpDataSize(width(), height()));

		// get buffer into bit map
		bitmap.clear();
		for(int i=0; i<height(); i++){
			V2d row;
			for(int j=0; j<width(); j++)
				row.emplace_back(&buffer[i][j*3], &buffer[i][j*3]+3);
			bitmap.push_back(row);
		}
		// scanning line from bottom if height > 0
		if(bmpHeader.height > 0)
			reverse(bitmap.begin(), bitmap.end());
		return 1;
	}
	bool save(string fn){
		std::fstream fout(fn, std::ios::out|std::ios::binary);
		if (!fout.good()) {
			std::cerr << "Can not open file \"" << fn << "\" for reading.\n";
			std::cerr << "Abort.\n";
			return 0;
		}
		// write header and padding
		fout.write("BM", 2);
		fout.write(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
		fout.write(reinterpret_cast<char*>(&bmpHeader), sizeof(bmpHeader));
		for(unsigned int i=0; i<fileHeader.data_offset - sizeof(fileHeader) - sizeof(bmpHeader) - 2; i++)
			fout.write("\0", 1);

		// get data into buffer
		unsigned char buffer[height()][alignWidth()];
		if(bmpHeader.height > 0)
			reverse(bitmap.begin(), bitmap.end());
		for(int i=0; i<height(); i++)
			for(int j=0; j<width(); j++)
				for(int k=0; k<3; k++)
					buffer[i][j*3+k] = bitmap[i][j][k];
		if(bmpHeader.height > 0)
			reverse(bitmap.begin(), bitmap.end());

		// write out buffer
		fout.write(reinterpret_cast<char*>(buffer), bmpDataSize());
		return 1;
	}
	inline int width(){
		return bmpHeader.width;
	}
	inline int height(){
		return abs(bmpHeader.height);
	}
	inline size_t alignWidth(){
		return ( ( width()*3 + 3 ) / 4 ) * 4;
	}
	inline size_t bmpDataSize(uint32_t _width = 0, uint32_t _height = 0){
		if(_width && _height){
			bmpHeader.width = _width;
			bmpHeader.height = _height;
		}
		return alignWidth() * height();
	}
};

