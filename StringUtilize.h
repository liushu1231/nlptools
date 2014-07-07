

#include<string>
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

class StringUtilizes {
public:
	static void StringTrim(string &s){
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
        	return;
        }
	}
	static void StringSplit(vector<string>& parts, string &str, const char* splitChars)
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
	}

};