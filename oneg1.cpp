#include<fstream>
#include<vector>
#include <algorithm>
#include<cstring>
#include<cassert>
using std::strlen;
using std::ifstream;
using std::vector;
using std::ios_base;
bool Compare(const char *str1, const char *str2)//компаратор для сортировки
{
	return std::strcmp(str1,str2) < 0;
}


int Size(ifstream& in)
{
	
	in.seekg(0,ios_base::end);
	int n=in.tellg();
	in.seekg(0, ios_base::beg);
	return n;
}


char* ReadFile(const char* file)
{
	ifstream in(file);
	int n = Size(in);
	char* str = new char[n+1];
	in.read(str, n);
	in.close();
	return str;
}


vector<char*> Parse (char* str)
{
	int n=strlen(str);
	vector<char*> stro;
        stro.push_back(str);
	for(int i=0;i<n-1;i++)
        {
                if (str[i] == '\n')
                {
                        str[i] = '\0';
                        i++;
                        if(i < n-1)
                                stro.push_back(str+i);
                }
        }
	return stro;
}

int main()
{
	
        char* str = ReadFile("/home/alex/Рабочий стол/avidreaders.ru__evgeniy-onegin.txt");
	int n=strlen(str);
	vector<char*> stro=Parse (str);
        str[n] = '\0';
        std::sort(stro.begin(),stro.end(),Compare);
        std::ofstream ofs ("onegin.txt", std::ofstream::out);
        for(int i=0;i<stro.size();i++)
	{
                ofs << stro[i] << std::endl;
        }
        ofs.close();
        delete[] str;
        return 0;
}
