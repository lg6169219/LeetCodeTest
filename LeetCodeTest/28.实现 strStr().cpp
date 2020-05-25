#include <iostream>
#include <vector>
#include <string>
/**
ʵ�� strStr() ������

����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻�  -1��

ʾ�� 1:

����: haystack = "hello", needle = "ll"
���: 2
ʾ�� 2:

����: haystack = "aaaaa", needle = "bba"
���: -1
˵��:

�� needle �ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�����һ���������кܺõ����⡣

���ڱ�����ԣ��� needle �ǿ��ַ���ʱ����Ӧ������ 0 ������C���Ե� strstr() �Լ� Java�� indexOf() ���������
*/
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle == "")
		{
			return 0;
		}

		char str = needle[0];
		int index = -1;
		int sameNum = 0;

		int length1 = haystack.length();
		int length2 = needle.length();
		for (int j = 0; j < length1 - length2 + 1; ++j)
		{
			if (str == haystack[j]) // �ҵ���ͷ����ļ� ��ɨһ��needle�����ǲ���ȫ��
			{
				sameNum = 0;
				++sameNum;
				for (int i = 1; i < length2; ++i)
				{
					if (haystack[j + i] == needle[i]){
						++sameNum;
					}else{
						break;
					}
				}
				// ɨ��Ƚ�һ��
				if (sameNum == length2){
					index = j;
					break;
				}
			}
		}
		return index;
	}
};