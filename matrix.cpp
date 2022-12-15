#include<iostream>
#include<vector>
using namespace std;
class Matrix{
        int n_,m_;
        vector<vector<int>> matrix;
        public:
        Matrix(int a,int b){
                n_=a,m_=b;
                for(int i=0;i<a;i++){
                        vector<int>line;
                        for(int j=0;j<b;j++){
                                int num;
                                cin>>num;
                                line.push_back(num);
                        }
                        matrix.push_back(line);
                }
                cout<<"您有了一个矩阵"<<endl;
        }

        int get_r(){return n_;}
        int get_l(){return m_;}
        vector<vector<int>> get_matrix(){return matrix;}
        int each_line(int k,int pos){
                vector<vector<int>>::iterator it=matrix.begin()+k;
                vector<int>::iterator line_it=(*it).begin()+pos;
                return *line_it;
        }
};
vector<vector<int>> to_multiple(Matrix& a,Matrix& b){
        int n_a=a.get_r(),m_a=a.get_l();
        int n_b=b.get_r(),m_b=b.get_l();
        Matrix a1=a,b1=b;
        vector<vector<int>> outcome;
        if(m_a!=n_b)
        throw runtime_error("矩阵相乘需要满足左矩阵的列数等于右矩阵的行数\n");
        else{
                for(int i=0;i<n_a;i++){
                        vector<vector<int>>::iterator line_it=outcome.begin()+i;
                        for(int j=0;j<m_b;j++){
                                vector<int>::iterator pos_it=(*line_it).begin()+j;
                                int sum=0;
                                for(int i1=0,j1=0;i1<n_b,j1<m_a;i1++,j1++){
                                        sum+=a.each_line(i,i1)*b.each_line(j1,j);
                                }
                                *pos_it=sum;
                        }
                }
        }
        return outcome;
}
int main(){
        int n1,n2;
        int m1,m2;
        cout<<"请输入你要创造的矩阵的行列参数："<<endl;
        cin>>n1>>n2>>m1>>m2;
        cout<<"请创造第一个矩阵"<<endl;
        Matrix a(n1,n2);
        cout<<"请创造第二个矩阵"<<endl;
        Matrix b(m1,m2);
        vector<vector<int>> out=to_multiple(a,b);
        cout<<"这就是相乘结果"<<endl;
        for(int i=0;i<n1;i++){
                for(int j=0;j<m2;j++){
                        cout<<out[i][j]<<" ";
                }
                cout<<endl;
        }
}