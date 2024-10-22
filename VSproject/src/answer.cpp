#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>      
#include <algorithm>    


using namespace std;

class ImageMatrix {
public:
    int width, height;
    vector<vector<int>> matrix;

    // 从文件读取图像
    void readFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "无法打开文件！" << endl;
            return;
        }
        matrix.clear();
        string line;
        while (getline(file, line)) {
            vector<int> row;
            int num;
            istringstream iss(line);
            while (iss >> num) {
                row.push_back(num);
            }
            matrix.push_back(row);
        }
        height = matrix.size();
        width = height > 0 ? matrix[0].size() : 0;
        file.close();
    }

    // 阈值化处理
    void threshold(int thr) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (matrix[i][j] <= thr) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // 二值化显示
    void binaryDisplay() const {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (matrix[i][j] == 0) {
                    cout << '.';
                } else {
                    cout << 'O';
                }
            }
            cout << endl;
        }
    }

    // 左右翻转
    void flipHorizontal() {
        for (int i = 0; i < height; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    // 顺时针旋转90度
    void rotate90Clockwise() {
        vector<vector<int>> rotated(width, vector<int>(height));
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                rotated[j][height - 1 - i] = matrix[i][j];
            }
        }
        matrix = rotated;
        swap(width, height);
    }
};

int main() {
    ImageMatrix img;
    
    // 从TXT文件读取图像
    img.readFromFile("/home/ak/VSproject/src/R.txt");
    
    // 阈值化处理，假设阈值为100
    img.threshold(100);
    
    // 顺时针旋转90度
    img.rotate90Clockwise();

    // 左右翻转
    img.flipHorizontal();
    
    // 二值化显示
    img.binaryDisplay();

    return 0;
}
