


#include "gtest/gtest.h"
#include<iostream>
#include<string>
#include<limits.h>
#include"StringUtilize.h"
using namespace std;


TEST(EditDisTest,EQ_TEST)
{
	string x = "adcdz";
	string y = "xyz";
	//cout<<StringUtilizes::GetEditDis(x,y)<<endl;;
	EXPECT_EQ(2,StringUtilizes::GetEditDis(x,y));
}

int main(int argc,char* argv[])
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}