
#include "StringUtilize.h"
using namespace std;


int StringUtilizes::matrix[N][N] = {0};

bool StringUtilizes::StringTrim(string &s){
	size_t left = 0;
	size_t right = s.length()-1;
	while((s[left] == ' ' || s[left] == '\r' || s[left] == '\n' ) && left < s.length())
    {
        left++;
    }
    while((s[right] == ' '|| s[right] == '\r' || s[right] == '\n' ) && right >= 0)
    {
        right--;
    }
    if(left > right)
    {
        s = "";
        return true;
    }
	return true;
}
bool StringUtilizes::StringSplit(std::vector<std::string>& parts, std::string &str, const char* splitChars)
{
	parts.clear();
	int split_len = strlen(splitChars);
	size_t last_pos = 0;
	size_t pos = str.find(splitChars,last_pos);

	while( pos != string::npos)
	{
		if(pos != last_pos)
		{
			//cout<<str.substr(last_pos,pos-last_pos)<<endl;
			parts.push_back(str.substr(last_pos,pos-last_pos));
		}
		last_pos = pos + split_len;
		//cout<<last_pos<<endl;
		pos = str.find(splitChars,last_pos);
	}

	//process the last part
	if(last_pos + split_len < str.length())
	{
		parts.push_back(str.substr(last_pos,str.length()-last_pos));
	}
	return true;
}

int StringUtilizes::GetMaxofTwo(int m, int n)
{
	return m>n?m:n;
}

int StringUtilizes::GetMinofTwo(int m,int n)
{
	return m<n?m:n;
}
int StringUtilizes::GetMinOfThree(int m, int n, int k)
{
	int min = GetMinofTwo(m,n);
	return k<min?k:min;
}

int StringUtilizes::GetEditDis(string leftStr, string rightStr)
{
	int i = 0 , j = 0;
		
	for(i = 0; i < rightStr.length()+1; i++)
	{
		matrix[0][i] = i;
	}
	for( i = 0; i < leftStr.length()+1; i++)
	{
		matrix[i][0] = i;
	}
	for(i =1 ; i <= leftStr.length(); i ++)
	{
		for(j = 1; j <= rightStr.length(); j++)
		{
			if( leftStr[i-1] == rightStr[j-1] )
			{
				matrix[i][j] = matrix[i-1][j-1];
			}
			else
			{
				matrix[i][j] = GetMinOfThree(matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]) + 1;
			}
		}
	}
	return matrix[leftStr.length()][rightStr.length()];
}

string StringUtilizes::GetMaxCommonPrefix(string leftStr, string rightStr)
{

}