#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>      
#include <algorithm>   
using namespace std;

class Img{//图像类
public :
       int w,h;
       vector<vector<int>> Tu;

       void Read(const string& filename){
          ifstream file(filename);
          if(!file.is_open()){
            cerr<<"GG!"<<endl;
            return;
          }
   

        Tu.clear();
        string line;

        while (getline(file,line)){
         vector<int> row;
            int num;
            istringstream iss(line);
            while (iss >> num) {
                row.push_back(num);
            }
            Tu.push_back(row);
       }

       h=Tu.size();
       w=(h>0)?Tu[0].size():0;//检查 h 是否大于 0

       file.close();
    }   


    void Display() const {
    for(const auto& row:Tu){
        for(int num:row){
            cout<<num<<" ";
        }
        cout<<endl;
    }

  }



  void Judgeout(int thr){
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            if (Tu[i][j]<=thr){
                Tu[i][j]=0;
                if(Tu[i][j]==0){
                  cout<<".";
                }else{
                  cout<<"0";
                }
                cout<<endl;
            }
        }
    }
  }


  
};


int main(){
    Img T;
    T.Read("/home/ak/VSproject/src/R.txt") ;
    T.Judgeout(100);
    T.Display();
    return 0;
}


