

#include<string>
#include<vector>

#define N 100
class StringUtilizes {
public:
	static int matrix[N][N];
public:
	static bool StringTrim(std::string &s);
	static bool StringSplit(std::vector<std::string>& parts, std::string &str, const char* splitChars);

	static inline int GetMaxofTwo(int m, int n);
	static inline int GetMinofTwo(int m,int n);
	static inline int GetMinOfThree(int m, int n, int k);

	static int GetEditDis(std::string leftStr, std::string rightStr);
	static std::string GetMaxCommonPrefix(std::string leftStr,std::string rightStr);
};