#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <map>
#include <vector>
#include <fstream>

//文件管理类
class FileManager
{
public:

    //加载CSV格式文件
    void loadCSVData(string path, map<string, map<string, string>>& m);

    //解析单行数据到vector容器中
    void parseLineToVector(string line, vector<string>& v);
};